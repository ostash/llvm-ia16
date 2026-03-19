//===-- IA16TargetMachine.cpp - Define TargetMachine for IA16 -----------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
//
//===----------------------------------------------------------------------===//

#include "IA16TargetMachine.h"

#include "IA16Subtarget.h"
#include "TargetInfo/IA16TargetInfo.h"

#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"

namespace llvm {

namespace {
class IA16PassConfig : public TargetPassConfig {
public:
  IA16PassConfig(IA16TargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  IA16TargetMachine &getIA16TargetMachine() const {
    return getTM<IA16TargetMachine>();
  }

  bool addInstSelector() override;
};

bool IA16PassConfig::addInstSelector() {
  // addPass(createIA16ISelDag(getIA16TargetMachine(), getOptLevel()));
  return false;
}
} // namespace

static constexpr Reloc::Model getEffectiveRelocModel() {
  // No support for other relocation models for now
  return Reloc::Static;
}

static CodeModel::Model
getEffectiveIA16CodeModel(std::optional<CodeModel::Model> CM) {
  switch (CM.value_or(CodeModel::Small)) {
  case CodeModel::Tiny:
    reportFatalUsageError("IA16 target does not support the tiny code model");
  case CodeModel::Small:
    break;
  case CodeModel::Kernel:
    reportFatalUsageError("IA16 target does not support the kernel code model");
  case CodeModel::Medium:
    reportFatalUsageError("IA16 target does not support the medium code model");
  case CodeModel::Large:
    reportFatalUsageError("IA16 target does not support the large code model");
  }

  return CodeModel::Small;
}

IA16TargetMachine::IA16TargetMachine(const Target &T, const Triple &TT,
                                     StringRef CPU, StringRef FS,
                                     const TargetOptions &Options,
                                     std::optional<Reloc::Model> /* RM */,
                                     std::optional<CodeModel::Model> CM,
                                     CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, TT.computeDataLayout(), TT, CPU, FS, Options,
                               getEffectiveRelocModel(),
                               getEffectiveIA16CodeModel(CM), OL),
      // TODO: custom lowering for OMF
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()) {
  // TODO: probably we will need to do something LargeDataThreshold if other
  // code models are added

  // TODO: will we ever need to set RequireStructuredCFG? Probably not.

  // NOTE: no backends use PGOOption, looks to be used just as a storage only.

  // TODO: there are plenty of options in Options and Options.MCTargetOptions,
  // most probably we will need to adjust some of them.

  // Initialize via TargetRegistry:
  // - MRI: MCRegisterInfo
  // - MII: MCInstrInfo
  // - STI: MCSubtargetInfo
  // - AsmInfo: MCAsmInfo
  initAsmInfo();
}

IA16TargetMachine::~IA16TargetMachine() = default;

const TargetSubtargetInfo *
IA16TargetMachine::getSubtargetImpl(const Function &F) const {
  // NOTE: Subtargets should be created based on attributes set on the function.
  // For now we do not support any, so single subtarget is created.
  if (!Subtarget)
    Subtarget = std::make_unique<IA16Subtarget>(TargetTriple, TargetCPU,
                                                TargetFS, *this);
  return Subtarget.get();
}

TargetLoweringObjectFile *IA16TargetMachine::getObjFileLowering() const {
  return TLOF.get();
}

TargetPassConfig *IA16TargetMachine::createPassConfig(PassManagerBase &PM) {
  return new IA16PassConfig(*this, PM);
}

// MachineFunctionInfo *IA16TargetMachine::createMachineFunctionInfo(
//     BumpPtrAllocator &Allocator, const Function &F,
//     const TargetSubtargetInfo *STI) const {
//   return new (Allocator) MachineFunctionInfo();
//   // return new (Allocator) IA16MachineFunctionInfo(F, STI);
// }

} // namespace llvm

// Force static initialization.
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeIA16Target() {
  llvm::RegisterTargetMachine<llvm::IA16TargetMachine> X(
      llvm::getTheIA16Target());
}