#include <TicTacToeEnvironment.h>
#include <iostream>

TicTacToeEnv::TicTacToeEnv() {}

State TicTacToeEnv::GetStartState() {
    BoardState state = {None, None, None,
                        None, None, None,
                        None, None, None};
    State result = State(state);

    return result;
}

std::vector<State> TicTacToeEnv::GetValidChildStates(State &state) {

    BoardState bState = state.getData<BoardState>();
    std::vector<State> result;

    // Check if this state is terminal
    if(EvaluateTerminalState(state) != 0){
        return result;
    }

    int board_pieces = 0;
    int player_turn;
    for (BoardPiece symbol : bState) {
        board_pieces += symbol > 0;
    }
    // Player 1 if an even number of pieces is on the board
    // Otherwise player 2
    player_turn = board_pieces % 2;
    BoardPiece piece = player_turn ? Circle : Cross;


    for (int i = 0; i < bState.size(); i++) {
        if (bState[i] == None) {

            BoardState boardState(bState);
            boardState[i] = piece;
            State childState(boardState);
            result.push_back(childState);
        }
    }

    return result;
}

Reward TicTacToeEnv::EvaluateTerminalState(State &state) {
    /*
      Return 1 if player one has won;
      Return -1 if player two has won;
      Return 0 otherwise
    */
    BoardState bstate = state.getData<BoardState>();
    Reward reward = 0;

    for (auto &condition : TicTacToeWinConditions) {
        int i1, i2, i3;
        i1 = condition[0];
        i2 = condition[1];
        i3 = condition[2];

        if (bstate[i1] == bstate[i2] && bstate[i1] == bstate[i3] && bstate[i1] != None) {
            return bstate[i1] == Cross ? 1 : -1;
        }
    }

    return reward;
}

void TicTacToeEnv::PrintBoard(State &state) {
    BoardState bstate = state.getData<BoardState>();

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int index = i * 3 + j;
            BoardPiece symbol = bstate[index];
            std::cout << (symbol == None ? " u " : (symbol == Cross ? " X " : " O "));
        }
        std::cout << "\n";
    }
}
