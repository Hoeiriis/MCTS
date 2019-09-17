
class Runner:

    def __init__(self, mcts_algo):
        self.algo = mcts_algo
        self.player1 = 0
        self.player2 = 0
        self.draw = 0

        self.games_ran = 0

    def _run_one_game(self, simulations):

        if self.games_ran % 25 == 0:
            print("Running game {} out of 1000".format(self.games_ran))

        end_node, result = self.algo.run(simulations)

        if result == 1:
            self.player1 += 1
        elif result == -1:
            self.player2 += 1
        else:
            self.draw += 1

        self.games_ran += 1

    def run(self, n_games=1000, simulations=100):

        for game in range(0, n_games):
            self._run_one_game(simulations)

        print("out of {} games:".format(n_games))
        print("Player 1 won {} times!".format(self.player1))
        print("Player 2 won {} times!".format(self.player2))
        print("{} games were a draw!".format(self.draw))
        self.games_ran = 0
