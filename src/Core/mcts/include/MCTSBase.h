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

    inline std::shared_ptr<SearchNode> getRoot() { return m_root; }
    inline std::shared_ptr<SearchNode> getOriginalRoot(){return tree_original_root;}


  protected:
    std::shared_ptr<SearchNode> m_search(int n_searches) override;
    std::shared_ptr<SearchNode> unroll_search();


    virtual std::shared_ptr<SearchNode> m_tree_policy(std::shared_ptr<SearchNode> node) = 0;
    virtual Reward m_default_policy(State &state) = 0;
    virtual std::shared_ptr<SearchNode> m_best_child(std::shared_ptr<SearchNode> node, double c) = 0;
    virtual std::shared_ptr<SearchNode> m_expand(std::shared_ptr<SearchNode> node) = 0;
    virtual void m_backpropagation(std::shared_ptr<SearchNode> node, Reward score) = 0;

    std::shared_ptr<SearchNode> m_root;
    std::shared_ptr<SearchNode> tree_original_root;

    EnvironmentInterface &m_environment;
};

#endif // MCTS_LIBRARY_MCTSBASE_H
