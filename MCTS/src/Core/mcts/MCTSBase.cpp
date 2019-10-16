// Created by happysun on 01/10/2019.
//

#include "MCTSBase.h"

MCTSBase::MCTSBase(EnvironmentBase<boost::any>& environment, boost::function<int(State<boost::any>)> default_policy):env(environment){};

void MCTSBase::run(int n_searches=100){
    State<boost::any> initialState = env.GetStartState();
}