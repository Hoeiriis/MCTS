//
// Created by happysun on 01/10/2019.
//

#ifndef MCTS_LIBRARY_MCTSBASE_H
#define MCTS_LIBRARY_MCTSBASE_H

#include <boost/function.hpp>
#include <boost/any.hpp>
#include <State.h>
#include <SearchNode.h>
#include <EnvironmentBase.h>

class MCTSBase
{
    public:
        MCTSBase(EnvironmentBase<boost::any>& environment, boost::function<int(State<boost::any>)> default_policy);

        virtual void run(int n_searches)=0;


    protected:
        virtual void search()=0;

        EnvironmentBase<boost::any>& env;
        SearchNode root;

};


#endif //MCTS_LIBRARY_MCTSBASE_H
