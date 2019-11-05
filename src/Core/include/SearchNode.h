#ifndef MCTS_LIBRARY_SEARCHNODE_H
#define MCTS_LIBRARY_SEARCHNODE_H

#include <State.h>
#include <vector>

class SearchNode {
  public:
    SearchNode(SearchNode *parent_node, State &state, bool isTerminal);
    int visits;
    double score;
    State state;
    std::vector<State> unvisited_child_states;
    SearchNode *parent;
    std::vector<SearchNode> child_nodes;

    bool isTerminalState;

    void add_child(SearchNode &child_node);
    void set_unvisited_child_states(std::vector<State> &possible_child_states);
};

#endif // MCTS_LIBRARY_SEARCHNODE_H
