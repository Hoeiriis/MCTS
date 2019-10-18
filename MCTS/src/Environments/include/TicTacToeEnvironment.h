/**
 *
 * @file TicTacToeEnvironment.h
 * @author Alexander Larsen
 * @date 16 Oct 2019
 * @brief Provides an environment for tictactoe
 *
 * @details Implements board states as a vector of size 9 representing
 * the state of each position in the grid; a value of 0 means the
 * position is not occupied; 1 means player one occupies it; 2 means
 * player 2 occupies it.
 *
 */


#ifndef TICTACENVIRONMENT_H
#define TICTACENVIRONMENT_H
#include <EnvironmentBase.h>

enum BoardPiece { None = 0, Cross = 1, Circle = 2 };
typedef std::vector<BoardPiece> BoardState;

/*
 * @brief      Environment implementing the game tictactoe
 *
 * @details    Implements barebones functionality of the game - defines legal
 * moves and determines a winner if there is one.
 *
 *
 * @return     TicTacToeEnv
 */

class TicTacToeEnv : public EnvironmentBase<BoardState> {
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
  State<BoardState> GetStartState();

  /**
   * @brief      Return successor states of a state
   *
   * @details    Given a representation of a state, return a vector of all
   * possible successor states of that state.
   *
   * @param      &state
   *
   * @return     vector<state>
   */
  std::vector<State<BoardState>> GetValidChildStates(State<BoardState> &state) ;
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
  Reward EvaluateTerminalState(State<BoardState> &state);

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
  void PrintBoard(State<BoardState> &state);

private:
};

#endif // TICTACTOEENVIRONMET_H
