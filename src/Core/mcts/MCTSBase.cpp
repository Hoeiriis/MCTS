// Created by happysun on 01/10/2019.
//

#include <MCTSBase.h>
#include <memory>

// TODO obviously fix this hack, but push to a branch if your code doesn't compile
// and now that tests are implemented, don't push builds to master if tests don't pass

State<boost::any> state_hack(1);

MCTSBase::MCTSBase(
    EnvironmentBase<boost::any> &environment,
    boost::function<SearchNode(SearchNode)> &tree_policy,
    boost::function<int(State<boost::any>)> &default_policy,
    boost::function<void(SearchNode, int)> &backpropagation)
    : m_environment(environment), m_root(SearchNode(NULL, state_hack)),
    m_tree_policy(tree_policy), m_default_policy(default_policy),
    m_backpropagation(backpropagation){};

void MCTSBase::run(int n_searches) {
    State<boost::any> initialState = m_environment.GetStartState();
    m_root = SearchNode(NULL, initialState);

    while (m_environment.GetValidChildStates(m_root.state).size() != 0) {
        m_root = search(n_searches);
    }
}

SearchNode MCTSBase::search(int n_searches) {

    for (int i = 0; i < n_searches; i++) {
    }
}
