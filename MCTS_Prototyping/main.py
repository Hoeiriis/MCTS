from .MCTS.MCTS import MCTS


if __name__ == "__main__":

    tictactoeEngine = None


    utc = MCTS(tictactoeEngine, MCTS.tree_policy.tpolicy, MCTS.default_policy.tpolicy, MCTS.backpropagation.back)
