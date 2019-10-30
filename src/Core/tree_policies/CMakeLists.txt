add_library(tree_policies TreePolicyBase.cpp UCT_TreePolicy.cpp)

target_include_directories(tree_policies
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${Boost_INCLUDE_DIRS}
        )

target_link_libraries(tree_policies Core)
