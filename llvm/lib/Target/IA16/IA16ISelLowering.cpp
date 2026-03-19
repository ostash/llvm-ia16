//===-- IA16ISelLowering.cpp - IA16 DAG Lowering Implementation -----------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the IA16TargetLowering class.
//
//===----------------------------------------------------------------------===//
#include "IA16ISelLowering.h"

#include "IA16Subtarget.h"

#if 0
#include "MCTargetDesc/IA16MCTargetDesc.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"

using namespace llvm;

#include "IA16GenCallingConv.inc"
#endif

#define GET_SDNODE_ENUM
#include "IA16GenSDNodeInfo.inc"


namespace llvm {

IA16TargetLowering::IA16TargetLowering(const TargetMachine &TM,
                                       const IA16Subtarget &STI)
    : TargetLowering(TM, STI), Subtarget(STI) {

  // llvm::errs() << "IA16TargetLowering::IA16TargetLowering\n";
  // addRegisterClass(MVT::i16, &IA16::GR16RegClass);

  // computeRegisterProperties(STI.getRegisterInfo());

  // Set minimum operations to legal.
  // setOperationAction(ISD::ADD, MVT::i16, Legal);

  // for (size_t i = 0; i < std::size(LoadExtActions); i++) {
  //   for (size_t j = 0; j < std::size(LoadExtActions[ i]); ++j) {
  //     if (LoadExtActions[i][j] == 0)
  //       llvm::errs() << "LoadExtActions[" << i << "][" << j << "] = " <<
  //       LoadExtActions[i][j] << "\n";
  //   }
  // }

  // for (size_t i = 0; i < std::size(AtomicLoadExtActions); i++) {
  //   for (size_t j = 0; j < std::size(AtomicLoadExtActions[ i]); ++j) {
  //     if (AtomicLoadExtActions[i][j] == 0)
  //       llvm::errs() << "AtomicLoadExtActions[" << i << "][" << j << "] = "
  //       << AtomicLoadExtActions[i][j] << "\n";
  //   }
  // }

  // for (size_t i = 0; i < std::size(TruncStoreActions); i++) {
  //   for (size_t j = 0; j < std::size(TruncStoreActions[ i]); ++j) {
  //     if (TruncStoreActions[i][j] == 0)
  //       llvm::errs() << "TruncStoreActions[" << i << "][" << j << "] = " <<
  //       TruncStoreActions[i][j] << "\n";
  //   }
  // }

  // for (size_t i = 0; i < std::size(IndexedModeActions); i++) {
  //   for (size_t j = 0; j < std::size(IndexedModeActions[ i]); ++j) {
  //     if (IndexedModeActions[i][j] == 0)
  //       llvm::errs() << "IndexedModeActions[" << i << "][" << j << "] = " <<
  //       IndexedModeActions[i][j] << "\n";
  //   }
  // }

  // for (size_t i = 0; i < std::size(CondCodeActions); i++) {
  //   for (size_t j = 0; j < std::size(CondCodeActions[ i]); ++j) {
  //     if (CondCodeActions[i][j] == 0)
  //       llvm::errs() << "CondCodeActions[" << i << "][" << j << "] = " <<
  //       CondCodeActions[i][j] << "\n";
  //   }
  // }
}

#if 0
// SDValue IA16TargetLowering::LowerOperation(SDValue Op,
//                                            SelectionDAG &DAG) const {
//   return SDValue();
// }

// SDValue IA16TargetLowering::LowerFormalArguments(
//     SDValue Chain, CallingConv::ID CallConv, bool isVarArg,
//     const SmallVectorImpl<ISD::InputArg> &Ins, const SDLoc &dl,
//     SelectionDAG &DAG, SmallVectorImpl<SDValue> &InVals) const {
//   MachineFunction &MF = DAG.getMachineFunction();
//   MachineRegisterInfo &RegInfo = MF.getRegInfo();

//   // Assign locations to all of the incoming arguments.
//   SmallVector<CCValAssign, 16> ArgLocs;
//   CCState CCInfo(CallConv, isVarArg, MF, ArgLocs, *DAG.getContext());
//   CCInfo.AnalyzeFormalArguments(Ins, CC_IA16);

//   for (unsigned i = 0, e = ArgLocs.size(); i != e; ++i) {
//     CCValAssign &VA = ArgLocs[i];
//     if (VA.isRegLoc()) {
//       // Arguments passed in registers
//       EVT RegVT = VA.getLocVT();
//       const TargetRegisterClass *RC = &IA16::GR16RegClass;
//       Register Reg = RegInfo.createVirtualRegister(RC);
//       RegInfo.addLiveIn(VA.getLocReg(), Reg);
//       SDValue ArgValue = DAG.getCopyFromReg(Chain, dl, Reg, RegVT);

//       InVals.push_back(ArgValue);
//     } else {
//       llvm_unreachable("Stack arguments not implemented");
//     }
//   }
//   return Chain;
// }
#endif

SDValue
IA16TargetLowering::LowerReturn(SDValue Chain, CallingConv::ID CallConv,
                                bool isVarArg,
                                const SmallVectorImpl<ISD::OutputArg> &Outs,
                                const SmallVectorImpl<SDValue> &OutVals,
                                const SDLoc &DL, SelectionDAG &DAG) const {
  SmallVector<SDValue, 1> RetOps;
  RetOps.push_back(Chain);
  // For Phase 1: i16 return value goes in AX
  // CCState analysis of Outs → assign to AX, emit CopyToReg, glue into RetOps
  return DAG.getNode(IA16ISD::RET_GLUE, DL, MVT::Other, RetOps);

  // MachineFunction &MF = DAG.getMachineFunction();

  // SmallVector<CCValAssign, 16> RetLocs;
  // CCState CCInfo(CallConv, isVarArg, MF, RetLocs, *DAG.getContext());
  // CCInfo.AnalyzeReturn(Outs, RetCC_IA16);

  // SDValue Flag;
  // SmallVector<SDValue, 4> RetOps;
  // RetOps.push_back(Chain); // Operand #0: Chain
  // RetOps.push_back(
  //     DAG.getTargetConstant(0, dl, MVT::i16)); // Operand #1: Bytes to pop

  // // Copy the result values into the output registers.
  // for (unsigned i = 0, e = RetLocs.size(); i != e; ++i) {
  //   CCValAssign &VA = RetLocs[i];
  //   assert(VA.isRegLoc() && "Can only return in registers!");

  //   Chain = DAG.getCopyToReg(Chain, dl, VA.getLocReg(), OutVals[i], Flag);

  //   // Guarantee that all emitted copies are stuck together with flags.
  //   Flag = Chain.getValue(1);
  //   RetOps.push_back(DAG.getRegister(VA.getLocReg(), VA.getLocVT()));
  // }

  // RetOps[0] = Chain; // Update chain.

  // // Add the glue if we have it.
  // if (Flag.getNode())
  //   RetOps.push_back(Flag);

  // return DAG.getNode(IA16ISD::RET_FLAG, dl, MVT::Other, RetOps);
  return Chain;
}

#if 0
// SDValue IA16TargetLowering::LowerCall(TargetLowering::CallLoweringInfo &CLI,
//                                       SmallVectorImpl<SDValue> &InVals) const {
//   return SDValue();
// }

// const char *IA16TargetLowering::getTargetNodeName(unsigned Opcode) const {
//   switch (Opcode) {
//   case IA16ISD::RET_FLAG:
//     return "IA16ISD::RET_FLAG";
//   default:
//     return nullptr;
//   }
// }
#endif

} // namespace llvm
