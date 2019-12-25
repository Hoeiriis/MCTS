#ifndef MCTS_LIBRARY_MCTSINTERFACE_H
#define MCTS_LIBRARY_MCTSINTERFACE_H

#include <EnvironmentInterface.h>
#include <SearchNode.h>
#include <State.h>

class MCTSInterface {
  public:
    virtual State run(int n_searches) = 0;
    virtual EnvironmentInterface &getEnvironment() = 0;

  protected:
    virtual std::shared_ptr<SearchNode> m_search(int n_searches) = 0;
    virtual std::shared_ptr<SearchNode> m_tree_policy(std::shared_ptr<SearchNode> node) = 0;
    virtual Reward m_default_policy(State &state) = 0;
    virtual std::shared_ptr<SearchNode> m_best_child(std::shared_ptr<SearchNode> node, double c) = 0;
    virtual std::shared_ptr<SearchNode> m_expand(std::shared_ptr<SearchNode> node) = 0;
    virtual void m_backpropagation(std::shared_ptr<SearchNode> node, Reward score) = 0;

    std::shared_ptr<SearchNode> m_root;
};

#endif // MCTS_LIBRARY_MCTSINTERFACE_H
