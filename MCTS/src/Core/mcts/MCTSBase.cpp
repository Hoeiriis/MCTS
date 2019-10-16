// Created by happysun on 01/10/2019.
//

#include "MCTSBase.h"

MCTSBase::MCTSBase(EnvironmentBase& environment, boost::function<int(State)> default_policy):env(environment){};

MCTSBase::run(int n_searches=100){
    State initialState = EnvironmentBase.GetStartState();
}