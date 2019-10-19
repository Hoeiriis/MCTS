//
// Created by happysun on 09/10/2019.
//
#include <SearchNode.h>

SearchNode::SearchNode(SearchNode *parent_node, State<boost::any> &in_state)
    : parent(parent_node), state(in_state), visits(0), score(0) {
    if (parent_node) {
        parent->add_child(*this);
    }
};

void SearchNode::add_child(SearchNode &child_node) { child_nodes.push_back(child_node); }

void SearchNode::set_unvisited_child_states(std::vector<State<boost::any>> &possible_child_states) {
    unvisited_child_states = possible_child_states;
}
