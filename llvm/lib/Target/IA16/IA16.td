//===-- IA16.td - Describe the IA16 Target Machine ---------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This is the top level entry point for the IA16 target.
//
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

include "IA16RegisterInfo.td"
//include "IA16InstrFormats.td"
include "IA16InstrInfo.td"
include "IA16CallingConv.td"

def IA16InstrInfo : InstrInfo;

// class Proc<string Name, list<SubtargetFeature> Features>
// : Processor<Name, NoItineraries, Features>;

// def : Proc<"generic", []>;

def : Processor<"generic", NoItineraries, []>;

defm : RemapAllTargetPseudoPointerOperands<GR16>;

def IA16 : Target {
  let InstructionSet = IA16InstrInfo;
}
