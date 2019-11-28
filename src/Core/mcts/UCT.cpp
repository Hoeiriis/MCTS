#include <UCT.h>

UCT::UCT(EnvironmentBase &environment)
    : MCTSInterface(environment){};

std::shared_ptr<SearchNode> UCT::m_tree_policy(std::shared_ptr<SearchNode> node){

};

Reward UCT::m_default_policy(State &state){
    return m_defaultPolicy.defaultPolicy(state);
};

std::shared_ptr<SearchNode> UCT::m_best_child(std::shared_ptr<SearchNode> node, double c) {
    return node;
};

void UCT::m_backpropagation(std::shared_ptr<SearchNode> node, Reward score) {
    return m_backup.backup(node, score);
}

std::shared_ptr<SearchNode> UCT::m_expand(std::shared_ptr<SearchNode> node){
    auto unvisited_childs = m_environment.GetValidChildStates(node->state);
    State expanded_state = unvisited_childs.at(0);
    auto is_terminal = m_environment.GetValidChildStates(expanded_state).empty();

    return SearchNode::create_SearchNode(node, expanded_state, is_terminal);
}
