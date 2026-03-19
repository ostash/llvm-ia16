//===-- IA16InstPrinter.cpp - Convert IA16 MCInst to asm syntax -----------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#include "MCTargetDesc/IA16InstPrinter.h"

#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInst.h"

namespace llvm {

// Include the tblgen-generated portion of the assembly writer.
// TODO: define PRINT_ALIAS_INSTR?
#include "IA16GenAsmWriter.inc"

void IA16InstPrinter::printOperand(const MCInst *MI, unsigned OpNo,
                                   raw_ostream &O) {
  // TODO: X86 also handles immediate via direct print and expression via
  // MAI.printExpr()
  const MCOperand &Op = MI->getOperand(OpNo);
  if (Op.isReg()) {
    O << getRegisterName(Op.getReg());
  } else {
    // TODO: this should be removed when we are sure that all operand types are
    // supported
    Op.print(O);
    llvm_unreachable("Unknown operand");
  }
}

void IA16InstPrinter::printInst(const MCInst *MI, uint64_t Address,
                                StringRef Annot, const MCSubtargetInfo &STI,
                                raw_ostream &O) {
  printInstruction(MI, Address, O);
  printAnnotation(O, Annot);
}

} // namespace llvm