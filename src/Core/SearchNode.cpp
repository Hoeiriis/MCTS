//
// Created by happysun on 09/10/2019.
//
#include <SearchNode.h>
#include <optional>

SearchNode::SearchNode(SearchNode *parent_node, State &in_state, bool isTerminal)
    : parent(parent_node), state(in_state), visits(0), isTerminalState(isTerminal){
        if (!parent_node){
            depth=0;
        }else
        {
            depth=parent_node->depth+1;
        }
    };

void SearchNode::add_child(const std::shared_ptr<SearchNode> &child) { child_nodes.push_back(child); }

void SearchNode::set_unvisited_child_states(std::vector<State> &possible_child_states) {
    unvisited_child_states = possible_child_states;
}

std::shared_ptr<SearchNode> SearchNode::create_SearchNode(SearchNode *parent_node, State &state, bool isTerminal) {
    auto newNode = std::make_shared<SearchNode>(SearchNode(parent_node, state, isTerminal));
    if (parent_node) {
        parent_node->add_child(newNode);
    }

    return newNode;
}

std::shared_ptr<SearchNode> SearchNode::create_SearchNode(SearchNode *parent_node, bool isTerminal) {
    State tempState = State(std::nullopt);
    auto newNode = std::make_shared<SearchNode>(SearchNode(parent_node, tempState, isTerminal));
    if (parent_node) {
        parent_node->add_child(newNode);
    }

    return newNode;
}

std::shared_ptr<SearchNode> SearchNode::create_SearchNode(std::shared_ptr<SearchNode> &parent_node, State &state,
                                                          bool isTerminal) {
    return create_SearchNode(parent_node.get(), state, isTerminal);
}

std::shared_ptr<SearchNode> SearchNode::create_SearchNode(std::shared_ptr<SearchNode> &parent_node, bool isTerminal) {
    return create_SearchNode(parent_node.get(), isTerminal);
}