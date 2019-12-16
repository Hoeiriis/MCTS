#ifndef MCTS_LIBRARY_UCT_H
#define MCTS_LIBRARY_UCT_H

#include <MCTSBase.h>
#include <RandomSamplingDefaultPolicy.h>
#include <BasicBackup.h>
#include <UCT_TreePolicy.h>

class UCT : MCTSBase {
  public:
    explicit UCT(EnvironmentInterface &environment);

  protected:
    std::shared_ptr<SearchNode> m_tree_policy(std::shared_ptr<SearchNode> node) override;
    Reward m_default_policy(State &state) override;
    std::shared_ptr<SearchNode> m_best_child(std::shared_ptr<SearchNode> node, double c) override;
    void m_backpropagation(std::shared_ptr<SearchNode> node, Reward score) override;
    std::shared_ptr<SearchNode> m_expand(std::shared_ptr<SearchNode> node) override;

    std::mt19937 generator;


  private:

    // UCT TreePolicy setup
    UCT_TreePolicy m_tpolicy = UCT_TreePolicy(f_expand, f_best_child);

    std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>)> f_expand =
            std::bind(&UCT::m_expand, this, std::placeholders::_1);

    std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>, double)> f_best_child =
            std::bind(&UCT::m_best_child, this, std::placeholders::_1, std::placeholders::_2);


    // UCT Backup setup
    BasicBackup m_backup = BasicBackup();


    // UCT Default Policy setup
    RandomSamplingDefaultPolicy m_defaultPolicy =
            RandomSamplingDefaultPolicy(m_environment);
};

#endif // MCTS_LIBRARY_UCT_H
