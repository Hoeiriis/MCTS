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