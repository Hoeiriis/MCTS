#include <MCTSBase.h>
#include <memory>

MCTSBase::MCTSBase(EnvironmentInterface &environment) : m_environment(environment){};

State MCTSBase::run(int n_searches) {
    State initialState = m_environment.GetStartState();
    return run(n_searches, initialState);
}

State MCTSBase::run(int n_searches, State initial_state) {
    std::vector<State> unvisited_child_states = m_environment.GetValidChildStates(initial_state);
    m_root = SearchNode::create_SearchNode(nullptr, initial_state, false);
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
        
        std::cout << "Iter: " << i << " of " << n_searches << std::endl;
    }

    return m_best_child(m_root, 0);
}

std::shared_ptr<SearchNode> MCTSBase::search_iter_limit(int n_search_iterations) {
    State initial_state = m_environment.GetStartState();
    std::vector<State> unvisited_child_states = m_environment.GetValidChildStates(initial_state);
    m_root = SearchNode::create_SearchNode(nullptr, initial_state, false);
    m_root->set_unvisited_child_states(unvisited_child_states);

    // run until stopping condition is met
    m_root = m_search(n_search_iterations);
    return unroll_search();
}

std::shared_ptr<SearchNode> MCTSBase::search_time_limit(int sec_to_run) {
    State initial_state = m_environment.GetStartState();
    std::vector<State> unvisited_child_states = m_environment.GetValidChildStates(initial_state);
    m_root = SearchNode::create_SearchNode(nullptr, initial_state, false);
    m_root->set_unvisited_child_states(unvisited_child_states);

    time_t start = time(nullptr);
    long timeLeft = sec_to_run;

    // run until stopping condition is met
    while(timeLeft > 0) {
        // TreePolicy runs to find an unexpanded node to expand
        auto expandedNode = m_tree_policy(m_root);
        // From the expanded node, a simulation runs that returns a score
        Reward simulation_score = m_default_policy(expandedNode->state);
        // The score is backpropagated up through the search tree
        m_backpropagation(expandedNode, simulation_score);

        // update time left
        timeLeft = timeLeft - (time(nullptr) - start);
    }

    return unroll_search();
}

std::shared_ptr<SearchNode> MCTSBase::unroll_search() {
    auto current_node = m_root;
    // keep getting best child until we reach a terminal node or leaf node
    while((!m_environment.IsTerminal(current_node->state)) || (!current_node->child_nodes.empty())){
        current_node = m_best_child(current_node, 0);
    }

    return current_node;
}
