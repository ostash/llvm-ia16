add_llvm_component_library(LLVMIA16Desc
  IA16InstPrinter.cpp
  IA16MCAsmInfo.cpp
  IA16MCTargetDesc.cpp

  LINK_COMPONENTS
  MC
  Support
  TargetParser
  IA16Info

  ADD_TO_COMPONENT
  IA16
  )
