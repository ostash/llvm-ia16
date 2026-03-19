add_llvm_component_group(IA16)

set(LLVM_TARGET_DEFINITIONS IA16.td)

tablegen(LLVM IA16GenRegisterInfo.inc -gen-register-info)
tablegen(LLVM IA16GenInstrInfo.inc -gen-instr-info)
tablegen(LLVM IA16GenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM IA16GenCallingConv.inc -gen-callingconv)
tablegen(LLVM IA16GenDAGISel.inc -gen-dag-isel)
tablegen(LLVM IA16GenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM IA16GenSDNodeInfo.inc -gen-sd-node-info)

add_public_tablegen_target(IA16CommonTableGen)

#  IA16SelectionDAGInfo.cpp
add_llvm_target(IA16CodeGen
  IA16AsmPrinter.cpp
  IA16FrameLowering.cpp
  IA16InstrInfo.cpp
  IA16ISelDAGToDAG.cpp
  IA16ISelLowering.cpp
  IA16RegisterInfo.cpp
  IA16Subtarget.cpp
  IA16TargetMachine.cpp

  LINK_COMPONENTS
  Analysis
  AsmPrinter
  CodeGen
  CodeGenTypes
  Core
  IA16Desc
  IA16Info
  MC
  SelectionDAG
  Support
  Target
  TargetParser

  ADD_TO_COMPONENT
  IA16

  DEPENDS
  intrinsics_gen
  )

add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
