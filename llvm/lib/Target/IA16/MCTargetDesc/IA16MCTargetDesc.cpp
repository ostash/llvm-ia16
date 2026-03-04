//===- IA16MCTargetDesc.cpp - IA16 Target Descriptions ----------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
// #include "IA16MCTargetDesc.h"
#include "IA16InstPrinter.h"
// #include "IA16MCAsmInfo.h"
// #include "IA16TargetStreamer.h"
#include "TargetInfo/IA16TargetInfo.h"
// #include "llvm/MC/MCDwarf.h"
// #include "llvm/MC/MCInstrInfo.h"
// #include "llvm/MC/MCRegisterInfo.h"
// #include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
// #include "llvm/Support/ErrorHandling.h"
// #include "llvm/Support/FormattedStream.h"

// using namespace llvm;

// #define GET_INSTRINFO_MC_DESC
// #define ENABLE_INSTR_PREDICATE_VERIFIER
// #include "IA16GenInstrInfo.inc"

// #define GET_SUBTARGETINFO_MC_DESC
// #include "IA16GenSubtargetInfo.inc"

// #define GET_REGINFO_MC_DESC
// #include "IA16GenRegisterInfo.inc"

// static MCInstrInfo *createIA16MCInstrInfo() {
//   auto *X = new MCInstrInfo();
//   InitIA16MCInstrInfo(X);
//   return X;
// }
//
// static MCRegisterInfo *createIA16MCRegisterInfo(const Triple &TT) {
//   auto *X = new MCRegisterInfo();
//   InitIA16MCRegisterInfo(X, IA16::BLINK);
//   return X;
// }
//
// static MCSubtargetInfo *createIA16MCSubtargetInfo(const Triple &TT,
//                                                  StringRef CPU, StringRef FS)
//                                                  {
//   return createIA16MCSubtargetInfoImpl(TT, CPU, /*TuneCPU=*/CPU, FS);
// }
//
//
// static MCInstPrinter *createIA16MCInstPrinter(const Triple &T,
//                                              unsigned SyntaxVariant,
//                                              const MCAsmInfo &MAI,
//                                              const MCInstrInfo &MII,
//                                              const MCRegisterInfo &MRI) {
//   return new IA16InstPrinter(MAI, MII, MRI);
// }
//
// IA16TargetStreamer::IA16TargetStreamer(MCStreamer &S) : MCTargetStreamer(S)
// {} IA16TargetStreamer::~IA16TargetStreamer() = default;
//
// static MCTargetStreamer *createTargetAsmStreamer(MCStreamer &S,
//                                                  formatted_raw_ostream &OS,
//                                                  MCInstPrinter *InstPrint) {
//   return new IA16TargetStreamer(S);
// }
namespace llvm {

static MCAsmInfo *createIA16MCAsmInfo(const MCRegisterInfo &MRI,
                                      const Triple &TT,
                                      const MCTargetOptions &Options) {
  return new MCAsmInfo();
}

static MCInstrInfo *createIA16MCInstrInfo() { return new MCInstrInfo(); }

static MCRegisterInfo *createIA16MCRegisterInfo(const Triple &TT) {
  return new MCRegisterInfo();
}

static const StringRef IA16ProcNames = {"generic"};
static const SubtargetFeatureKV IA16ProcFeatures = {
    SubtargetFeatureKV{nullptr, nullptr, 0, FeatureBitArray({})}};
static const SubtargetSubTypeKV IA16ProcDesc = {
    SubtargetSubTypeKV{nullptr, FeatureBitArray({}), FeatureBitArray({}), 0}};

static MCSubtargetInfo *
createIA16MCSubtargetInfo(const Triple &TT, StringRef CPU, StringRef Features) {
  return new MCSubtargetInfo(
      TT, CPU, CPU /* TuneCPU*/, "", IA16ProcNames, IA16ProcFeatures,
      IA16ProcDesc, nullptr /* const MCWriteProcResEntry *WPR */,
      nullptr /* const MCWriteLatencyEntry *WL */,
      nullptr /* const MCReadAdvanceEntry *RA */,
      nullptr /* const InstrStage *IS */, nullptr /* const unsigned int *OC */,
      nullptr /* const unsigned int *FP */);
}

static MCInstPrinter *createIA16MCInstPrinter(const Triple &T,
                                              unsigned SyntaxVariant,
                                              const MCAsmInfo &MAI,
                                              const MCInstrInfo &MII,
                                              const MCRegisterInfo &MRI) {
  return new IA16InstPrinter(MAI, MII, MRI);
}

} // namespace llvm

