#ifndef MCTS_LIBRARY_UCT_H
#define MCTS_LIBRARY_UCT_H

#include <MCTSBase.h>
#include <boost/any.hpp>

class UCT:MCTSBase
{
    private:
        /* data */
    public:
        UCT(EnvironmentBase& environement, boost::function<int(State)> default_policy);
        ~UCT();

        void run(int n_searches);

};

#endif //MCTS_LIBRARY_UCT_H
