//===- IA16InstPrinter.cpp - IA16 MCInst to assembly syntax -----*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#include "IA16InstPrinter.h"
#include "llvm/Support/DOTGraphTraits.h"

namespace llvm {

IA16InstPrinter::~IA16InstPrinter() = default;

std::pair<const char *, uint64_t>
IA16InstPrinter::getMnemonic(const MCInst &MI) const {
  return {"mnem", 0};
}

void IA16InstPrinter::printInst(const MCInst *MI, uint64_t Address,
                                StringRef Annot, const MCSubtargetInfo &STI,
                                raw_ostream &OS) {
  OS << "someinst";
}

} // namespace llvm