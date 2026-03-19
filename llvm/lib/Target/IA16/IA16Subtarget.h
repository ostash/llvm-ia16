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

#include "IA16RegisterInfo.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"

#define GET_SUBTARGETINFO_HEADER
#include "IA16GenSubtargetInfo.inc"

#if 0

#include "IA16InstrInfo.h"
// #include "IA16SelectionDAGInfo.h"

#endif

namespace llvm {
// class StringRef;
class IA16TargetMachine;

class IA16Subtarget : public IA16GenSubtargetInfo {
public:
  IA16Subtarget(const Triple &TT, const std::string &CPU, const std::string &FS,
                const IA16TargetMachine &TM);

  // Things that can be overriden from MCSubtargetInfo

  // unsigned resolveVariantSchedClass(...) const - implemented by
  // IA16GenSubtargetInfo

  // bool isCPUStringValid(StringRef CPU) const final;

  // unsigned getHwModeSet() const final;

  // unsigned getHwMode(enum HwModeType type = HwMode_Default) const final;

  // std::optional<unsigned> getCacheSize(unsigned Level) const final;

  // std::optional<unsigned> getCacheAssociativity(unsigned Level) const final;

  // std::optional<unsigned> getCacheLineSize(unsigned Level) const final;

  // unsigned getCacheLineSize() const final;

  // unsigned getPrefetchDistance() const final;

  // unsigned getMaxPrefetchIterationsAhead() const final;

  // bool enableWritePrefetching() const final;

  // unsigned getMinPrefetchStride(unsigned NumMemAccesses,
  //                               unsigned NumStridedMemAccesses,
  //                               unsigned NumPrefetches,
  //                               bool HasCall) const final;

  // bool shouldPrefetchAddressSpace(unsigned AS) const final;

  // Things that can be overriden from TargetSubtargetInfo

  // bool isXRaySupported() const final;

  // const TargetInstrInfo *getInstrInfo() const final;

  const TargetFrameLowering *getFrameLowering() const final;

  const TargetLowering *getTargetLowering() const final;

  // const SelectionDAGTargetInfo *getSelectionDAGInfo() const final;

  // const CallLowering *getCallLowering() const final;

  // const InlineAsmLowering *getInlineAsmLowering() const final;

  // InstructionSelector *getInstructionSelector() const final;

  // RegisterScheduler::FunctionPassCtor
  //     getDAGScheduler(CodeGenOptLevel) const final;

  // const LegalizerInfo *getLegalizerInfo() const final;

  const TargetRegisterInfo *getRegisterInfo() const final;

  // const RegisterBankInfo *getRegBankInfo() const final;

  // const InstrItineraryData *getInstrItineraryData() const final;

  // void initLibcallLoweringInfo(LibcallLoweringInfo &Info) const final;

  // // unsigned resolveSchedClass(...) const - implemented by
  // IA16GenSubtargetInfo

  // bool isZeroIdiom(const MachineInstr *MI, APInt &Mask) const final;

  // bool isDependencyBreaking(const MachineInstr *MI, APInt &Mask) const final;

  // bool isOptimizableRegisterMove(const MachineInstr *MI) const final;

  // bool enableMachineScheduler() const final;

  // bool enableMachineSchedDefaultSched() const final;

  // bool enableMachinePipeliner() const final;

  // bool enableWindowScheduler() const final;

  // bool enableJoinGlobalCopies() const final;

  // bool enableTerminalRule() const final;

  // bool enablePostRAScheduler() const final;

  // bool enablePostRAMachineScheduler() const final;

  // bool enableAtomicExpand() const final;

  // bool enableIndirectBrExpand() const final;

  // void overrideSchedPolicy(MachineSchedPolicy &Policy,
  //                          const SchedRegion &Region) const final;

  // void overridePostRASchedPolicy(MachineSchedPolicy &Policy,
  //                                const SchedRegion &Region) const final;

  // void adjustSchedDependency(SUnit *Def, int DefOpIdx, SUnit *Use, int
  // UseOpIdx,
  //                            SDep &Dep,
  //                            const TargetSchedModel *SchedModel) const final;

  // AntiDepBreakMode getAntiDepBreakMode() const final;

  // void getCriticalPathRCs(RegClassVector &CriticalPathRCs) const final;

  // void getPostRAMutations(
  //     std::vector<std::unique_ptr<ScheduleDAGMutation>> &Mutations) const
  //     final;

  // void getSMSMutations(
  //     std::vector<std::unique_ptr<ScheduleDAGMutation>> &Mutations) const
  //     final;

  // bool useDFAforSMS() const final;

  // CodeGenOptLevel getOptLevelToEnablePostRAScheduler() const final;

  // bool enableRALocalReassignment(CodeGenOptLevel OptLevel) const final;

  // bool useAA() const final;

  // bool addrSinkUsingGEPs() const final;

  // bool enableEarlyIfConversion() const final;

  // std::unique_ptr<PBQPRAConstraint> getCustomPBQPConstraints() const final;

  // bool enableSubRegLiveness() const final;

  // void mirFileLoaded(MachineFunction &MF) const final;

  // bool ignoreCSRForAllocationOrder(const MachineFunction &MF,
  //                                  MCRegister PhysReg) const final;

  // unsigned char
  // classifyGlobalFunctionReference(const GlobalValue *GV) const final;

  // bool enableSpillageCopyElimination() const final;

  // std::vector<MacroFusionPredTy> getMacroFusions() const final;

  // bool requiresDisjointEarlyClobberAndUndef() const final;

  // bool isRegisterReservedByUser(Register R) const final;

public:
  // const Triple &TT, StringRef CPU, StringRef TuneCPU, StringRef FS

  // const IA16InstrInfo *getInstrInfo() const override { return &InstrInfo; }

  // const IA16SelectionDAGInfo *getSelectionDAGInfo() const override {
  //   return &TSInfo;
  // }

  // void ParseSubtargetFeatures(StringRef CPU, StringRef TuneCPU, StringRef
  // FS);

private:
  // IA16InstrInfo InstrInfo;
  // virtual void anchor();
  // IA16InstrInfo InstrInfo;
  // IA16SelectionDAGInfo TSInfo;
  const IA16RegisterInfo RI;
  const IA16TargetLowering TLInfo;
  const IA16FrameLowering FrameLowering;
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_IA16_IA16SUBTARGET_H