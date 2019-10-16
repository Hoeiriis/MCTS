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

  /**
   * @brief      Get the initial state
   *
   * @details    Returns a vector representing the initial board configuration
   * of tic tac toe
   *
   * @return     State
   */
  State GetStartState();

  std::vector<State> GetValidChildStates(State &state);

  /**
   * @brief      Evaluate whether a state is terminal
   *
   * @details    Checks vertical, horizontal, and diagonally whether one player
   * has three successive pieces. If player one does, return 1. If player two
   * does, return -1. Otherwise return 0.
   *
   * @param      State&
   *
   * @return     double
   */
  Reward EvaluateTerminalState(State &state);

  /**
   * @brief      Display a given state representation
   *
   * @details    Dumps a representation of the given state to stdout. Player one
   * is marked as X, player two is marked as O, and slots without pieces are
   * marked with 'u'
   *
   * @param      State&
   *
   * @return     void
   */
  void PrintBoard(BoardState &state);

private:
};
