//
// Created by happysun on 01/10/2019.
//

#ifndef MCTS_LIBRARY_MCTSBASE_H
#define MCTS_LIBRARY_MCTSBASE_H

#include <EnvironmentBase.h>
#include <SearchNode.h>
#include <State.h>
#include <boost/any.hpp>
#include <boost/function.hpp>

class MCTSBase {
  public:
    MCTSBase(EnvironmentBase<boost::any> &environment, boost::function<int(State<boost::any>)> default_policy);

    void run(int n_searches);

  protected:
    virtual SearchNode search(int n_searches) = 0;

    EnvironmentBase<boost::any> &m_environment;
    SearchNode m_root;
};

#endif // MCTS_LIBRARY_MCTSBASE_H
