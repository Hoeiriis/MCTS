#ifndef MCTS_LIBRARY_UCT_H
#define MCTS_LIBRARY_UCT_H

#include <MCTSInterface.h>
#include <boost/any.hpp>
#include <UCT_treePolicy.h>
#include <RandomDefaultPolicy.h>

class UCT : MCTSInterface {
  public:
    UCT(EnvironmentBase<boost::any> &environement);
};

#endif // MCTS_LIBRARY_UCT_H
