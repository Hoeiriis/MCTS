target_sources(MCTS
    PRIVATE
      DefaultPolicyBase.cpp
      RandomSamplingDefaultPolicy.cpp
      UPPAAL_RandomSamplingDefaultPolicy.cpp
      TicTacToeDefaultPolicy.cpp
)

target_include_directories(MCTS
    PUBLIC
      $<INSTALL_INTERFACE:include>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}
)

add_to_PUBLIC_HEADER(MCTS 
  src/Core/default_policy/include/DefaultPolicyBase.h 
  src/Core/default_policy/include/RandomSamplingDefaultPolicy.h 
  src/Core/default_policy/include/UPPAAL_RandomSamplingDefaultPolicy.h
  src/Core/default_policy/include/TicTacToeDefaultPolicy.h)