//===-- IA16.h - Top-level interface for IA16 representation ----*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the entry points for global functions defined in the LLVM
// IA16 back-end.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_IA16_IA16_H
#define LLVM_LIB_TARGET_IA16_IA16_H

#include "llvm/Support/CodeGen.h"

namespace llvm {
class IA16TargetMachine;
class FunctionPass;
class PassRegistry;

FunctionPass *createIA16ISelDag(IA16TargetMachine &TM,
                                CodeGenOptLevel OptLevel);

void initializeIA16DAGToDAGISelLegacyPass(PassRegistry &);

} // namespace llvm

#endif
