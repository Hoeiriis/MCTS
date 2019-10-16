#include "include/UCT.h"

UCT::UCT(EnvironmentBase<boost::any>& environment, boost::function<int(State<boost::any>)> default_policy)
:MCTSBase(environment, default_policy)
{};

void UCT::run(int n_searches){

}