#ifndef MCTS_LIBRARY_UCT_TREEPOLICY_H
#define MCTS_LIBRARY_UCT_TREEPOLICY_H

#include <TreePolicyBase.h>

class UCT_TreePolicy : TreePolicyBase {
  public:
    UCT_TreePolicy(std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>)> &expand,
                   std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>, double)> &bestChild)
        : TreePolicyBase(expand, bestChild){};

    std::shared_ptr<SearchNode> treePolicy(std::shared_ptr<SearchNode> node) override;

    ~UCT_TreePolicy();
};

#endif // MCTS_LIBRARY_UCT_TREEPOLICY_H
