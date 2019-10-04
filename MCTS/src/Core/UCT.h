#ifndef MCTS_LIBRARY_UCT_H
#define MCTS_LIBRARY_UCT_H

#include <MCTSBase.h>

class UCT:MCTSBase
{
    private:
        /* data */
    public:
        UCT(EnvironmentBase& environement);
        ~UCT();

        void run() override;
        
};

#endif //MCTS_LIBRARY_UCT_H