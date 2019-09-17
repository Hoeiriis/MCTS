from MCTS_Prototyping.MCTS import MCTS
from MCTS_Prototyping.MCTS.tree_policies import *
from MCTS_Prototyping.MCTS.best_child import *
from MCTS_Prototyping.MCTS.default_policies import *
from MCTS_Prototyping.MCTS.backpropagation import *
from MCTS_Prototyping.Environments.tictactoe import Board
from runner import Runner
if __name__ == "__main__":

    environment = Board()
    UCT = MCTS(environment,
               tree_policy=UCT_tree_policy,
               best_child=UCT_best_child,
               default_policy=random,
               backpropagation=backup_negamax,
               two_players=True)

    runner = Runner(UCT)
    runner.run(100, 10)
