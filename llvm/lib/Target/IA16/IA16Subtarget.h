//===-- IA16Subtarget.h - Define Subtarget for the IA16 -------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares the IA16 specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_IA16_IA16SUBTARGET_H
#define LLVM_LIB_TARGET_IA16_IA16SUBTARGET_H

#include "IA16FrameLowering.h"
#include "IA16ISelLowering.h"
#include "IA16InstrInfo.h"
#include "IA16SelectionDAGInfo.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"

#define GET_SUBTARGETINFO_HEADER
#include "IA16GenSubtargetInfo.inc"

namespace llvm {
class StringRef;
class IA16TargetMachine;

class IA16Subtarget : public IA16GenSubtargetInfo {
  virtual void anchor();
  IA16InstrInfo InstrInfo;
  IA16FrameLowering FrameLowering;
  IA16TargetLowering TLInfo;
  IA16SelectionDAGInfo TSInfo;

public:
  IA16Subtarget(const Triple &TT, const std::string &CPU, const std::string &FS,
                const IA16TargetMachine &TM);

  const IA16InstrInfo *getInstrInfo() const override { return &InstrInfo; }
  const IA16FrameLowering *getFrameLowering() const override {
    return &FrameLowering;
  }
  const IA16TargetLowering *getTargetLowering() const override {
    return &TLInfo;
  }
  const IA16SelectionDAGInfo *getSelectionDAGInfo() const override {
    return &TSInfo;
  }
  const IA16RegisterInfo *getRegisterInfo() const override {
    return &InstrInfo.getRegisterInfo();
  }

  void ParseSubtargetFeatures(StringRef CPU, StringRef TuneCPU, StringRef FS);
};
} // namespace llvm

#endif
