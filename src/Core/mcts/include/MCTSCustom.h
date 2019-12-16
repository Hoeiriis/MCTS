#ifndef MCTS_LIBRARY_MCTSCUSTOM_H
#define MCTS_LIBRARY_MCTSCUSTOM_H

#include <EnvironmentInterface.h>
#include <SearchNode.h>
#include <State.h>
#include <functional>
#include <memory>

class MCTSCustom {
  public:
    MCTSCustom(EnvironmentInterface &environment,
               std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>)> &tree_policy,
               std::function<Reward(State)> &default_policy,
               std::function<void(std::shared_ptr<SearchNode>, int)> &backpropagation,
               std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>)> &best_child);

    void run(int n_searches);
    //EnvironmentInterface& getEnvironemnt();

  protected:
    std::shared_ptr<SearchNode> search(int n_searches);

    EnvironmentInterface &m_environment;
    std::shared_ptr<SearchNode> m_root;

    std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>)> m_tree_policy;
    std::function<Reward(State)> m_default_policy;
    std::function<void(std::shared_ptr<SearchNode>, int)> m_backpropagation;
    std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>)> m_best_child;
};

#endif //MCTS_LIBRARY_MCTSCUSTOM_H
