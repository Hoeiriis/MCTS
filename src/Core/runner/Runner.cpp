#include <Runner.h>

Runner::Runner(MCTSInterface &mctsAlgorithm) : mctsAlgorithm(mctsAlgorithm){};

int Runner::setPrint(int n_games) {
    if (n_games <= 20) {
        return 1;
    } else if (n_games <= 50) {
        return 2;
    } else if (n_games <= 100) {
        return 5;
    } else if (n_games <= 200) {
        return 10;
    } else {
        return 25;
    }
}