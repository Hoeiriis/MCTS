#include <EnvironmentBase.h>
#include <iostream>
#include <ostream>

enum BoardPiece { None = 0, Cross = 1, Circle = 2 };
typedef std::vector<BoardPiece> BoardState;

class TicTacToeEnv : public EnvironmentBase {
public:
  TicTacToeEnv();
  BoardState GetStartState();
  std::vector<BoardState> GetValidChildStates(BoardState &state);
  Reward EvaluateTerminalState(BoardState &state);

  void PrintBoard(BoardState &state);

private:
};
