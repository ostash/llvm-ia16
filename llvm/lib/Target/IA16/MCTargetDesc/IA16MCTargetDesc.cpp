//===-- IA16MCTargetDesc.cpp - IA16 Target Descriptions -----------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#include "MCTargetDesc/IA16MCTargetDesc.h"

#include "MCTargetDesc/IA16InstPrinter.h"
#include "TargetInfo/IA16TargetInfo.h"

#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

#define GET_REGINFO_ENUM
#include "IA16GenRegisterInfo.inc"

// For InitIA16MCInstrInfo()
#define GET_INSTRINFO_MC_DESC
#include "IA16GenInstrInfo.inc"

// For InitIA16MCRegisterInfo()

#define GET_REGINFO_MC_DESC
#include "IA16GenRegisterInfo.inc"

// For createIA16MCSubtargetInfoImpl()
#define GET_SUBTARGETINFO_MC_DESC
#include "IA16GenSubtargetInfo.inc"

namespace llvm {

static MCAsmInfo *createIA16MCAsmInfo(const MCRegisterInfo &MRI,
                                      const Triple &TT,
                                      const MCTargetOptions &Options) {
  // TODO: Create custom IA16MCAsmInfo?
  return new MCAsmInfo();
}

static MCInstrInfo *createIA16MCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitIA16MCInstrInfo(X);
  return X;
}

static MCRegisterInfo *createIA16MCRegisterInfo(const Triple &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  // TODO: RA - return address register: X86 passes EIP/RIP, but return address
  // is actually on stack. Targets with link register pass that register which
  // make perfect sense. We do not have IP defined yet anyway, so NoRegister is
  // a way to go for now.
  // TODO: PC - program counter register: we should pasS IP when it will be
  // defined.
  InitIA16MCRegisterInfo(X, /*RA=*/IA16::NoRegister, /*DwarfFlavour=*/0,
                         /*EHFlavour=*/0, /*PC=*/0);
  return X;
}

static MCSubtargetInfo *createIA16MCSubtargetInfo(const Triple &TT,
                                                  StringRef CPU, StringRef FS) {
  return createIA16MCSubtargetInfoImpl(TT, CPU, /*TuneCPU=*/ CPU, FS);
}

static MCInstPrinter *createIA16MCInstPrinter(const Triple &T,
                                              unsigned SyntaxVariant,
                                              const MCAsmInfo &MAI,
                                              const MCInstrInfo &MII,
                                              const MCRegisterInfo &MRI) {
  return new IA16InstPrinter(MAI, MII, MRI);
}

} // namespace llvm

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeIA16TargetMC() {
  llvm::Target &T = llvm::getTheIA16Target();

  // There are plenty of ways how target can hook its specific implementation to
  // the LLVM. Root place is to register creators of the target components in
  // the TargetRegistry. Currently there are 27 such creators defined in Target
  // class. Most of the are registered in LLVMInitialize<XXX>TargetMC function,
  // but there are exceptions.

  // Here we list all of them in the order of definition in Target class.
  // Currently most of them are commented out. As backend implementation
  // matures, more of them will be uncommented.

  // Register assembly info
  llvm::TargetRegistry::RegisterMCAsmInfo(T, llvm::createIA16MCAsmInfo);

  // NOTE: MCObjectFileInfo is created by default
  // llvm::TargetRegistry::RegisterMCObjectFileInfo(T,
  // llvm::createIA16MCObjectInfo);

  // Register instruction info
  llvm::TargetRegistry::RegisterMCInstrInfo(T, llvm::createIA16MCInstrInfo);

  // llvm::TargetRegistry::RegisterMCInstrAnalysis(T,
  // llvm::createIA16MCInstrAnalysis);

  // Register register info
  llvm::TargetRegistry::RegisterMCRegInfo(T, llvm::createIA16MCRegisterInfo);

  // Register subtarget info
  llvm::TargetRegistry::RegisterMCSubtargetInfo(
      T, llvm::createIA16MCSubtargetInfo);

  // NOTE: TargetRegistry::RegisterTargetMachine() is called from
  // LLVMInitializeIA16Target

  // llvm::TargetRegistry::RegisterMCAsmBackend(T,
  // llvm::createIA16MCAsmBackend);

  // NOTE: TargetRegistry::RegisterMCAsmParser() is called from
  // LLVMInitializeIA16AsmParser

  // NOTE: TargetRegistry::RegisterAsmPrinter() is called from
  // LLVMInitializeIA16AsmPrinter

  // NOTE: TargetRegistry::RegisterMCDisassembler() is called from
  // LLVMInitializeIA16Disassembler

  // Register instruction printer
  llvm::TargetRegistry::RegisterMCInstPrinter(T, llvm::createIA16MCInstPrinter);

  // llvm::TargetRegistry::RegisterMCCodeEmitter(T,
  // llvm::createIA16MCCodeEmitter);

  // llvm::TargetRegistry::RegisterCOFFStreamer(T,
  // llvm::createIA16COFFStreamer);

  // NOTE: MCMachOStreamer is created by default
  // llvm::TargetRegistry::RegisterMachOStreamer(T,
  // llvm::createIA16MachOStreamer);

  // NOTE: MCELFStreamer is created by default
  // llvm::TargetRegistry::RegisterELFStreamer(T, llvm::createIA16ELFStreamer);

  // llvm::TargetRegistry::RegisterXCOFFStreamer(T,
  // llvm::createIA16XCOFFStreamer);

  // llvm::TargetRegistry::RegisterNullTargetStreamer(
  //     T, llvm::createIA16NullTargetStreamer);

  // llvm::TargetRegistry::RegisterAsmTargetStreamer(
  //     T, llvm::createIA16AsmTargetStreamer);

  // NOTE: MCAsmStreamer is created by default
  // llvm::TargetRegistry::RegisterAsmStreamer(T, llvm::createIA16AsmStreamer);

  // llvm::TargetRegistry::RegisterObjectTargetStreamer(
  //     T, llvm::createIA16ObjectTargetStreamer);

  // NOTE: MCRelocationInfo is created by default
  // llvm::TargetRegistry::RegisterMCRelocationInfo(
  //     T, llvm::createIA16MCRelocationInfo);

  // NOTE: MCExternalSymbolizer is created by default
  // NOTE: llvm::TargetRegistry::RegisterMCSymbolizer() is called from
  // LLVMInitializeIA16Disassembler

  // NOTE: TargetRegistry::RegisterCustomBehaviour() is called from
  // LLVMInitializeIA16TargetMCA

  // NOTE: TargetRegistry::RegisterInstrPostProcess() is called from
  // LLVMInitializeIA16TargetMCA

  // NOTE: TargetRegistry::RegisterInstrumentManager() is called from
  // LLVMInitializeIA16TargetMCA

  // llvm::TargetRegistry::RegisterMCLFIRewriter(T,
  // llvm::createIA16MCLFIRewriter);
}
