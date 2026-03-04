//===- IA16TargetMachine.cpp - Define TargetMachine for IA16 ----*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#include "IA16TargetMachine.h"
#include "TargetInfo/IA16TargetInfo.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/IR/Instructions.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/CodeGen.h"

#include <memory>

namespace llvm {

namespace {
class IA16TargetPassConfig : public TargetPassConfig {
public:
  IA16TargetPassConfig(TargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  bool addInstSelector() final {
    // addPass(createARCISelDag(getARCTargetMachine(), getOptLevel()));
    // addPass(FCmpInst())
    return false;
  }
};
} // namespace

IA16TargetMachine::IA16TargetMachine(const Target &T, const Triple &TT,
                                     StringRef CPU, StringRef FS,
                                     const TargetOptions &Options,
                                     std::optional<Reloc::Model> RM,
                                     std::optional<CodeModel::Model> CM,
                                     CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T,
                               ""
                               "",
                               TT, CPU, FS, Options, RM.value_or(Reloc::Static),
                               CM.value_or(CodeModel::Tiny), OL),
      // FIXME: OMF?
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()) {
  initAsmInfo();
}

IA16TargetMachine::~IA16TargetMachine() = default;

TargetPassConfig *IA16TargetMachine::createPassConfig(PassManagerBase &PM) {
  return new IA16TargetPassConfig(*this, PM);
}

} // namespace llvm

// Force static initialization.
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeIA16Target() {
  llvm::RegisterTargetMachine<llvm::IA16TargetMachine> X(
      llvm::getTheIA16Target());
}
