//===-- IA16MCAsmInfo.h - IA16 asm properties ------------------*- C++ -*--===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the declaration of the IA16MCAsmInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_IA16_MCTARGETDESC_IA16MCASMINFO_H
#define LLVM_LIB_TARGET_IA16_MCTARGETDESC_IA16MCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {
class Triple;

class IA16MCAsmInfo : public MCAsmInfoELF {
public:
  explicit IA16MCAsmInfo(const Triple &TT);
};

} // namespace llvm

#endif
