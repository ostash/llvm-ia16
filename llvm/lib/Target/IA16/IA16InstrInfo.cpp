//===-- IA16InstrInfo.cpp - IA16 Instruction Information ------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the IA16 implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#if 0

#include "IA16InstrInfo.h"
#include "IA16.h"
#include "IA16Subtarget.h"
#include "MCTargetDesc/IA16MCTargetDesc.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"

#define GET_INSTRINFO_CTOR_DTOR
#include "IA16GenInstrInfo.inc"

using namespace llvm;

IA16InstrInfo::IA16InstrInfo(const IA16Subtarget &STI)
    : IA16GenInstrInfo(STI, RI), RI() {}

// void IA16InstrInfo::copyPhysReg(MachineBasicBlock &MBB,
//                                 MachineBasicBlock::iterator I,
//                                 const DebugLoc &DL, Register DestReg,
//                                 Register SrcReg, bool KillSrc,
//                                 bool RenamableDest, bool RenamableSrc) const {
//   BuildMI(MBB, I, DL, get(IA16::MOV16rr), DestReg)
//       .addReg(SrcReg, getKillRegState(KillSrc));
// }
#endif