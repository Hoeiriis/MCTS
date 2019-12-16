add_library(tree_policy TreePolicyBase.cpp UCT_TreePolicy.cpp)

target_include_directories(tree_policy
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${Boost_INCLUDE_DIRS}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}      
        )

target_link_libraries(tree_policy Core)
