//===-- IA16InstrInfo.h - IA16 Instruction Information ----------*- C++ -*-===//
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

#ifndef LLVM_LIB_TARGET_IA16_IA16INSTRINFO_H
#define LLVM_LIB_TARGET_IA16_IA16INSTRINFO_H

#include "IA16RegisterInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "IA16GenInstrInfo.inc"

namespace llvm {
class IA16Subtarget;

class IA16InstrInfo : public IA16GenInstrInfo {
  const IA16RegisterInfo RI;

public:
  explicit IA16InstrInfo(const IA16Subtarget &STI);

  const IA16RegisterInfo &getRegisterInfo() const { return RI; }

  void copyPhysReg(MachineBasicBlock &MBB, MachineBasicBlock::iterator I,
                   const DebugLoc &DL, Register DestReg, Register SrcReg,
                   bool KillSrc, bool RenamableDest = false,
                   bool RenamableSrc = false) const override;
};
} // namespace llvm

#endif
