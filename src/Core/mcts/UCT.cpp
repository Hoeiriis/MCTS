#include <UCT.h>

UCT::UCT(EnvironmentBase &environment, boost::function<int(State)> default_policy)
    : MCTSBase(environment, default_policy){};

void UCT::run(int n_searches) {}
