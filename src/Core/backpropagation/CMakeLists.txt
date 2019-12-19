target_sources(MCTS
    PRIVATE
      BackupBase.cpp
      BasicBackup.cpp
      BackupNegamax.cpp
)

target_include_directories(MCTS
    PUBLIC
      $<INSTALL_INTERFACE:include>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}
)

add_to_PUBLIC_HEADER(MCTS 
  src/Core/backpropagation/include/BackupBase.h
  src/Core/backpropagation/include/BasicBackup.h 
  src/Core/backpropagation/include/BackupNegamax.h)