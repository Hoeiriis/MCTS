//
// Created by happysun on 05/12/2019.
//

#include <UCT_two_players.h>
#include <cfloat>

UCT_two_players::UCT_two_players(EnvironmentBase &environment): UCT(environment){}

std::shared_ptr<SearchNode> UCT_two_players::m_best_child(std::shared_ptr<SearchNode> node, double c) {
    auto best_score_so_far = DBL_MIN;
    std::vector<double> score_list = {};

    for (int i = 0; i < node->child_nodes.size(); i++) {
        auto child = node->child_nodes.at(i);
        double score = (child->score.at(CurrentPlayer) / (child->visits + DBL_MIN)) +
                       c * std::sqrt((std::log(node->visits) / (child->visits + DBL_MIN)));

        score_list.push_back(score);

        if (score > best_score_so_far) {
            best_score_so_far = score;
        }
    }

    std::vector<double> bestChildren {};
    for (int i = 0; i < node->child_nodes.size(); i++) {
        if (score_list.at(i) == best_score_so_far){
            bestChildren.push_back(i);
        }
    }

    std::uniform_int_distribution<int> uniformIntDistribution(0, bestChildren.size()-1);
    int i_random = uniformIntDistribution(generator);

    return node->child_nodes.at(bestChildren.at(i_random));
}

std::shared_ptr<SearchNode> UCT_two_players::m_expand(std::shared_ptr<SearchNode> node) {
    int i_random = 0;

    if (node->unvisited_child_states.size() > 1) {
        // Get unvisited state randomly
        std::uniform_int_distribution<int> uniformIntDistribution(0, node->unvisited_child_states.size() - 1);
        i_random = uniformIntDistribution(generator);
    }

    State expanded_state = node->unvisited_child_states.at(i_random);

    // Create node from unvisited state
    auto is_terminal = m_environment.GetValidChildStates(expanded_state).empty();
    auto expanded_node = SearchNode::create_SearchNode(node, expanded_state, is_terminal);

    // Add values for both players
    expanded_node->score = {0, 0};

    // Remove the state from unvisited states
    node->unvisited_child_states.erase(node->unvisited_child_states.begin() + i_random);

    return expanded_node;
}

State UCT_two_players::run(int n_searches) {

    State initialState = m_environment.GetStartState();
    std::vector<State> unvisited_child_states = m_environment.GetValidChildStates(initialState);
    m_root = SearchNode::create_SearchNode(nullptr, initialState, false);
    m_root->set_unvisited_child_states(unvisited_child_states);

    CurrentPlayer = 0;

    while (!m_environment.GetValidChildStates(m_root->state).empty()) {
        auto best_child = m_search(n_searches);
        m_root = best_child;

        // Change player
        CurrentPlayer = !CurrentPlayer;
    }

    return m_root->state;
}

void UCT_two_players::m_backpropagation(std::shared_ptr<SearchNode> node, Reward score) {
    m_backup.backup(node, score, CurrentPlayer);
};