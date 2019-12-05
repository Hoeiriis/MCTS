#ifndef MCTS_LIBRARY_SEARCHNODE_H
#define MCTS_LIBRARY_SEARCHNODE_H

#include <State.h>
#include <memory>
#include <vector>

class SearchNode {
  private:
    SearchNode(SearchNode *parent_node, State &state, bool isTerminal);

  public:
    int visits;
    std::vector<double> score {0};
    State state;
    std::vector<State> unvisited_child_states;
    SearchNode *parent;
    std::vector<std::shared_ptr<SearchNode>> child_nodes;

    bool isTerminalState;

    void add_child(const std::shared_ptr<SearchNode> &child);
    void set_unvisited_child_states(std::vector<State> &possible_child_states);
    static std::shared_ptr<SearchNode> create_SearchNode(SearchNode *parent_node, bool isTerminal);
    static std::shared_ptr<SearchNode> create_SearchNode(SearchNode *parent_node, State &state, bool isTerminal);
    static std::shared_ptr<SearchNode> create_SearchNode(std::shared_ptr<SearchNode> &parent_node, bool isTerminal);
    static std::shared_ptr<SearchNode> create_SearchNode(std::shared_ptr<SearchNode> &parent_node, State &state,
                                                         bool isTerminal);

    // SearchNode(SearchNode &original) = delete;
};

#endif // MCTS_LIBRARY_SEARCHNODE_H
