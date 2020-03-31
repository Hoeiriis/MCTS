add_library(mctsAlg_objLib OBJECT)
target_sources(mctsAlg_objLib
    PRIVATE
      MCTSBase.cpp
      UCT.cpp
      MCTSInterface.cpp
)

Set_Multiple_PUBLIC_HEADER(mctsAlg_objLib
  ${CMAKE_CURRENT_SOURCE_DIR}/include/MCTSBase.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/UCT.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/MCTSInterface.h)

target_include_directories(mctsAlg_objLib
    PUBLIC
      $<INSTALL_INTERFACE:include>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)


  target_link_libraries(mctsAlg_objLib
        PRIVATE
          environments_objLib
          defaultpolicy_objLib
          treepolicy_objLib
          backpropagation_objLib
          common_objLib)
