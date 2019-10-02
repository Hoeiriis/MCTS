//
// Created by happysun on 01/10/2019.
//

#ifndef MCTS_LIBRARY_MCTSBASE_H
#define MCTS_LIBRARY_MCTSBASE_H

#include "../Environments/EnvironmentBase.h"

class MCTSBase {

    public:
        MCTSBase(EnvironmentBase& environment);
        ~MCTSBase();

        virtual void run()=0;


    protected:
        virtual void search()=0;

        EnvironmentBase& env; 
};


#endif //MCTS_LIBRARY_MCTSBASE_H