add_llvm_component_library(LLVMIA16Info
  IA16TargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  IA16
  )
