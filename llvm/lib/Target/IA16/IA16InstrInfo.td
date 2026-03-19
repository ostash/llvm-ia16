//===-- IA16InstrInfo.td - Target Description for IA16 ---*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file describes the IA16 instructions in TableGen format.
//
//===----------------------------------------------------------------------===//

//def MemOperand : Operand<i16> {
//  let PrintMethod = "printMemOperand";
//  let MIOperandInfo = (ops GR16, i16imm);
//}

// Memory mapping patterns for DAG Selector:
//def addr : ComplexPattern<i16, 2, "SelectAddr", [], []>;

// IA16 Specific Node Definitions
//def SDTIA16Ret : SDTypeProfile<0, 1, [SDTCisVT<0, i16>]>;

//def IA16retflag : SDNode<"IA16ISD::RET_FLAG", SDTIA16Ret,
//                         [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

// mov reg, imm
//def MOV16ri : IA16Inst<(outs GR16:$dst), (ins i16imm:$src),
//                       "mov\t$dst, $src",
//                       [(set i16:$dst, imm:$src)]>;

def MOV16ri : Instruction { let Namespace = "IA16"; let OutOperandList = (outs GR16:$dst); let InOperandList = (ins i16imm:$src); 
 let Pattern = [(set i16:$dst, imm:$src)]; let AsmString = "mov $dst, $src"; }

// mov reg, reg
//def MOV16rr : IA16Inst<(outs GR16:$dst), (ins GR16:$src),
//                       "mov\t$dst, $src",
//                       []> {
//  let isMoveReg = 1;
//}

// mov reg, mem
//def MOV16rm : IA16Inst<(outs GR16:$dst), (ins MemOperand:$src),
//                       "mov\t$dst, $src",
//                       [(set i16:$dst, (load addr:$src))]> {
//  let canFoldAsLoad = 1;
//}

// mov mem, reg
//def MOV16mr : IA16Inst<(outs), (ins MemOperand:$dst, GR16:$src),
//                       "mov\t$dst, $src",
//                       [(store i16:$src, addr:$dst)]>;

// add reg, reg
// Note: typically add sets flags, but for minimal viable we just do add
//def ADD16rr : IA16Inst<(outs GR16:$dst), (ins GR16:$src1, GR16:$src2),
//                       "add\t$dst, $src2",
//                       [(set i16:$dst, (add i16:$src1, i16:$src2))]> {
//  let isAdd = 1;
//  let Constraints = "$src1 = $dst"; // Two-address instruction
//}

//let isReturn = 1, isTerminator = 1, isBarrier = 1 in
//  def RET : IA16Inst<(outs), (ins), "ret", [(IA16retflag (i16 0))]>;


def IA16retglue      : SDNode<"IA16ISD::RET_GLUE", SDTNone,
                             [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;
def RET : Instruction { let isReturn = 1; let Namespace = "IA16"; let OutOperandList = (outs); let InOperandList = (ins);
 let Pattern = [(IA16retglue)]; let AsmString = "ret";  }

// MOV reg, mem
// MOV mem, reg
// ADD reg, reg