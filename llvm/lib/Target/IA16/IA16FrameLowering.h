//===-- IA16FrameLowering.h - Define frame lowering for IA16 --*- C++ -*--===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_IA16_IA16FRAMELOWERING_H
#define LLVM_LIB_TARGET_IA16_IA16FRAMELOWERING_H

#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {
class IA16Subtarget;

class IA16FrameLowering : public TargetFrameLowering {
  const IA16Subtarget &STI;

public:
  explicit IA16FrameLowering(const IA16Subtarget &STI)
      : TargetFrameLowering(StackGrowsDown, Align(2), 0), STI(STI) {}

  void emitPrologue(MachineFunction &MF, MachineBasicBlock &MBB) const override;
  void emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const override;
  bool hasFPImpl(const MachineFunction &MF) const override;
};
} // namespace llvm

#endif
