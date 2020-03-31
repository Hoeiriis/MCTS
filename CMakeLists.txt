cmake_minimum_required(VERSION 3.12...3.13)
project(MCTS 
        VERSION 0.1.0
        LANGUAGES "CXX"
        DESCRIPTION "A Monte Carlo Tree Search library.")

set( CMAKE_POSITION_INDEPENDENT_CODE ON )
############################################
# Cmake commands only enabled when developing 
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME) AND MCTS_Executable)

  message("Setting local variables")
  set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
  set(OUTPUT_DIR "${PROJECT_SOURCE_DIR}/build")
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}/bin)
  set(EXTERNAL_INSTALL_LOCATION "${PROJECT_ROOT}/ExternalLibs")
  set(PREFIX_LOCATION "${PROJECT_ROOT}/.prefixes")

  message(STATUS "Prefix=${PREFIX_LOCATION}")

  # Build doxygen documentation if possible 
  find_package(Doxygen)
  if(DOXYGEN_FOUND AND DOXYGEN_DOT_FOUND)
    set(DOC_OUTPUT_DIR "${PROJECT_ROOT}/doc")

    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
                  ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

    add_custom_target(doc ${DOXYGEN_EXECUTABLE}
                      ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
                      WORKING_DIRECTORY ${PROJECT_ROOT}
                      COMMENT "Generating API documentation with Doxygen"
                      VERBATIM)
  endif(DOXYGEN_FOUND AND DOXYGEN_DOT_FOUND)

endif()

############################################
# Macros
macro(Set_Multiple_PUBLIC_HEADER TARGET)
  #set_target_properties(${TARGET} PROPERTIES PUBLIC_HEADER "")
  #get_target_property(current_public_headers ${TARGET} PUBLIC_HEADER)
  set_target_properties(${TARGET} PROPERTIES PUBLIC_HEADER "${current_public_headers};${ARGN}")  
endmacro()

############################################
# Dependencies

############################################
# Library target
add_library(MCTS)
add_subdirectory(src/Environments)
add_library(MCTS::Environments ALIAS Environments)

add_subdirectory(src/Core)
add_library(MCTS::Core ALIAS Core)


target_link_libraries(MCTS
     PUBLIC
      MCTS::Environments
      MCTS::Core)
      

target_compile_features(MCTS PRIVATE cxx_auto_type)
target_compile_options(MCTS PRIVATE $<$<CXX_COMPILER_ID:GNU>:-Wall>)

############################################
# Installation instructions

message(STATUS "include dir ${CMAKE_INTALL_INCLUDEDIR}")

include(GNUInstallDirs)
install(
  TARGETS
    MCTS
    Environments
    environments_objLib
    Core
    treepolicy_objLib
    common_objLib
    mctsAlg_objLib
    runner_objLib
    defaultpolicy_objLib
    backpropagation_objLib
  EXPORT MCTSTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT MCTSTargets
  FILE MCTSTargets.cmake
  NAMESPACE MCTS::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MCTS
)

#Create a ConfigVersion.cmake file for helping to find version
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/MCTSConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

# configure and install config, configversion
#configure_package_config_file(
#    ${CMAKE_CURRENT_LIST_DIR}/cmake/MCTSConfig.cmake.in
#    ${CMAKE_CURRENT_BINARY_DIR}/MCTSConfig.cmake
#    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MCTS
#)
configure_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/MCTSConfig.cmake.in
    MCTSConfig.cmake
    @ONLY)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/MCTSConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/MCTSConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MCTS
)

#################################################
# Exporting package to be found with find_package() by other CMake projects 
export(EXPORT MCTSTargets
      NAMESPACE MCTS::
      FILE ${CMAKE_CURRENT_BINARY_DIR}/MCTSTargets.cmake)
set(CMAKE_EXPORT_PACKAGE_REGISTRY ON)
export(PACKAGE MCTS)


if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME) AND MCTS_Executable)
  # Testing
  if(NOT "${TESTING}" STREQUAL "NO")
    message("Testing is ENABLED")
    set(TESTING YES)
  else()
    message("Testing is DISABLED")
  endif()

  if("${TESTING}" STREQUAL "YES")
    enable_testing()
    add_subdirectory(test)
  endif()
endif()
