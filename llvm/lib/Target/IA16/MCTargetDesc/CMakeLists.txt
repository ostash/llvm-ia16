add_llvm_component_library(LLVMIA16Desc
  IA16InstPrinter.cpp
  IA16MCTargetDesc.cpp
#  IA16MCAsmInfo.cpp

  LINK_COMPONENTS
  MC
  Support
  IA16Info

  ADD_TO_COMPONENT
  IA16
  )
