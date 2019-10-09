#ifndef MCTS_LIBRARY_TREEPOLICYBASE_H
#define MCTS_LIBRARY_TREEPOLICYBASE_H

#include "../../include/SearchNode.h"
#include <boost/function.hpp>

class TreePolicyBase
{
    public:
        TreePolicyBase(boost::function<SearchNode(SearchNode)> &expand, boost::function<SearchNode(SearchNode)> &bestChild);
        virtual SearchNode treePolicy(SearchNode);

    protected:
        boost::function<SearchNode(SearchNode)> expand;
        boost::function<SearchNode(SearchNode)> bestChild;
};

#endif //MCTS_LIBRARY_TREEPOLICYBASE_H