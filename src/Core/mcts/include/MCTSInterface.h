//
// Created by happysun on 01/10/2019.
//

#ifndef MCTS_LIBRARY_MCTSINTERFACE_H
#define MCTS_LIBRARY_MCTSINTERFACE_H

#include <EnvironmentBase.h>
#include <SearchNode.h>
#include <State.h>
#include <boost/any.hpp>
#include <boost/function.hpp>

class MCTSInterface {
  public:
    MCTSInterface(EnvironmentBase<boost::any> &environment);

    void run(int n_searches);

  protected:
    SearchNode search(int n_searches);
    virtual SearchNode tree_policy(SearchNode &node)=0;
    virtual int default_policy(State<boost::any> &state)=0;
    virtual SearchNode best_child(SearchNode &node)=0;
    virtual void backpropagation(SearchNode &node)=0;

    EnvironmentBase<boost::any> &m_environment;
};

#endif // MCTS_LIBRARY_MCTSINTERFACE_H
