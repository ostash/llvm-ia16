//===-- IA16Subtarget.cpp - IA16 Subtarget Information --------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the IA16 specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//
#include "IA16Subtarget.h"

#include "IA16TargetMachine.h"

#define GET_SUBTARGETINFO_CTOR
#include "IA16GenSubtargetInfo.inc"

#if 0

#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define DEBUG_TYPE "ia16-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC

void IA16Subtarget::anchor() {}
#endif

namespace llvm {

IA16Subtarget::IA16Subtarget(const Triple &TT, const std::string &CPU,
                             const std::string &FS, const IA16TargetMachine &TM)
    : IA16GenSubtargetInfo(TT, CPU, /*TuneCPU=*/CPU, FS)
      // , InstrInfo(*this)
      ,
      TLInfo(TM, *this)
/*, TSInfo() */
{}

const TargetFrameLowering *IA16Subtarget::getFrameLowering() const {
  return &FrameLowering;
}

const TargetLowering *IA16Subtarget::getTargetLowering() const {
  return &TLInfo;
}

const TargetRegisterInfo *IA16Subtarget::getRegisterInfo() const { return &RI; }

} // namespace llvm