/**
 * @file main.cpp
 * @author Alexander Larsen
 * @date 16 Oct 2019
 * @brief Very nice
 *
 * @details Does basically nothing
 *
 */

#include <TicTacToeEnvironment.h>
#include <RunnerTicTacToe.h>

int main() {

    TicTacToeEnv env = TicTacToeEnv();

    /*
    for (int i = 0; i < 100; ++i) {
        std::cout << "Running one game of tic tac toe!" << std::endl;

        auto endState = uctTwoPlayers.run(50000);
        int winner = env.EvaluateTerminalState(endState);
        env.PrintBoard(endState);
        std::cout << "Player " << winner << " wins!" << std::endl;
    } */

    return 0;
}
