add_library(Environment EnvironmentBase.cpp)

target_include_directories(Environment
  PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
  )

add_library(TicTacToe TicTacToeEnvironment.cpp)
target_link_libraries(TicTacToe Environment)
target_include_directories(TicTacToe
  PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
  )

  target_link_libraries(Environment Core)