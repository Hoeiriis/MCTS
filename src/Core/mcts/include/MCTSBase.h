#ifndef MCTS_LIBRARY_MCTSBASE_H
#define MCTS_LIBRARY_MCTSBASE_H

#include <EnvironmentInterface.h>
#include <MCTSInterface.h>
#include <SearchNode.h>
#include <State.h>

class MCTSBase : public MCTSInterface {
  public:
    explicit MCTSBase(EnvironmentInterface &environment);
    State run(int n_searches);
    State run(int n_searches, State initial_state);
    EnvironmentInterface &getEnvironment();

    std::shared_ptr<SearchNode> m_root;
    std::shared_ptr<SearchNode> tree_original_root;

  protected:
    std::shared_ptr<SearchNode> m_search(int n_searches);
    virtual std::shared_ptr<SearchNode> m_tree_policy(std::shared_ptr<SearchNode> node) = 0;
    virtual Reward m_default_policy(State &state) = 0;
    virtual std::shared_ptr<SearchNode> m_best_child(std::shared_ptr<SearchNode> node, double c) = 0;
    virtual std::shared_ptr<SearchNode> m_expand(std::shared_ptr<SearchNode> node) = 0;
    virtual void m_backpropagation(std::shared_ptr<SearchNode> node, Reward score) = 0;

    EnvironmentInterface &m_environment;
};

#endif // MCTS_LIBRARY_MCTSBASE_H
