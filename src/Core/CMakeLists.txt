add_library(Core SearchNode.cpp)

target_include_directories(Core
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        )

target_link_libraries(Core Environment)
add_subdirectory(tree_policies)
add_subdirectory(mcts)
add_subdirectory(DefaultPolicy)
add_subdirectory(backpropagation)
add_subdirectory(runner)
