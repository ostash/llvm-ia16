//===-- IA16MCTargetDesc.h - IA16 Target Descriptions --------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file provides IA16 specific target descriptions.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_IA16_MCTARGETDESC_IA16MCTARGETDESC_H
#define LLVM_LIB_TARGET_IA16_MCTARGETDESC_IA16MCTARGETDESC_H

#include "llvm/Support/DataTypes.h"

namespace llvm {
class Target;

Target &getTheIA16Target();

} // namespace llvm

#define GET_REGINFO_ENUM
#include "IA16GenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#define GET_INSTRINFO_MC_HELPER_DECLS
#include "IA16GenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "IA16GenSubtargetInfo.inc"

#endif
