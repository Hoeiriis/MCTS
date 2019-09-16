from anytree import Node
import numpy as np


class MCTS:

    def __init__(self, engine, tree_policy, default_policy, backpropagation, two_players=False):
        """
        MCTS: Monte Carlo Tree search
        :param engine: The game engine
        :param tree_policy: The tree policy algorithm for MCTS
        :param default_policy: The default policy for MCTS
        :param backpropagation: The backpropagation algorithm for MCTS
        """

        self._engine = engine

        self.tree_policy = tree_policy(self._expand, self._best_child)
        self.default_policy = default_policy(self._engine.get_valid_child_states, self._engine.evaluate_terminal_state)
        self.backpropagation = backpropagation
        self.nodes_explored = 0
        self.search_tree_root = None

        self.two_player = two_players
        self.current_player = 0

    def run(self):

        start_state = self._engine.start_state()
        self.search_tree_root = self._new_node([], start_state)

        while self._engine.get_valid_child_states(self.search_tree_root.state).size != 0:
            best_child = self._search(50)
            self.search_tree_root = best_child

            if self.two_player:
                self._change_player()
                
        return self.search_tree_root, self._engine.evaluate_terminal_state(self.search_tree_root)

    def _search(self, n_simulations):

        for i in range(0, n_simulations):
            node_to_simulate = self.tree_policy(self.search_tree_root)
            simulation_results = self.default_policy(node_to_simulate.state)
            self.backpropagation(node_to_simulate, simulation_results)

        return self._best_child(self.search_tree_root, 0)

    def _expand(self, node):
        if not node.unvisited_child_states:
            return None

        # Get a child state
        child_state = node.unvisited_child_states[0]
        # remove the child state from unvisited child states
        node.valid_child_states = node.unvisited_child_states[1:]
        self.nodes_explored += 1

        return self._new_node(node, child_state)

    def _best_child(self, node, c=1/np.sqrt(2)):

        child_scores = []
        child_visits = []
        for child in node.children:
            child_scores.append(node.score[self.current_player])
            child_visits.append(child.visits)

        best_child = np.argmax(np.divide(child_scores, child_visits) +\
                       c*np.sqrt(np.divide(2*np.log(node.visits), child_visits)))

        return node.children[best_child]

    def _new_node(self, parent_node, state):
        score = (0, 0)

        new_node = Node("Node{}".format(self.nodes_explored),
                        parent=parent_node,
                        state=state,
                        score=score,
                        visits=0,
                        unvisited_child_states=self._engine.get_valid_child_states(state))

        return new_node

    def _change_player(self):
        if self.current_player == 0:
            self.current_player = 1
        else:
            self.current_player = 0
