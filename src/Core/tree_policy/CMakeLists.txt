target_sources(MCTS
    PRIVATE
      TreePolicyBase.cpp
      UCT_TreePolicy.cpp
)

target_include_directories(MCTS
    PUBLIC
      $<INSTALL_INTERFACE:include>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}      
)

add_to_PUBLIC_HEADER(MCTS 
  src/Core/tree_policy/include/TreePolicyBase.h
  src/Core/tree_policy/include/UCT_TreePolicy.h)