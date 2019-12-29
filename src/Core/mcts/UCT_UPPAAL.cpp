//
// Created by happysun on 27/12/2019.
//

#include <cfloat>
#include <cassert>
#include <cmath>
#include "UCT_UPPAAL.h"

UCT_UPPAAL::UCT_UPPAAL(EnvironmentInterface &environment)
: _environment(environment), generator(std::mt19937(time(nullptr))), _defaultPolicy(UPPAAL_RandomSamplingDefaultPolicy(_environment)) {
    // UCT TreePolicy setup
    std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>)> f_expand =
            std::bind(&UCT_UPPAAL::m_expand, this, std::placeholders::_1);

    std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>, double)> f_best_child =
            std::bind(&UCT_UPPAAL::m_best_child, this, std::placeholders::_1, std::placeholders::_2);

    _tpolicy = UCT_TreePolicy(f_expand, f_best_child);
}

State UCT_UPPAAL::run(int n_searches) {

    State initial_state = _environment.GetStartState();
    std::vector<State> unvisited_child_states = _environment.GetValidChildStates(initial_state);
    m_root = SearchNode::create_SearchNode(nullptr, initial_state, false);
    m_root->set_unvisited_child_states(unvisited_child_states);


    time_t start = time(nullptr);
    long timeLeft = n_searches;

    while(!best_proved && timeLeft > 0) {
        // TreePolicy runs to find an unexpanded node to expand
        auto expandedNode = m_tree_policy(m_root);
        // From the expanded node, a simulation runs that returns a score
        Reward simulation_score = m_default_policy(expandedNode->state);
        // The score is backpropagated up through the search tree
        m_backpropagation(expandedNode, simulation_score);

        // if new terminal node is encountered, update the bestTerminalNode
        if (expandedNode->isTerminalState){
            Reward termReward = _environment.EvaluateRewardFunction(expandedNode->state);
            if (bestTerminalNodesFound.empty() || bestTerminalNodesFound.at(0).score < termReward){
                auto newBestNode = TerminalNodeScore();
                newBestNode.score = termReward;
                newBestNode.node = expandedNode;
                newBestNode.time_to_find = (time(nullptr) - start);
                // insert at beginning
                bestTerminalNodesFound.insert(bestTerminalNodesFound.begin(), newBestNode);
            }
        }

        // update time left
        timeLeft = timeLeft - (time(nullptr) - start);
    }

    if (bestTerminalNodesFound.empty()){
        return nullptr;
    } else {
        return bestTerminalNodesFound.at(0).node->state;
    }
}


std::shared_ptr<SearchNode> UCT_UPPAAL::m_best_child(std::shared_ptr<SearchNode> node, double c) {

    auto best_score_so_far = std::numeric_limits<double>::lowest();
    std::vector<double> score_list = {};

    for (int i = 0; i < node->child_nodes.size(); i++) {
        auto child = node->child_nodes.at(i);
        double score = (child->score.at(0) / (child->visits + DBL_MIN)) +
                       c * std::sqrt((std::log(node->visits) / (child->visits + DBL_MIN)));

        score_list.push_back(score);

        if (score > best_score_so_far) {
            best_score_so_far = score;
        }
    }

    std::vector<double> bestChildren{};
    for (int i = 0; i < node->child_nodes.size(); i++) {
        if (score_list.at(i) == best_score_so_far) {
            bestChildren.push_back(i);
        }
    }

    assert(!bestChildren.empty()); // ensure that there is children
    std::uniform_int_distribution<int> uniformIntDistribution(0, bestChildren.size() - 1);
    int i_random = uniformIntDistribution(generator);

    return node->child_nodes.at(bestChildren.at(i_random));

}

std::shared_ptr<SearchNode> UCT_UPPAAL::m_expand(std::shared_ptr<SearchNode> node) {

    int i_random = 0;

    if (node->unvisited_child_states.size() > 1) {
        // Get unvisited state randomly
        std::uniform_int_distribution<int> uniformIntDistribution(0, node->unvisited_child_states.size() - 1);
        i_random = uniformIntDistribution(generator);
    }

    State expanded_state = node->unvisited_child_states.at(i_random);

    // Create node from unvisited state
    auto is_terminal = _environment.IsTerminal(expanded_state);
    auto expanded_node = SearchNode::create_SearchNode(node, expanded_state, is_terminal);

    // Set unvisited child States
    auto unvisitedChildStates = _environment.GetValidChildStates(expanded_state);
    expanded_node->set_unvisited_child_states(unvisitedChildStates);

    // Remove the state from unvisited states
    node->unvisited_child_states.erase(node->unvisited_child_states.begin() + i_random);

    return expanded_node;
}

Reward UCT_UPPAAL::m_default_policy(State &state) {
    return _defaultPolicy.defaultPolicy(state);
}

void UCT_UPPAAL::m_backpropagation(std::shared_ptr<SearchNode> node, Reward score) {
    return _backup.backup(node, score);
}

std::shared_ptr<SearchNode> UCT_UPPAAL::m_tree_policy(std::shared_ptr<SearchNode> node) {
    return _tpolicy.treePolicy(node);
}

std::shared_ptr<SearchNode> UCT_UPPAAL::m_search(int n_searches) {
    return std::shared_ptr<SearchNode>();
}