// Force static initialization.
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeIA16TargetMC() {
  // Target::MCAsmInfoCtorFn
  llvm::TargetRegistry::RegisterMCAsmInfo(llvm::getTheIA16Target(),
                                          &llvm::createIA16MCAsmInfo);

  // Target::MCObjectFileInfoCtorFn, TargetRegistry::RegisterMCObjectFileInfo -
  // MCObjectFileInfo by default

  // Target::MCInstrInfoCtorFn
  llvm::TargetRegistry::RegisterMCInstrInfo(llvm::getTheIA16Target(),
                                            &llvm::createIA16MCInstrInfo);

  // LATER: Target::MCInstrAnalysisCtorFn,
  // TargetRegistry::RegisterMCInstrAnalysis

  // Target::MCRegInfoCtorFn
  llvm::TargetRegistry::RegisterMCRegInfo(llvm::getTheIA16Target(),
                                          &llvm::createIA16MCRegisterInfo);

  // TODO: Target::MCSubtargetInfoCtorFn,
  // TargetRegistry::RegisterMCSubtargetInfo
  llvm::TargetRegistry::RegisterMCSubtargetInfo(
      llvm::getTheIA16Target(), &llvm::createIA16MCSubtargetInfo);

  // DONE: Target::TargetMachineCtorFn,
  //  TargetRegistry::RegisterTargetMachine - see IA16TargetMachine.* LATER:
  //  Target::MCAsmBackendCtorFn, TargetRegistry::RegisterMCAsmBackend LATER:
  //  Target::MCAsmParserCtorFn, TargetRegistry::RegisterMCAsmParser - in
  //  LLVMInitializeIA16AsmParser LATER: Target::AsmPrinterCtorFn,
  //  TargetRegistry::RegisterAsmPrinter - in LLVMInitializeIA16AsmPrinter
  //  LATER: Target::MCDisassemblerCtorFn,
  //  TargetRegistry::RegisterMCDisassembler - LLVMInitializeIA16Disassembler

  //  LATER: Target::MCInstPrinterCtorFn, TargetRegistry::RegisterMCInstPrinter
  llvm::TargetRegistry::RegisterMCInstPrinter(llvm::getTheIA16Target(),
                                              &llvm::createIA16MCInstPrinter);

  //  LATER: Target::MCCodeEmitterCtorFn, TargetRegistry::RegisterMCCodeEmitter
  //  LATER: Target: {COFF,MachOS,ELF,XCOFF}StreamerCtorFn,
  //  TargetRegistry::Register{COFF,MachOS,ELF,XCOFF}Streamer LATER:
  //  Target::NullTargetStreamerCtorFn,
  //  TargetRegistry::RegisterNullTargetStreamer LATER:
  //  Target::AsmTargetStreamerCtorFn, TargetRegistry::RegisterAsmTargetStreamer
  //  LATER: Target::ObjectTargetStreamerCtorFn,
  //  TargetRegistry::RegisterObjectTargetStreamer MAYBE:
  //  Target::MCRelocationInfoCtorFn, TargetRegistry::RegisterMCRelocationInfo -
  //  MCRelocationInfo by default MAYBE: Target::MCSymbolizerCtorFn,
  //  TargetRegistry::RegisterMCSymbolizer - MCExternalSymbolizer by default, in
  //  LLVMInitializeIA16Disassemble MAYBE: Target::CustomBehaviourCtorFn,
  //  TargetRegistry::RegisterCustomBehaviour - in LLVMInitializeIA16TargetMCA
  //  MAYBE: Target::InstrPostProcessCtorFn,
  //  TargetRegistry::RegisterInstrPostProcess - in LLVMInitializeIA16TargetMCA
  //  MAYBE:: Target::InstrumentManagerCtorFn,
  //  TargetRegistry::RegisterInstrumentManager - in LLVMInitializeIA16TargetMCA
}
