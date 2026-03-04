//===- IA16AsmPrinter.cpp - IA16 LLVM assembly writer -----------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#include "TargetInfo/IA16TargetInfo.h"
#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/TargetRegistry.h"

namespace llvm {

class IA16AsmPrinter : public AsmPrinter
{
public:
  IA16AsmPrinter(TargetMachine &TM, std::unique_ptr<MCStreamer> Streamer) :
    AsmPrinter(TM, std::move(Streamer))
    {}
};

static AsmPrinter *
createIA16AsmPrinter(TargetMachine &TM,
                     std::unique_ptr<MCStreamer> &&Streamer) {
    return new IA16AsmPrinter(TM, std::move(Streamer));
                     }
} // namespace llvm

// Force static initialization.
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeIA16AsmPrinter() {
  llvm::TargetRegistry::RegisterAsmPrinter(llvm::getTheIA16Target(),
                                           &llvm::createIA16AsmPrinter);
}
