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

add_to_PUBLIC_HEADER(MCTS src/Core/runner/include/Runner.h src/Core/runner/include/RunnerTicTacToe.h)