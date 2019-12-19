target_sources(MCTS
    PRIVATE
      Runner.cpp
      RunnerTicTacToe.cpp
)

target_include_directories(MCTS
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
