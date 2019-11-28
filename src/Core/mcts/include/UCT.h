#ifndef MCTS_LIBRARY_UCT_H
#define MCTS_LIBRARY_UCT_H

#include <MCTSInterface.h>
#include <RandomSamplingDefaultPolicy.h>
#include <BasicBackup.h>
#include <UCT_TreePolicy.h>

using namespace std::placeholders;

class UCT : MCTSInterface {
  public:
    explicit UCT(EnvironmentBase &environment);
    ;

  protected:
    std::shared_ptr<SearchNode> m_tree_policy(std::shared_ptr<SearchNode> node) override;
    Reward m_default_policy(State &state) override;
    std::shared_ptr<SearchNode> m_best_child(std::shared_ptr<SearchNode> node, double c) override;
    void m_backpropagation(std::shared_ptr<SearchNode> node, Reward score) override;
    std::shared_ptr<SearchNode> m_expand(std::shared_ptr<SearchNode> node) override;


  private:

    UCT_TreePolicy m_tpolicy = UCT_TreePolicy(f_expand, f_best_child);

    std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>)> f_expand =
            std::bind(&UCT::m_expand, this, _1);

    std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>, double)> f_best_child =
            std::bind(&UCT::m_best_child, this, _1, _2);



    BasicBackup m_backup = BasicBackup();

    RandomSamplingDefaultPolicy m_defaultPolicy =
            RandomSamplingDefaultPolicy(getValidChildStates, evaluateTerminalStates);

    std::function<std::vector<State>(State &)> getValidChildStates =
        std::bind(&EnvironmentBase::GetValidChildStates, &m_environment, _1);

    std::function<Reward(State &)> evaluateTerminalStates =
        std::bind(&EnvironmentBase::EvaluateTerminalState, &m_environment, _1);
};

#endif // MCTS_LIBRARY_UCT_H
