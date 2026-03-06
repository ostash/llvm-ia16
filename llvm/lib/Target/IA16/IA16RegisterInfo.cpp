//===-- IA16RegisterInfo.cpp - IA16 Register Information ------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the IA16 implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#include "IA16RegisterInfo.h"
#include "IA16.h"
#include "IA16FrameLowering.h"
#include "IA16Subtarget.h"
#include "MCTargetDesc/IA16MCTargetDesc.h"
#include "llvm/ADT/BitVector.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"

#define GET_REGINFO_TARGET_DESC
#include "IA16GenRegisterInfo.inc"

using namespace llvm;

IA16RegisterInfo::IA16RegisterInfo() : IA16GenRegisterInfo(0) {}

const MCPhysReg *
IA16RegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  static const MCPhysReg CalleeSavedRegs[] = {0};
  return CalleeSavedRegs;
}

BitVector IA16RegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  BitVector Reserved(getNumRegs());
  return Reserved;
}

bool IA16RegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator MI,
                                           int SPAdj, unsigned FIOperandNum,
                                           RegScavenger *RS) const {
  llvm_unreachable("eliminateFrameIndex not implemented");
  return false;
}

Register IA16RegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  return IA16::AX; // Dummy for now
}
