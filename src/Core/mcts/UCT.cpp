#include <UCT.h>
#include <UCT_treePolicy.h>
#include <RandomDefaultPolicy.h>

UCT::UCT(EnvironmentBase<boost::any> &environment) : MCTSInterface(environment){ 
};

