add_library(DefaultPolicy DefaultPolicyBase.cpp RandomSamplingDefaultPolicy.cpp TicTacToeDefaultPolicy.cpp)

target_include_directories(DefaultPolicy
    PUBLIC
      $<INSTALL_INTERFACE:include>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(DefaultPolicy
    PUBLIC
      Environment
)