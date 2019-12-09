add_library(mcts MCTSCustom.cpp MCTSBase.cpp UCT.cpp MCTSInterface.cpp UCT_two_players.cpp) 

target_include_directories(mcts
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        )

target_link_libraries(mcts Environment Core tree_policies DefaultPolicy backpropagation)
