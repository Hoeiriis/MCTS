from anytree import Node
import numpy as np


class MCTS:

    def __init__(self, environment, tree_policy, best_child, default_policy, backpropagation, two_players=False):
        """
        MCTS: Monte Carlo Tree search
        :param engine: The game engine
        :param tree_policy: The tree policy algorithm for MCTS
        :param default_policy: The default policy for MCTS
        :param backpropagation: The backpropagation algorithm for MCTS
        """

        self._environment = environment

        self.backpropagation = backpropagation
        self.best_child = best_child
        self.tree_policy = tree_policy(self._expand, self.best_child)
        self.default_policy = default_policy(self._environment.get_valid_child_states,
                                             self._environment.evaluate_terminal_state)

        self.nodes_explored = 0
        self.search_tree_root = None

        self.two_player = two_players
        self.current_player = 0

    def run(self):

        start_state = self._environment.start_state()
        self.search_tree_root = self._new_node(None, start_state)

        while self._environment.get_valid_child_states(self.search_tree_root.state).size != 0:
            best_child = self._search(50)
            self.search_tree_root = best_child

            if self.two_player:
                self._change_player()
                
        return self.search_tree_root, self._environment.evaluate_terminal_state(self.search_tree_root.state)

    def _search(self, n_simulations):

        for i in range(0, n_simulations):
            node_to_simulate = self.tree_policy(self.search_tree_root)
            simulation_results = self.default_policy(node_to_simulate.state)

            if self.two_player:
                if self.current_player == 1:
                    simulation_results = -1*simulation_results

                self.backpropagation(node_to_simulate, simulation_results, self.current_player)
            else:
                self.backpropagation(node_to_simulate, simulation_results)

        return self.best_child(self.search_tree_root, current_player=self.current_player, c=1)

    def _expand(self, node):
        if node.unvisited_child_states.size == 0:
            return None

        # Get a child state
        child_state = node.unvisited_child_states[0]
        # remove the child state from unvisited child states
        node.valid_child_states = node.unvisited_child_states[1:]
        self.nodes_explored += 1

        return self._new_node(node, child_state)

    def _new_node(self, parent_node, state):
        score = [0, 0]

        new_node = Node("Node{}".format(self.nodes_explored),
                        parent=parent_node,
                        state=state,
                        score=score,
                        visits=0,
                        unvisited_child_states=self._environment.get_valid_child_states(state))

        return new_node

    def _change_player(self):
        if self.current_player == 0:
            self.current_player = 1
        else:
            self.current_player = 0
