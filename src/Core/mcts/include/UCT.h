#ifndef MCTS_LIBRARY_UCT_H
#define MCTS_LIBRARY_UCT_H

#include <BasicBackup.h>
#include <MCTSBase.h>
#include <RandomSamplingDefaultPolicy.h>
#include <UCT_TreePolicy.h>

class UCT : public MCTSBase {
  public:
    explicit UCT(EnvironmentInterface &environment);
    ~UCT()= default;

  protected:
    Reward m_default_policy(State &state) override;
    std::shared_ptr<SearchNode> m_tree_policy(std::shared_ptr<SearchNode> node) override;
    std::shared_ptr<SearchNode> m_best_child(std::shared_ptr<SearchNode> node, double c) override;
    std::shared_ptr<SearchNode> m_expand(std::shared_ptr<SearchNode> node) override;
    void m_backpropagation(std::shared_ptr<SearchNode> node, Reward score) override;

    std::mt19937 generator;

  private:
    // UCT Backup setup
    BasicBackup m_backup = BasicBackup();

    // UCT TreePolicy setup
    std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode> node)> placeholderFunc =
        [](std::shared_ptr<SearchNode> node) { return node; };

    std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode> node, double c)> placeholderFunc2 =
        [](std::shared_ptr<SearchNode> node, double c) { return node; };

    UCT_TreePolicy m_tpolicy = UCT_TreePolicy(placeholderFunc, placeholderFunc2);

    // UCT Default Policy setup
    RandomSamplingDefaultPolicy m_defaultPolicy;
};

#endif // MCTS_LIBRARY_UCT_H
