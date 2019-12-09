#include <RunnerTicTacToe.h>
#include <State.h>
#include <iostream>

using namespace std;

RunnerTicTacToe::RunnerTicTacToe(MCTSInterface &mctsAlgorithm) : Runner(mctsAlgorithm){};

void RunnerTicTacToe::run(int n_games = 1000, int n_searches = 100) {
    player1 = 0;
    player2 = 0;
    gamesRan = 0;

    for (int i = 1; i <= n_games; i++) {
        runOneGame(n_games, n_searches);
    }
    cout << "\nOut of " << n_games << " games: " << endl;
    cout << "Player 1 won " << player1 << " times!" << endl;
    cout << "Player 2 won " << player2 << " times!" << endl;
    cout << draw << " games were a draw\n" << endl;

}

void RunnerTicTacToe::runOneGame(int n_games, int n_searches) {
    int result;
    int print_param = setPrint(n_games);
    gamesRan += 1;

    if (this->gamesRan % print_param == 0) {
        cout << "Running game " << this->gamesRan << " out of " << n_games << endl;
    }
    State state = this->mctsAlgorithm.run(n_searches);
    result = this->mctsAlgorithm.getEnvironment().EvaluateTerminalState(state);
    if (result == 1) {
        player1 += 1;
    } else if (result == -1) {
        player2 += 1;
    } else {
        draw += 1;
    }
}