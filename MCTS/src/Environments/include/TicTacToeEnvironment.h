#include <EnvironmentBase.h>
#include <iostream>
#include <ostream>

enum BoardPiece { None = 0, Cross = 1, Circle = 2 };
typedef std::vector<BoardPiece> BoardState;

class TicTacToeState: public State{
  public:
    TicTacToeState(BoardState state):data(state){};
    BoardState data;
};

class TicTacToeEnv : public EnvironmentBase {
public:
  TicTacToeEnv();
  State GetStartState();
  std::vector<State> GetValidChildStates(State &state);
  Reward EvaluateTerminalState(State &state);

  void PrintBoard(BoardState &state);

private:
};
