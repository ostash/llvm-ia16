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
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define DEBUG_TYPE "ia16-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "IA16GenSubtargetInfo.inc"

void IA16Subtarget::anchor() {}

IA16Subtarget::IA16Subtarget(const Triple &TT, const std::string &CPU,
                             const std::string &FS, const IA16TargetMachine &TM)
    : IA16GenSubtargetInfo(TT, CPU, /*TuneCPU=*/CPU, FS), InstrInfo(*this),
      FrameLowering(*this), TLInfo(TM, *this), TSInfo() {}
