add_library(Core SearchNode.cpp State.cpp )

target_include_directories(Core
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        )

add_subdirectory(tree_policies)
add_subdirectory(mcts)