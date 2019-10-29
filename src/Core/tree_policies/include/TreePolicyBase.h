#ifndef MCTS_LIBRARY_TREEPOLICYBASE_H
#define MCTS_LIBRARY_TREEPOLICYBASE_H

#include <SearchNode.h>
#include <boost/function.hpp>

class TreePolicyBase {
  public:
    TreePolicyBase(boost::function<SearchNode(SearchNode)> &expand, boost::function<SearchNode(SearchNode)> &bestChild);
    virtual SearchNode treePolicy(SearchNode &node);

  protected:
    boost::function<SearchNode(SearchNode)> m_expand;
    boost::function<SearchNode(SearchNode)> m_bestChild;
};

#endif // MCTS_LIBRARY_TREEPOLICYBASE_H
