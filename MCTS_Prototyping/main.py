from MCTS_Prototyping.MCTS import MCTS
from MCTS_Prototyping.MCTS.tree_policies import *
from MCTS_Prototyping.MCTS.best_child import *
from MCTS_Prototyping.MCTS.default_policies import *
from MCTS_Prototyping.MCTS.backpropagation import *
from MCTS_Prototyping.Environments.tictactoe import Board

if __name__ == "__main__":

    environment = Board()
    UCT = MCTS(environment,
               tree_policy=UCT_tree_policy,
               best_child=UCT_best_child,
               default_policy=random,
               backpropagation=backup_negamax,
               two_players=True)

    end_node, result = UCT.run()

    winner = None
    if result == 1:
        winner = "Player 1"
    elif result == -1:
        winner = "Player 2"

    if result == 0:
        print("The game is a draw!")
    else:
        print("{} won the game!".format(winner))

    end_board = environment.create_board_from_state(end_node.state)
    print("\n{}".format(end_board))

    print("{} nodes explored".format(UCT.nodes_explored))
