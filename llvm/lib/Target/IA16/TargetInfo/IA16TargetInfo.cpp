//===-- IA16TargetInfo.cpp - IA16 Target Implementation -------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#include "TargetInfo/IA16TargetInfo.h"

#include "llvm/MC/TargetRegistry.h"
#include "llvm/TargetParser/Triple.h"

namespace llvm {

Target &getTheIA16Target() {
  static Target TheIA16Target;
  return TheIA16Target;
}

} // namespace llvm

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeIA16TargetInfo() {
  llvm::RegisterTarget<llvm::Triple::ia16, /*HasJIT=*/false> X(
      llvm::getTheIA16Target(), "ia16", "Intel 16-bit x86", "IA16");
}
