#include <TreePolicyBase.h>

TreePolicyBase::TreePolicyBase(std::function<std::shared_ptr<SearchNode>(SearchNode&)> &expand,
                               std::function<std::shared_ptr<SearchNode>(SearchNode&)> &bestChild)
    : m_expand(expand), m_bestChild(bestChild){};
