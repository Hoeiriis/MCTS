# Creating object library
add_library(treepolicy_objLib OBJECT)
target_sources(treepolicy_objLib
      PRIVATE
        TreePolicyBase.cpp
        UCT_TreePolicy.cpp)

# Setting PUBLIC_HEADER because of project structure        
Set_Multiple_PUBLIC_HEADER(treepolicy_objLib
    ${CMAKE_CURRENT_SOURCE_DIR}/include/TreePolicyBase.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/UCT_TreePolicy.h)

# Set include dirs
target_include_directories(treepolicy_objLib
      PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

# Depends on SearchNode.h which is part of common        
target_link_libraries(treepolicy_objLib PRIVATE common_objLib)