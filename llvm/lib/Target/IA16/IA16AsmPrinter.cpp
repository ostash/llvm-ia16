//===-- IA16AsmPrinter.cpp - IA16 LLVM assembly writer --------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains a printer that converts from our internal representation
// of machine-dependent LLVM code to the IA-16 assembly language.
//
//===----------------------------------------------------------------------===//

#include "IA16.h"
#include "IA16TargetMachine.h"
#include "TargetInfo/IA16TargetInfo.h"
#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define DEBUG_TYPE "asm-printer"

namespace {
class IA16AsmPrinter : public AsmPrinter {
public:
  explicit IA16AsmPrinter(TargetMachine &TM,
                          std::unique_ptr<MCStreamer> Streamer)
      : AsmPrinter(TM, std::move(Streamer)) {}

  StringRef getPassName() const override { return "IA16 Assembly Printer"; }

  void emitInstruction(const MachineInstr *MI) override;
};
} // namespace

void IA16AsmPrinter::emitInstruction(const MachineInstr *MI) {
  MCInst TmpInst;
  TmpInst.setOpcode(MI->getOpcode());

  for (const MachineOperand &MO : MI->operands()) {
    if (MO.isReg()) {
      TmpInst.addOperand(MCOperand::createReg(MO.getReg()));
    } else if (MO.isImm()) {
      TmpInst.addOperand(MCOperand::createImm(MO.getImm()));
    } else {
      llvm_unreachable("Operand type not supported yet");
    }
  }

  EmitToStreamer(*OutStreamer, TmpInst);
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeIA16AsmPrinter() {
  RegisterAsmPrinter<IA16AsmPrinter> X(getTheIA16Target());
}
