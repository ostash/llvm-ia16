//===-- IA16SelectionDAGInfo.cpp - IA16 SelectionDAG Info -----------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the IA16SelectionDAGInfo class.
//
//===----------------------------------------------------------------------===//

#include "IA16SelectionDAGInfo.h"
#include "IA16TargetMachine.h"
#include "llvm/CodeGen/SelectionDAG.h"

#define GET_SDNODE_DESC
#include "IA16GenSDNodeInfo.inc"

using namespace llvm;

IA16SelectionDAGInfo::IA16SelectionDAGInfo()
    : SelectionDAGGenTargetInfo(IA16GenSDNodeInfo) {}

IA16SelectionDAGInfo::~IA16SelectionDAGInfo() {}

#if !defined(NDEBUG) || defined(LLVM_ENABLE_DUMP)
void IA16SelectionDAGInfo::verifyTargetNode(const SelectionDAG &DAG,
                                            const SDNode *N) const {
  SelectionDAGGenTargetInfo::verifyTargetNode(DAG, N);
}
#endif
