#ifndef MCTS_LIBRARY_MCTSINTERFACE_H
#define MCTS_LIBRARY_MCTSINTERFACE_H

#include <EnvironmentBase.h>
#include <SearchNode.h>
#include <State.h>

class MCTSInterface {
  public:
    explicit MCTSInterface(EnvironmentBase &environment);

    void run(int n_searches);

  protected:
    std::shared_ptr<SearchNode> m_search(int n_searches);
    virtual std::shared_ptr<SearchNode> m_tree_policy(std::shared_ptr<SearchNode> node) = 0;
    virtual Reward m_default_policy(State &state) = 0;
    virtual std::shared_ptr<SearchNode> m_best_child(std::shared_ptr<SearchNode> node, double c) = 0;
    virtual std::shared_ptr<SearchNode> m_expand(std::shared_ptr<SearchNode> node) = 0;
    virtual void m_backpropagation(std::shared_ptr<SearchNode> node, Reward score) = 0;

    EnvironmentBase &m_environment;
    std::shared_ptr<SearchNode> m_root;
};

#endif // MCTS_LIBRARY_MCTSINTERFACE_H
