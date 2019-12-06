#include <RunnerTicTacToe.h>
#include <State.h>
#include <iostream>

using namespace std;

RunnerTicTacToe::RunnerTicTacToe(MCTSBase &mctsAlgorithm) : Runner(mctsAlgorithm){};

void RunnerTicTacToe::runOneGame(int n_searches) {
    int result;
    // TODO parametrize printout?
    if (this->gamesRan % 25 == 0) {
        cout << "Running game " << this->gamesRan << "out of 1000." << endl;

        // TODO add environment result line and check: usage of a reference for a state?
        State state = this->mctsAlgorithm.run(n_searches);
        // result = this->mctsAlgorithm.environment(state);

        if (result == 1) {
            player1 += 1;
        } else if (result == -1) {
            player2 += 1;
        } else {
            draw += 1;
        }
        gamesRan += 1;
    }
}

void RunnerTicTacToe::run(int n_games = 1000, int n_searches = 100) {
    for (int i = 1; i < n_games; i++) {
        runOneGame(n_searches);
    }
    cout << "Out of " << n_games << " games" << endl;
    cout << "Player 1 won " << player1 << " times!" << endl;
    cout << "Player 2 won " << player2 << " times!" << endl;
    cout << draw << " games were a draw" << endl;
    gamesRan = 0;
}