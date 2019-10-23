// Created by happysun on 01/10/2019.
//

#include <MCTSBase.h>

// TODO obviously fix this hack, but push to a branch if your code doesn't compile
// and now that tests are implemented, don't push builds to master if tests don't pass

State<boost::any> state_hack(1);

MCTSBase::MCTSBase(EnvironmentBase<boost::any> &environment, boost::function<int(State<boost::any>)> default_policy)
    : env(environment), root((SearchNode*)NULL, state_hack){};

void MCTSBase::run(int n_searches = 100) { State<boost::any> initialState = env.GetStartState(); }
