add_library(runner Runner.cpp RunnerTicTacToe.cpp )

target_include_directories(runner
    PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(runner mcts Environment Core tree_policies DefaultPolicy backpropagation)