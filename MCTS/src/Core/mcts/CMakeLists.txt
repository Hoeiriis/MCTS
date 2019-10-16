add_library(mcts MCTSBase.cpp UCT.cpp)

target_include_directories(mcts
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${Boost_INCLUDE_DIRS}
        )
target_link_libraries(mcts Environment Core)
