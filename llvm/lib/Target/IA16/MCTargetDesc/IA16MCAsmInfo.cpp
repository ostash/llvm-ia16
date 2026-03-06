//===-- IA16MCAsmInfo.cpp - IA16 asm properties ---------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the declarations of the IA16MCAsmInfo properties.
//
//===----------------------------------------------------------------------===//

#include "IA16MCAsmInfo.h"

using namespace llvm;

IA16MCAsmInfo::IA16MCAsmInfo(const Triple &TT) {
  CodePointerSize = 2;
  CalleeSaveStackSlotSize = 2;
  IsLittleEndian = true;
  CommentString = ";";
}
