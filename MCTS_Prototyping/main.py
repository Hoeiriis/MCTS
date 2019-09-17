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
