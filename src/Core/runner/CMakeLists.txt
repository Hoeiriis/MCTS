add_library(runner_objLib OBJECT)
target_sources(runner_objLib
    PRIVATE
      Runner.cpp
      RunnerTicTacToe.cpp
)

target_include_directories(runner_objLib
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

Set_Multiple_PUBLIC_HEADER(runner_objLib
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Runner.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/RunnerTicTacToe.h)


target_link_libraries(runner_objLib
    PRIVATE
      common_objLib
      mctsAlg_objLib)