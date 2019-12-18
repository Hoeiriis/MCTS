add_library(Environment OBJECT EnvironmentInterface.cpp State.cpp TicTacToeEnvironment.cpp)

target_include_directories(Environment
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(Environment PRIVATE cxx_std_17)