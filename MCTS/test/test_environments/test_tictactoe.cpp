#include <TicTacToeEnvironment.h>
#include <gtest/gtest.h>

TEST(GetStartState, InitialStateIsCorrect) {
  TicTacToeEnv env;
  std::vector<BoardPiece> start_state = env.GetStartState().data;

  EXPECT_EQ(start_state.size(), 9);
  for (auto &board_piece : start_state) {
    EXPECT_EQ(board_piece, None);
  }
}
