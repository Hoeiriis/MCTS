#ifndef MCTS_LIBRARY_MCTSBASE_H
#define MCTS_LIBRARY_MCTSBASE_H

#include <EnvironmentInterface.h>
#include <MCTSInterface.h>
#include <SearchNode.h>
#include <State.h>

class MCTSBase : public MCTSInterface {
  public:
    explicit MCTSBase(EnvironmentInterface &environment);
    State run(int n_searches) override ;
    State run(int n_searches, State initial_state);
    EnvironmentInterface &getEnvironment() override ;
    std::shared_ptr<SearchNode> search_iter_limit(int n_searches);
    std::shared_ptr<SearchNode> search_time_limit(int n_searches);

    std::shared_ptr<SearchNode> m_root;

  protected:
    std::shared_ptr<SearchNode> m_search(int n_searches) override;
    std::shared_ptr<SearchNode> unroll_search();


    EnvironmentInterface &m_environment;
};

#endif // MCTS_LIBRARY_MCTSBASE_H
