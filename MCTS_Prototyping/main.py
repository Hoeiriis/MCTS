from runner import Runner
from MCTS import MCTS
from MCTS.tree_policies import *
from MCTS.best_child import *
from MCTS.default_policies import *
from MCTS.backpropagation import *
from Environments.tictactoe import Board
if __name__ == "__main__":

    environment = Board()
    UCT = MCTS(environment,
               tree_policy=UCT_tree_policy,
               best_child=UCT_best_child,
               default_policy=tictactoe_1,
               backpropagation=backup_negamax,
               two_players=True)

    runner = Runner(UCT)
    runner.run(20, 500)
