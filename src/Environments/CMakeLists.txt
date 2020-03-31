# Obejct library, which can be used as dependency in several
# libraries but only recompiling once if necessary
add_library(environments_objLib OBJECT)
target_sources(environments_objLib
      PRIVATE
        EnvironmentInterface.cpp
        State.cpp
        TicTacToeEnvironment.cpp
      PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/State.h>
        $<INSTALL_INTERFACE:include>)

# We need to set PUBLIC_HEADER for the target because of our project structure
Set_Multiple_PUBLIC_HEADER(environments_objLib
        ${CMAKE_CURRENT_SOURCE_DIR}/include/EnvironmentInterface.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/State.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/State.tcc
        ${CMAKE_CURRENT_SOURCE_DIR}/include/TicTacToeEnvironment.h)
        

# Required include search-paths and compile features
target_include_directories(environments_objLib
      PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_compile_features(environments_objLib
      PUBLIC
        cxx_std_17)

# A shared library for Environments functionality
add_library(Environments STATIC)
target_link_libraries(Environments PUBLIC environments_objLib)