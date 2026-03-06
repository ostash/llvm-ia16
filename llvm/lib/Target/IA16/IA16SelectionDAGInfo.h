//===-- IA16SelectionDAGInfo.h - IA16 SelectionDAG Info -----------*- C++
//-*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the IA16 subclass for SelectionDAGTargetInfo.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_IA16_IA16SELECTIONDAGINFO_H
#define LLVM_LIB_TARGET_IA16_IA16SELECTIONDAGINFO_H

#include "llvm/CodeGen/SelectionDAGTargetInfo.h"

namespace llvm {

class IA16SelectionDAGInfo : public SelectionDAGGenTargetInfo {
public:
  IA16SelectionDAGInfo();

  ~IA16SelectionDAGInfo() override;

  void verifyTargetNode(const SelectionDAG &DAG,
                        const SDNode *N) const override;
};

} // namespace llvm

#endif
