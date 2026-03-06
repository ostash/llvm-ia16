//===-- IA16MachineFunctionInfo.h - IA16 machine function info --*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares IA16-specific per-machine-function information.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_IA16_IA16MACHINEFUNCTIONINFO_H
#define LLVM_LIB_TARGET_IA16_IA16MACHINEFUNCTIONINFO_H

#include "llvm/CodeGen/MachineFunction.h"

namespace llvm {

class IA16MachineFunctionInfo : public MachineFunctionInfo {
public:
  IA16MachineFunctionInfo() = default;
  IA16MachineFunctionInfo(const Function &F, const TargetSubtargetInfo *STI) {}
  MachineFunctionInfo *
  clone(BumpPtrAllocator &Allocator, MachineFunction &DestMF,
        const DenseMap<MachineBasicBlock *, MachineBasicBlock *> &Src2DstMBB)
      const override {
    return DestMF.cloneInfo<IA16MachineFunctionInfo>(*this);
  }
};

} // namespace llvm

#endif
