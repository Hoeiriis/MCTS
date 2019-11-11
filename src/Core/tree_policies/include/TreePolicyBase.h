#ifndef MCTS_LIBRARY_TREEPOLICYBASE_H
#define MCTS_LIBRARY_TREEPOLICYBASE_H

#include <SearchNode.h>
#include <functional>
#include <memory>

class TreePolicyBase {
  public:
    TreePolicyBase(std::function<std::shared_ptr<SearchNode>(SearchNode*)> &expand, std::function<std::shared_ptr<SearchNode>(SearchNode*)> &bestChild);
    virtual std::shared_ptr<SearchNode> treePolicy(SearchNode *node) = 0;

  protected:
    std::function<std::shared_ptr<SearchNode>(SearchNode*)> m_expand;
    std::function<std::shared_ptr<SearchNode>(SearchNode*)> m_bestChild;
};

#endif // MCTS_LIBRARY_TREEPOLICYBASE_H
