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
    MCTSBase(
    EnvironmentBase<boost::any> &environment,
    boost::function<SearchNode(SearchNode)> &tree_policy,
    boost::function<int(State<boost::any>)> &default_policy,
    boost::function<void(SearchNode, int)> &backpropagation);

    void run(int n_searches);

  protected:
    SearchNode search(int n_searches);

    EnvironmentBase<boost::any> &m_environment;
    boost::function<SearchNode(SearchNode)> &m_tree_policy;
    boost::function<int(State<boost::any>)> &m_default_policy;
    boost::function<void(SearchNode, int)> &m_backpropagation;
    SearchNode m_root;
};

#endif // MCTS_LIBRARY_MCTSBASE_H
