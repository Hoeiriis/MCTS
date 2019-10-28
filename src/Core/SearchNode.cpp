//
// Created by happysun on 09/10/2019.
//
#include <SearchNode.h>

SearchNode::SearchNode(SearchNode *parent_node, State<boost::any> &in_state)
    : m_parent(parent_node), m_state(in_state), m_visits(0), m_score(0) {
    if (parent_node) {
        m_parent->add_child(*this);
    }
};

void SearchNode::add_child(SearchNode &child_node) { m_child_nodes.push_back(child_node); }

void SearchNode::set_unvisited_child_states(std::vector<State<boost::any>> &possible_child_states) {
    m_unvisited_child_states = possible_child_states;
}
