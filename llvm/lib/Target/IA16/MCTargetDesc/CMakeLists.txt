add_llvm_component_library(LLVMIA16Desc
  IA16InstPrinter.cpp
  IA16MCTargetDesc.cpp

  LINK_COMPONENTS
  IA16Info
  MC
  Support

  ADD_TO_COMPONENT
  IA16
  )
