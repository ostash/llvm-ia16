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
#include "IA16.h"
#include "IA16MachineFunctionInfo.h"
#include "TargetInfo/IA16TargetInfo.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeIA16Target() {
  RegisterTargetMachine<IA16TargetMachine> X(getTheIA16Target());
}

static std::string computeDataLayout(const Triple &TT) {
  // 16-bit pointers, 16-bit registers, 16-bit integers, 8-bit bytes
  return "e-m:e-p:16:16-i16:16-a:0:16-n16-S16";
}

static Reloc::Model getEffectiveRelocModel(std::optional<Reloc::Model> RM) {
  return RM.value_or(Reloc::Static);
}

IA16TargetMachine::IA16TargetMachine(const Target &T, const Triple &TT,
                                     StringRef CPU, StringRef FS,
                                     const TargetOptions &Options,
                                     std::optional<Reloc::Model> RM,
                                     std::optional<CodeModel::Model> CM,
                                     CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, computeDataLayout(TT), TT, CPU, FS, Options,
                               getEffectiveRelocModel(RM),
                               getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()),
      Subtarget(TT, std::string(CPU), std::string(FS), *this) {
  initAsmInfo();
}

MachineFunctionInfo *IA16TargetMachine::createMachineFunctionInfo(
    BumpPtrAllocator &Allocator, const Function &F,
    const TargetSubtargetInfo *STI) const {
  return new (Allocator) IA16MachineFunctionInfo(F, STI);
}

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
} // namespace

TargetPassConfig *IA16TargetMachine::createPassConfig(PassManagerBase &PM) {
  return new IA16PassConfig(*this, PM);
}

bool IA16PassConfig::addInstSelector() {
  addPass(createIA16ISelDag(getIA16TargetMachine(), getOptLevel()));
  return false;
}
