#include <TreePolicyBase.h>

TreePolicyBase::TreePolicyBase(boost::function<SearchNode(SearchNode)> &expand, boost::function<SearchNode(SearchNode)> &bestChild)
:m_expand(expand)
,m_bestChild(bestChild)
{};
