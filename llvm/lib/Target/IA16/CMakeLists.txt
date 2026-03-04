add_llvm_component_group(IA16)

add_llvm_target(IA16CodeGen
  IA16AsmPrinter.cpp
  IA16TargetMachine.cpp

  LINK_COMPONENTS
#  ARCDesc
  IA16Info
#  Analysis
  AsmPrinter
  CodeGen
#  CodeGenTypes
  Core
#  MC
#  SelectionDAG
  Support
  Target
#  TargetParser
#  TransformUtils

  ADD_TO_COMPONENT
  IA16
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
