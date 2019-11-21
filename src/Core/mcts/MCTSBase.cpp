#include <MCTSBase.h>

MCTSBase::MCTSBase(EnvironmentBase &environment, boost::function<int(State)> default_policy)
    : env(environment), root(SearchNode::create_SearchNode(nullptr, false)){};

void MCTSBase::run(int n_searches = 100) { State initialState = env.GetStartState(); }
