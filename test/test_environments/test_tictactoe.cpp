#include <TicTacToeEnvironment.h>
#include <gtest/gtest.h>

TEST(GetStartState, BoardSizeIsCorrect) {
    TicTacToeEnv env;

    std::vector<BoardPiece> start_state = env.GetStartState().getData<BoardState>();

    EXPECT_EQ(start_state.size(), 9);
}

TEST(GetStartState, InitialBoardStateIsCorrect) {
    TicTacToeEnv env;

    std::vector<BoardPiece> start_state = env.GetStartState().getData<BoardState>();

    for (auto &board_piece : start_state) {
        EXPECT_EQ(board_piece, None);
    }
}

TEST(EvaluateTerminalState, TerminalStatesAreTerminal) {
    TicTacToeEnv env;
    std::vector<BoardPiece> players = {Cross, Circle};

    for (auto &player : players) {
        Reward expected = (player == Cross) ? 1 : -1;
        for (auto &indices : TicTacToeWinConditions) {
            BoardState start_state = env.GetStartState().getData<BoardState>();
            int i1 = indices[0];
            int i2 = indices[1];
            int i3 = indices[2];

            start_state[i1] = start_state[i2] = start_state[i3] = player;

            State terminal_state(start_state);

            EXPECT_DOUBLE_EQ(env.EvaluateTerminalState(terminal_state), expected);
        }
    }
}

TEST(GetValidChildStates, NoValidChildStatesFromTerminalStateS) {
    TicTacToeEnv env;
    std::vector<BoardPiece> players = {Cross, Circle};

    for (auto &player : players) {
        Reward expected = (player == Cross) ? 1 : -1;
        for (auto &indices : TicTacToeWinConditions) {
            BoardState start_state = env.GetStartState().getData<BoardState>();
            int i1 = indices[0];
            int i2 = indices[1];
            int i3 = indices[2];

            start_state[i1] = start_state[i2] = start_state[i3] = player;

            State terminal_state(start_state);

            std::vector<State> child_states = env.GetValidChildStates(terminal_state);
            EXPECT_EQ(child_states.size(), 0);
        }
    }
}

TEST(EvaluateTerminalState, NonterminalStatesNotTerminal) {
    TicTacToeEnv env;
    std::vector<std::vector<BoardPiece>> nonterminal_states = {
        {None, None, None, None, None, None, None, None},
        {Circle, Cross, Circle, Cross, Cross, Circle, Circle, Circle, Cross},
        {Circle, None, Circle, Cross, None, Cross, Circle, None, Cross}};

    for (auto &state : nonterminal_states) {
        State board_state(state);
        EXPECT_DOUBLE_EQ(env.EvaluateTerminalState(board_state), 0);
    }
}

TEST(GetValidChildStates, CorrectNumberOfChildStates){
    TicTacToeEnv env;
    State parent_state = env.GetStartState();

    while (env.EvaluateTerminalState(parent_state)){
    // for (int i = 0; i < 100; i++){
        int occupied_spots = 0;
        for(auto& grid : parent_state.getData<BoardState>()){
            occupied_spots += grid > 0;
        }
        int expected_child_states = 9 - occupied_spots;

        std::vector<State> child_states = env.GetValidChildStates(parent_state);
        EXPECT_EQ(expected_child_states, child_states.size());

        parent_state = child_states[0];
    }

}
