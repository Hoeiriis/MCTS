#ifndef MCTS_LIBRARY_UCT_TREEPOLICY_H
#define MCTS_LIBRARY_UCT_TREEPOLICY_H

#include <TreePolicyBase.h>

class UCT_TreePolicy : TreePolicyBase {
  public:
    UCT_TreePolicy(std::function<std::shared_ptr<SearchNode>(SearchNode*)> &expand, std::function<std::shared_ptr<SearchNode>(SearchNode*)> &bestChild)
        : TreePolicyBase(expand, bestChild){};

    std::shared_ptr<SearchNode> treePolicy(SearchNode *node) override;
};

#endif // MCTS_LIBRARY_UCT_TREEPOLICY_H
