#include <TicTacToeEnvironment.h>

TicTacToeEnv::TicTacToeEnv() {}

std::vector<std::vector<int>> WinConditions = {
                                               {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // rows
                                               {0, 3, 6}, {1, 4, 6}, {2, 5, 8}, // columns
                                               {0, 4, 8}, {2, 4, 6}};           // diagonals

State TicTacToeEnv::GetStartState() {
  BoardState state(9, None);
  TicTacToeState result = TicTacToeState(state);

  return result;
}

std::vector<State> TicTacToeEnv::GetValidChildStates(State &state) {
  TicTacToeState tttstate = (TicTacToeState&)state;
  BoardState bState = tttstate.data;
  std::vector<State> result;
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

      BoardState childState(bState);
      childState[i] = piece;
      result.push_back(TicTacToeState(childState));
    }
  }

  return result;
}

Reward TicTacToeEnv::EvaluateTerminalState(TicTacToeState &tttstate) {
  /*
    Return 1 if player one has won;
    Return -1 if player two has won;
    Return 0 otherwise
  */
  BoardState state = tttstate.state;
  Reward reward = 0;

  for (auto &condition : WinConditions) {
    int i1, i2, i3;
    i1 = condition[0];
    i2 = condition[1];
    i3 = condition[2];

    if (state[i1] == state[i2] && state[i1] == state[i3] && state[i1] != None) {
      return state[i1] == Cross ? 1 : -1;
    }
  }

  return reward;
}

void TicTacToeEnv::PrintBoard(BoardState &state) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int index = i * 3 + j;
      BoardPiece symbol = state[index];
      std::cout << (symbol == None ? " u " : (symbol == Cross ? " X " : " O "));
    }
    std::cout << "\n";
  }
}
