from .MCTS import MCTS
from .MCTS.tree_policies import *

if __name__ == "__main__":

    UTC = MCTS(tree_policy=uct)