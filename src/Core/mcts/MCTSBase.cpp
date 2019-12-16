#include <MCTSBase.h>
#include <memory>

MCTSBase::MCTSBase(EnvironmentInterface &environment) : m_environment(environment){};

State MCTSBase::run(int n_searches) {
    State initialState = m_environment.GetStartState();
    std::vector<State> unvisited_child_states = m_environment.GetValidChildStates(initialState);
    m_root = SearchNode::create_SearchNode(nullptr, initialState, false);
    m_root->set_unvisited_child_states(unvisited_child_states);

    while (!m_environment.IsTerminal(m_root->state)) {
        auto best_child = m_search(n_searches);
        m_root = best_child;
    }

    return m_root->state;
}

EnvironmentInterface &MCTSBase::getEnvironment() { return this->m_environment; }

std::shared_ptr<SearchNode> MCTSBase::m_search(int n_searches) {

    for (int i = 0; i < n_searches; i++) {
        // TreePolicy runs to find an unexpanded node to expand
        auto expandedNode = m_tree_policy(m_root);
        // From the expanded node, a simulation runs that returns a score
        Reward simulation_score = m_default_policy(expandedNode->state);
        // The score is backpropagated up through the search tree
        m_backpropagation(expandedNode, simulation_score);
    }

    return m_best_child(m_root, 0);
}
