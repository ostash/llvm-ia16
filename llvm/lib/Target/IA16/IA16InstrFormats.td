//===-- IA16InstrFormats.td - IA16 Instruction Formats ---*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

class IA16Inst<dag outs, dag ins, string asmstr, list<dag> pattern>
  : Instruction {
  let Namespace = "IA16";
  let OutOperandList = outs;
  let InOperandList = ins;
  let AsmString = asmstr;
  let Pattern = pattern;
  let Size = 2; // Fixed pseudo size for now
}
