target_sources(MCTS
    PRIVATE
      SearchNode.cpp
)

target_include_directories(MCTS
    PUBLIC
      $<INSTALL_INTERFACE:include>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}
)

add_subdirectory(tree_policy)
add_subdirectory(mcts)
add_subdirectory(default_policy)
add_subdirectory(backpropagation)
add_subdirectory(runner)
add_subdirectory(mcts)