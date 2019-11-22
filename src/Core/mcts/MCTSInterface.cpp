#include <MCTSInterface.h>
#include <memory>

MCTSInterface::MCTSInterface(EnvironmentBase &environment) : m_environment(environment){};

void MCTSInterface::run(int n_searches) {
    State initialState = m_environment.GetStartState();
    std::vector<State> unvisited_child_states = m_environment.GetValidChildStates(initialState);
    m_root = SearchNode::create_SearchNode(NULL, initialState, false);

    while (!m_environment.GetValidChildStates(m_root->state).empty()) {
        m_root = m_search(n_searches);
    }
}

std::shared_ptr<SearchNode> MCTSInterface::m_search(int n_searches) {

    for (int i = 0; i < n_searches; i++) {
        // TreePolicy runs to find an unexpanded node to expand
        auto node_to_expand = m_tree_policy(m_root);
        // From the unexpanded node, a simulation runs that returns a score
        Reward simulation_score = m_default_policy(node_to_expand->state);
        // The score is backpropagated up through the search tree
        m_backpropagation(node_to_expand, simulation_score);
    }
}
