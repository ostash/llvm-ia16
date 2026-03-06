//===-- IA16MCTargetDesc.cpp - IA16 Target Descriptions -----------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "IA16MCTargetDesc.h"
#include "IA16InstPrinter.h"
#include "IA16MCAsmInfo.h"
#include "TargetInfo/IA16TargetInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_INSTRINFO_MC_DESC
#define GET_INSTRINFO_MC_HELPERS
#include "IA16GenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "IA16GenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "IA16GenRegisterInfo.inc"

static MCInstrInfo *createIA16MCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitIA16MCInstrInfo(X);
  return X;
}

static MCRegisterInfo *createIA16MCRegisterInfo(const Triple &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitIA16MCRegisterInfo(X, 0);
  return X;
}

static MCSubtargetInfo *createIA16MCSubtargetInfo(const Triple &TT,
                                                  StringRef CPU, StringRef FS) {
  return createIA16MCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCInstPrinter *createIA16MCInstPrinter(const Triple &T,
                                              unsigned SyntaxVariant,
                                              const MCAsmInfo &MAI,
                                              const MCInstrInfo &MII,
                                              const MCRegisterInfo &MRI) {
  return new IA16InstPrinter(MAI, MII, MRI);
}

static MCAsmInfo *createIA16MCAsmInfo(const MCRegisterInfo &MRI,
                                      const Triple &TT,
                                      const MCTargetOptions &Options) {
  return new IA16MCAsmInfo(TT);
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeIA16TargetMC() {
  Target &T = getTheIA16Target();
  RegisterMCAsmInfoFn X(T, createIA16MCAsmInfo);
  TargetRegistry::RegisterMCInstrInfo(T, createIA16MCInstrInfo);
  TargetRegistry::RegisterMCRegInfo(T, createIA16MCRegisterInfo);
  TargetRegistry::RegisterMCSubtargetInfo(T, createIA16MCSubtargetInfo);
  TargetRegistry::RegisterMCInstPrinter(T, createIA16MCInstPrinter);
}
