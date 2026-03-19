//===-- IA16TargetMachine.h - Define TargetMachine for IA16 ---*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares the IA16 specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//
#ifndef LLVM_LIB_TARGET_IA16_IA16TARGETMACHINE_H
#define LLVM_LIB_TARGET_IA16_IA16TARGETMACHINE_H

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"

namespace llvm {

class IA16TargetMachine : public CodeGenTargetMachineImpl {
public:
  IA16TargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                    StringRef FS, const TargetOptions &Options,
                    std::optional<Reloc::Model> RM,
                    std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                    bool JIT);

  ~IA16TargetMachine() final;

  // Things that can be overriden from TargetMachine

  const TargetSubtargetInfo *getSubtargetImpl(const Function &F) const final;

  TargetLoweringObjectFile *getObjFileLowering() const final;

  // MachineFunctionInfo *
  // createMachineFunctionInfo(BumpPtrAllocator &Allocator, const Function &F,
  //                           const TargetSubtargetInfo *STI) const final;

  // ScheduleDAGInstrs *createMachineScheduler(MachineSchedContext *C) const
  // final;

  // ScheduleDAGInstrs *
  // createPostMachineScheduler(MachineSchedContext *C) const final;

  // yaml::MachineFunctionInfo *createDefaultFuncInfoYAML() const final;

  // yaml::MachineFunctionInfo *
  // convertFuncInfoToYAML(const MachineFunction &MF) const final;

  // bool parseMachineFunctionInfo(const yaml::MachineFunctionInfo &,
  //                               PerFunctionMIParsingState &PFS,
  //                               SMDiagnostic &Error,
  //                               SMRange &SourceRange) const final;

  // bool isNoopAddrSpaceCast(unsigned SrcAS, unsigned DestAS) const final;

  // unsigned getAssumedAddrSpace(const Value *V) const final;

  // std::pair<const Value *, unsigned>
  // getPredicatedAddrSpace(const Value *V) const final;

  // TargetTransformInfo getTargetTransformInfo(const Function &F) const final;

  // void registerPassBuilderCallbacks(PassBuilder &) final;

  // void registerEarlyDefaultAliasAnalyses(AAManager &) final;

  // void registerDefaultAliasAnalyses(AAManager &) final;

  // bool addPassesToEmitFile(PassManagerBase &, raw_pwrite_stream &,
  //                          raw_pwrite_stream *, CodeGenFileType,
  //                          bool /*DisableVerify*/ = true,
  //                          MachineModuleInfoWrapperPass *MMIWP = nullptr)
  //                          final;

  // bool addPassesToEmitMC(PassManagerBase &, MCContext *&, raw_pwrite_stream
  // &,
  //                        bool /*DisableVerify*/ = true) final;

  // bool targetSchedulesPostRAScheduling() const final;

  // unsigned getSjLjDataSize() const final;

  // unsigned getAddressSpaceForPseudoSourceKind(unsigned Kind) const final;

  // bool splitModule(
  //     Module &M, unsigned NumParts,
  //     function_ref<void(std::unique_ptr<Module> MPart)> ModuleCallback)
  //     final;

  TargetPassConfig *createPassConfig(PassManagerBase &PM) final;

  // Error buildCodeGenPipeline(ModulePassManager &MPM, raw_pwrite_stream &Out,
  //                            raw_pwrite_stream *DwoOut,
  //                            CodeGenFileType FileType,
  //                            const CGPassBuilderOption &Opt, MCContext &Ctx,
  //                            PassInstrumentationCallbacks *PIC) final;

  // bool isMachineVerifierClean() const final;

  // bool addAsmPrinter(PassManagerBase &PM, raw_pwrite_stream &Out,
  //                    raw_pwrite_stream *DwoOut, CodeGenFileType FileType,
  //                    MCContext &Context) final;

  // Expected<std::unique_ptr<MCStreamer>>
  // createMCStreamer(raw_pwrite_stream &Out, raw_pwrite_stream *DwoOut,
  //                  CodeGenFileType FileType, MCContext &Ctx) final;

  // bool usesPhysRegsForValues() const final;

  // bool useIPRA() const final;

  // int unqualifiedInlineAsmVariant() const final;

  // void registerMachineRegisterInfoCallback(MachineFunction &MF) const final;

  // size_t clearLinkerOptimizationHints(
  //     const SmallPtrSetImpl<MachineInstr *> &MIs) const final;

  // bool canLowerCondLoop() const final;

  // Things that can be overriden from CodeGenTargetMachineImpl
  // void reset() final;

private:
  mutable std::unique_ptr<TargetSubtargetInfo> Subtarget;
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_IA16_IA16TARGETMACHINE_H
