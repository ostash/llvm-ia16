//===- IA16TargetMachine.h - Define TargetMachine for IA16 ------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#ifndef LLVM_LIB_TARGET_IA16_IA16TARGETMACHINE_H
#define LLVM_LIB_TARGET_IA16_IA16TARGETMACHINE_H

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"

namespace llvm {

class IA16TargetMachine final : public CodeGenTargetMachineImpl {
public:
  IA16TargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                    StringRef FS, const TargetOptions &Options,
                    std::optional<Reloc::Model> RM,
                    std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                    bool JIT);
  ~IA16TargetMachine() final;

  TargetPassConfig * createPassConfig(PassManagerBase &PM) final;
  TargetLoweringObjectFile *getObjFileLowering() const final {
    return TLOF.get();
  }

private:
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_IA16_IA16TARGETMACHINE_H
