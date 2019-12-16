add_library(default_policy DefaultPolicyBase.cpp RandomSamplingDefaultPolicy.cpp TicTacToeDefaultPolicy.cpp)

target_include_directories(default_policy
    PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(default_policy Core Environment)