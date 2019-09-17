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

    def run_tictactoe_maybe(self):

        # Initialize the environment and the search tree
        start_state = self._environment.start_state()
        self.search_tree_root = self._new_node(None, start_state)

        # Continually run until the environment terminates. The environment terminates when the search_tree_root does
        # not have any valid child states
        while self._environment.get_valid_child_states(self.search_tree_root.state).size != 0:

            best_child = None
            # If there currently is a winning move, choose that
            for node in self.search_tree_root.children:
                valid_child_child_states = self._environment.get_valid_child_states(node.state)
                if valid_child_child_states.size == 0:
                    winner = self._environment.evaluate_terminal_state(node.state)

                    if self.current_player == 1:
                        winner = -1 * winner
                    if winner == 1:
                        best_child = node
                        break

            # else explore the search_tree and choose the best child
            if best_child is None:
                best_child = self._search(500)

            # the best child is set as the new root of the search tree: eg. we make an actual "move" in the environment
            self.search_tree_root = best_child

            # if the environment has two players, the player is changed
            if self.two_player:
                self._change_player()

        # When the environment terminates, the current tree node is returned along with the evaluation of the
        # terminal state
        return self.search_tree_root, self._environment.evaluate_terminal_state(self.search_tree_root.state)

    def run(self, n_searches=100):
        # Initialize the environment and the search tree
        start_state = self._environment.start_state()
        self.search_tree_root = self._new_node(None, start_state)

        # Continually run until the environment terminates. The environment terminates when the search_tree_root does
        # not have any valid child states
        while self._environment.get_valid_child_states(self.search_tree_root.state).size != 0:
            # Explore the search_tree and choose the best child
            best_child = self._search(n_searches)

            # the best child is set as the new root of the search tree: eg. we make an actual "move" in the environment
            self.search_tree_root = best_child

            # if the environment has two players, the player is changed
            if self.two_player:
                self._change_player()

        # When the environment terminates, the current tree node is returned along with the evaluation of the
        # terminal state
        return self.search_tree_root, self._environment.evaluate_terminal_state(self.search_tree_root.state)

    def _search(self, n_searches):

        # loops over the search procedure n times
        for i in range(0, n_searches):
            # First the tree policy runs and find an unexpanded node to expand
            node_to_simulate = self.tree_policy(self.search_tree_root, self.current_player)
            # The default policy is then run on the expanded node
            simulation_results = self.default_policy(node_to_simulate.state)

            # The simulation results are backpropagated up through the ancestors of the expanded node
            # If it's a two player environment, the backpropagation algorithm needs to know the current_player
            if self.two_player:
                # Since the simulation results only returns results with repect to player 0 (eg. player 1), the results
                # are inverted if the current player is player 1 (player 2)
                if self.current_player == 1:
                    simulation_results = -1*simulation_results

                self.backpropagation(node_to_simulate, simulation_results, self.current_player)
            else:
                self.backpropagation(node_to_simulate, simulation_results)

        # When the search has finished, the algorithm chooses the best child based on current knowledge
        return self.best_child(self.search_tree_root, current_player=self.current_player, c=0)

    def _expand(self, node):
        if node.unvisited_child_states.size == 0:
            return None

        # Get a random child state
        i = np.random.choice(len(node.unvisited_child_states))
        child_state = node.unvisited_child_states[i]
        # remove the child state from unvisited child states
        node.unvisited_child_states = np.delete(node.unvisited_child_states, i, axis=0)
        self.nodes_explored += 1

        return self._new_node(node, child_state)

    def _new_node(self, parent_node, state):
        score = [0, 0]
        # Create new node, also compute valid child states
        new_node = Node("Node{}".format(self.nodes_explored),
                        parent=parent_node,
                        state=state,
                        score=score,
                        visits=0,
                        unvisited_child_states=self._environment.get_valid_child_states(state))

        return new_node

    def _change_player(self):
        self.current_player = 1 if self.current_player == 0 else 0
