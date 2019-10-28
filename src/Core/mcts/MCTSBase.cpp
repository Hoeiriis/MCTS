// Created by happysun on 01/10/2019.
//

#include <MCTSBase.h>
#include <memory>

// TODO obviously fix this hack, but push to a branch if your code doesn't compile
// and now that tests are implemented, don't push builds to master if tests don't pass

State<boost::any> state_hack(1);

MCTSBase::MCTSBase(EnvironmentBase<boost::any> &environment, boost::function<SearchNode(SearchNode)> &tree_policy,
                   boost::function<int(State<boost::any>)> &default_policy,
                   boost::function<void(SearchNode, int)> &backpropagation,
                   boost::function<SearchNode(SearchNode)> &best_child)
    : m_environment(environment), m_root(SearchNode(NULL, state_hack)), m_tree_policy(tree_policy),
      m_default_policy(default_policy), m_backpropagation(backpropagation), m_best_child(best_child){};

void MCTSBase::run(int n_searches) {
    State<boost::any> initialState = m_environment.GetStartState();
    std::vector<State<boost::any>> unvisited_child_states = m_environment.GetValidChildStates(initialState);
    m_root = SearchNode(NULL, initialState);

    while (m_environment.GetValidChildStates(m_root.m_state).size() != 0) {
        m_root = search(n_searches);
    }
}

SearchNode MCTSBase::search(int n_searches) {

    for (int i = 0; i < n_searches; i++) {
        // TreePolicy runs to find an unexpanded node to expand
        SearchNode node_to_expand = m_tree_policy(m_root);
        // From the unexpanded node, a simulation runs that returns a score
        int simulation_score = m_default_policy(node_to_expand.m_state);
        // The score is backpropagated up through the search tree
        m_backpropagation(node_to_expand, simulation_score);
    }
}
