#include <MCTSInterface.h>
#include <memory>

MCTSInterface::MCTSInterface(EnvironmentBase<boost::any> &environment) : m_environment(environment){};

void MCTSInterface::run(int n_searches) {
    State<boost::any> initialState = m_environment.GetStartState();
    std::vector<State<boost::any>> unvisited_child_states = m_environment.GetValidChildStates(initialState);
    m_root = SearchNode(NULL, initialState);

    while (m_environment.GetValidChildStates(m_root.m_state).size() != 0) {
        m_root = search(n_searches);
    }
}

SearchNode MCTSInterface::search(int n_searches) {

    for (int i = 0; i < n_searches; i++) {
        // TreePolicy runs to find an unexpanded node to expand
        SearchNode node_to_expand = m_tree_policy(m_root);
        // From the unexpanded node, a simulation runs that returns a score
        int simulation_score = m_default_policy(node_to_expand.m_state);
        // The score is backpropagated up through the search tree
        m_backpropagation(node_to_expand, simulation_score);
    }
}
