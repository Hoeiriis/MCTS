target_sources(MCTS
    PRIVATE
      MCTSBase.cpp
      MCTSEntry.cpp
      UCT.cpp
      MCTSInterface.cpp
)

target_include_directories(MCTS
    PUBLIC
      $<INSTALL_INTERFACE:include>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}
)

add_to_PUBLIC_HEADER(MCTS 
  src/Core/mcts/include/MCTSBase.h
  src/Core/mcts/include/MCTSEntry.h
  src/Core/mcts/include/UCT.h
  src/Core/mcts/include/MCTSInterface.h
)