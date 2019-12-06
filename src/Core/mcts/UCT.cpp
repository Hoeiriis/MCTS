#include <UCT.h>
#include <cfloat>

UCT::UCT(EnvironmentBase &environment) : MCTSBase(environment), generator(std::mt19937(time(nullptr))){};

std::shared_ptr<SearchNode> UCT::m_tree_policy(std::shared_ptr<SearchNode> node) { return m_tpolicy.treePolicy(node); };

Reward UCT::m_default_policy(State &state) { return m_defaultPolicy.defaultPolicy(state); };

std::shared_ptr<SearchNode> UCT::m_best_child(std::shared_ptr<SearchNode> node, double c) {
    auto best_score_so_far = DBL_MIN;
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

    std::vector<double> bestChildren {};
    for (int i = 0; i < node->child_nodes.size(); i++) {
        if (score_list.at(i) == best_score_so_far){
            bestChildren.push_back(i);
        }
    }

    std::uniform_int_distribution<int> uniformIntDistribution(0, bestChildren.size()-1);
    int i_random = uniformIntDistribution(generator);

    return node->child_nodes.at(bestChildren.at(i_random));
};

void UCT::m_backpropagation(std::shared_ptr<SearchNode> node, Reward score) { return m_backup.backup(node, score); }

std::shared_ptr<SearchNode> UCT::m_expand(std::shared_ptr<SearchNode> node) {
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

    // Remove the state from unvisited states
    node->unvisited_child_states.erase(node->unvisited_child_states.begin() + i_random);

    return expanded_node;
}
