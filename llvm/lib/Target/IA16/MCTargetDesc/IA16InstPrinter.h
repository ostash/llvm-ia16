//===- IA16InstPrinter.h - Convert IA16 MCInst to assembly syntax -*- C++
//-*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#ifndef LLVM_LIB_TARGET_IA16_INSTPRINTER_IA16INSTPRINTER_H
#define LLVM_LIB_TARGET_IA16_INSTPRINTER_IA16INSTPRINTER_H

#include "llvm/MC/MCInstPrinter.h"

namespace llvm {

class IA16InstPrinter final : public MCInstPrinter {
public:
  IA16InstPrinter(const MCAsmInfo &MAI, const MCInstrInfo &MII,
                  const MCRegisterInfo &MRI)
      : MCInstPrinter(MAI, MII, MRI) {}

  ~IA16InstPrinter() final;

  std::pair<const char *, uint64_t> getMnemonic(const MCInst &MI) const final;

  void printInst(const MCInst *MI, uint64_t Address, StringRef Annot,
                 const MCSubtargetInfo &STI, raw_ostream &OS) final;
};

} // namespace llvm

#endif