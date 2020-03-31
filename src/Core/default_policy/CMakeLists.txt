add_library(defaultpolicy_objLib OBJECT)

target_include_directories(defaultpolicy_objLib
    PUBLIC
      $<INSTALL_INTERFACE:include>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_sources(defaultpolicy_objLib
      PRIVATE
        DefaultPolicyBase.cpp
        RandomSamplingDefaultPolicy.cpp
        TicTacToeDefaultPolicy.cpp)

Set_Multiple_PUBLIC_HEADER(defaultpolicy_objLib
        ${CMAKE_CURRENT_SOURCE_DIR}/include/DefaultPolicyBase.h 
        ${CMAKE_CURRENT_SOURCE_DIR}/include/RandomSamplingDefaultPolicy.h 
        ${CMAKE_CURRENT_SOURCE_DIR}/include/TicTacToeDefaultPolicy.h)

target_link_libraries(defaultpolicy_objLib
      PRIVATE
        common_objLib) 
