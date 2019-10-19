#include <TreePolicyBase.h>

TreePolicyBase::TreePolicyBase(boost::function<SearchNode(SearchNode)> &expand, boost::function<SearchNode(SearchNode)> &bestChild)
:expand(expand)
,bestChild(bestChild)
{};
