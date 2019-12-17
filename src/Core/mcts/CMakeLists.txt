add_library(mcts MCTSBase.cpp UCT.cpp MCTSInterface.cpp MCTSEntry.cpp)

target_include_directories(mcts
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        )

target_link_libraries(mcts Environment Core tree_policy default_policy backpropagation)

install(FILES include/MCTSEntry.h include/UCT.h DESTINATION include/)
