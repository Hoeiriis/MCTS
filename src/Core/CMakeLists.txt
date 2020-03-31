#first make libraries at this level
add_library(common_objLib OBJECT)
target_sources(common_objLib
      PRIVATE
        SearchNode.cpp)

Set_Multiple_PUBLIC_HEADER(common_objLib
      ${CMAKE_CURRENT_SOURCE_DIR}/include/SearchNode.h)

target_include_directories(common_objLib
      PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_link_libraries(common_objLib PUBLIC environments_objLib)


# Add sublevel stuff and the Core Library
add_subdirectory(tree_policy)
add_subdirectory(backpropagation)
add_subdirectory(mcts)
add_subdirectory(runner)
add_subdirectory(default_policy)


add_library(Core STATIC)
target_link_libraries(Core
      PUBLIC
        common_objLib
        treepolicy_objLib
        mctsAlg_objLib
        runner_objLib
        defaultpolicy_objLib
        backpropagation_objLib)