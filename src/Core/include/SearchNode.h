#ifndef MCTS_LIBRARY_SEARCHNODE_H
#define MCTS_LIBRARY_SEARCHNODE_H

#include <State.h>
#include <boost/any.hpp>
#include <vector>

class SearchNode {
  public:
    SearchNode(SearchNode *parent_node, State<boost::any> &state);
    int m_visits;
    double m_score;
    State<boost::any> m_state;
    std::vector<State<boost::any>> m_unvisited_child_states;
    SearchNode *m_parent;
    std::vector<SearchNode> m_child_nodes;

    void add_child(SearchNode &child_node);
    void set_unvisited_child_states(std::vector<State<boost::any>> &possible_child_states);
};

#endif // MCTS_LIBRARY_SEARCHNODE_H
