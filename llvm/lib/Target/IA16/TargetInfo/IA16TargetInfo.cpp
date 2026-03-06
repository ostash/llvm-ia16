//===-- IA16TargetInfo.cpp - IA16 Target Implementation -------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "llvm/MC/TargetRegistry.h"
#include "llvm/TargetParser/Triple.h"

using namespace llvm;

namespace llvm {
Target &getTheIA16Target() {
  static Target TheIA16Target;
  return TheIA16Target;
}
} // namespace llvm

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeIA16TargetInfo() {
  RegisterTarget<Triple::ia16> X(getTheIA16Target(), "ia16", "IA-16", "IA16");
}
