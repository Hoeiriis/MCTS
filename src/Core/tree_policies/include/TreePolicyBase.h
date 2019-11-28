#ifndef MCTS_LIBRARY_TREEPOLICYBASE_H
#define MCTS_LIBRARY_TREEPOLICYBASE_H

#include <SearchNode.h>
#include <functional>
#include <memory>

class TreePolicyBase {
  public:
    TreePolicyBase(std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>)> &expand, std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>, double)> &bestChild);
    virtual std::shared_ptr<SearchNode> treePolicy(std::shared_ptr<SearchNode> node) = 0;

  protected:
    std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>)> m_expand;
    std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>, double)> m_bestChild;
};

#endif // MCTS_LIBRARY_TREEPOLICYBASE_H
