//===-- IA16ISelLowering.h - IA16 DAG Lowering Interface --------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the interfaces that IA16 uses to lower LLVM code into a
// selection DAG.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_IA16_IA16ISELLOWERING_H
#define LLVM_LIB_TARGET_IA16_IA16ISELLOWERING_H

#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class IA16Subtarget;

class IA16TargetLowering : public TargetLowering {
  const IA16Subtarget &Subtarget;

public:
  explicit IA16TargetLowering(const TargetMachine &TM,
                              const IA16Subtarget &STI);

  // SDValue LowerOperation(SDValue Op, SelectionDAG &DAG) const override;

  // SDValue LowerFormalArguments(SDValue Chain, CallingConv::ID CallConv,
  //                              bool isVarArg,
  //                              const SmallVectorImpl<ISD::InputArg> &Ins,
  //                              const SDLoc &dl, SelectionDAG &DAG,
  //                              SmallVectorImpl<SDValue> &InVals) const override;

  SDValue LowerReturn(SDValue Chain, CallingConv::ID CallConv, bool isVarArg,
                      const SmallVectorImpl<ISD::OutputArg> &Outs,
                      const SmallVectorImpl<SDValue> &OutVals, const SDLoc &dl,
                      SelectionDAG &DAG) const override;

  // SDValue LowerCall(TargetLowering::CallLoweringInfo &CLI,
  //                   SmallVectorImpl<SDValue> &InVals) const override;

  // const char *getTargetNodeName(unsigned Opcode) const override;
};
} // namespace llvm

#endif
