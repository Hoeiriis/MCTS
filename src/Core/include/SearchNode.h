#ifndef MCTS_LIBRARY_SEARCHNODE_H
#define MCTS_LIBRARY_SEARCHNODE_H

#include <State.h>
#include <memory>
#include <vector>

class SearchNode {
  public:
    SearchNode(SearchNode *parent_node, State &state, bool isTerminal);
    int visits;
    double score;
    State state;
    std::vector<State> unvisited_child_states;
    SearchNode *parent;
    std::vector<std::shared_ptr<SearchNode>> child_nodes;

    bool isTerminalState;

    void add_child(const SearchNode &child_node);
    void set_unvisited_child_states(std::vector<State> &possible_child_states);
    //SearchNode(SearchNode &original) = delete;
};

#endif // MCTS_LIBRARY_SEARCHNODE_H
