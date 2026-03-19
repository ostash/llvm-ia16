//===-- IA16FrameLowering.cpp - IA16 Frame Information ------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the IA16 implementation of TargetFrameLowering class.
//
//===----------------------------------------------------------------------===//
#include "IA16FrameLowering.h"

#if 0
#include "llvm/CodeGen/MachineFunction.h"

using namespace llvm;
#endif

namespace llvm {

// TODO: implement those functions

void IA16FrameLowering::emitPrologue(MachineFunction &MF,
                                     MachineBasicBlock &MBB) const {}

void IA16FrameLowering::emitEpilogue(MachineFunction &MF,
                                     MachineBasicBlock &MBB) const {}

bool IA16FrameLowering::hasFPImpl(const MachineFunction &MF) const {
  return false;
}

}