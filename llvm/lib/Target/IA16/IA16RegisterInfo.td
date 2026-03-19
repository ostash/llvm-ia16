//===-- IA16RegisterInfo.td - IA16 Register defs ----------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Declarations that describe the IA16 register file
//===----------------------------------------------------------------------===//

//class IA16Reg<bits<16> Enc, string n> : Register<n> {
//  let HWEncoding = Enc;
//  let Namespace = "IA16";
//}

// TODO: Registers parameters to check:
// Namespace
// AsmName
// AltNames
// Aliases
// SubRegs
// SubRegIndices
// RegAltNameIndices
// DwarfNumbers
// CostPerUse
// CoveredBySubRegs
// HWEncoding
// isArtificial
// isConstant
// PositionOrder

def AX : Register<"ax"> { let Namespace = "IA16"; }

// 16-bit registers
//def AX : IA16Reg<0, "ax">;
//def BX : IA16Reg<1, "bx">;
//def CX : IA16Reg<2, "cx">;
//def DX : IA16Reg<3, "dx">;

// TODO: Register classes parameters to check:
// Namespace
// RegInfos
// RegTypes
// Size
// Alignment
// CopyCost
// MemberList
// AltNameIndex
// isAllocatable
// AltOrders
// AltOrderSelect
// AllocationPriority
// GlobalPriority
// GeneratePressureSet
// Weight
// DiagnosticType
// DiagnosticString
// TSFlags
// BaseClassOrder

// Register classes 
// def <name> : RegisterClass<string namespace, list<ValueType> regTypes, int alignment,
//                            dag regList, RegAltNameIndex idx = NoRegAltName>  
def GR16 : RegisterClass<"IA16", [i16], 16, (add AX)>;
