//===-- IA16CallingConv.td - Calling Conventions for IA16 -*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
// This describes the calling conventions for IA16 architecture.
//===----------------------------------------------------------------------===//

def CSR_All : CalleeSavedRegs<(add AX)>;

// Minimal calling convention: pass arguments in AX, BX, CX, DX
def CC_IA16 : CallingConv<[
  CCIfType<[i16], CCAssignToReg<[AX]>>,
  // If we run out of registers, use stack.
  CCIfType<[i16], CCAssignToStack<2, 2>>
]>;

def RetCC_IA16 : CallingConv<[
  CCIfType<[i16], CCAssignToReg<[AX]>> // Return in AX
]>;
