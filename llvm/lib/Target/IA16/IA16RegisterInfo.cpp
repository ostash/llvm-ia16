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

#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "IA16FrameLowering.h"

#define GET_REGINFO_ENUM
#define GET_REGINFO_TARGET_DESC
#include "IA16GenRegisterInfo.inc"


#if 0
#include "IA16.h"

#include "IA16Subtarget.h"
#include "MCTargetDesc/IA16MCTargetDesc.h"
#include "llvm/ADT/BitVector.h"



using namespace llvm;
#endif

namespace llvm {
// TODO: why 0? What is the meaning of this and other parameters?
IA16RegisterInfo::IA16RegisterInfo() : IA16GenRegisterInfo(0) {}

const MCPhysReg *
IA16RegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  // TODO: This will need to be changed per calling convention
  return CSR_All_SaveList;
}

BitVector IA16RegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  // TODO: None of registers are reserved yet, but this will change 
  BitVector Reserved(getNumRegs());
  return Reserved;
}

bool IA16RegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator MI,
                                           int SPAdj, unsigned FIOperandNum,
                                           RegScavenger *RS) const {
  // TODO: needs SP (and possibly BP) register(s)
  llvm_unreachable("eliminateFrameIndex not implemented");
  return false;
}

Register IA16RegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  // TODO: needs SP (and possibly BP) register(s)
  llvm_unreachable("getFrameRegister not implemented");

  return IA16::AX; // Dummy for now
}

}