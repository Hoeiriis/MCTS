#include <TreePolicyBase.h>

TreePolicyBase::TreePolicyBase(std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>)> &expand,
                               std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>)> &bestChild)
    : m_expand(expand), m_bestChild(bestChild){};
