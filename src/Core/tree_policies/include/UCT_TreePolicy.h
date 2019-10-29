#ifndef MCTS_LIBRARY_UCT_TREEPOLICY_H
#define MCTS_LIBRARY_UCT_TREEPOLICY_H

#include <TreePolicyBase.h>

class UCT_TreePolicy : TreePolicyBase {
  public:
    UCT_TreePolicy(boost::function<SearchNode(SearchNode)> &expand, boost::function<SearchNode(SearchNode)> &bestChild)
        : TreePolicyBase(expand, bestChild){};

    SearchNode treePolicy(SearchNode &node);
};

#endif // MCTS_LIBRARY_UCT_TREEPOLICY_H
