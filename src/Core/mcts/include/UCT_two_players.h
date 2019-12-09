//
// Created by happysun on 05/12/2019.
//

#ifndef MCTS_LIBRARY_UCT_TWO_PLAYERS_H
#define MCTS_LIBRARY_UCT_TWO_PLAYERS_H

#include <BackupNegamax.h>
#include <UCT.h>

class UCT_two_players : public MCTSBase {

  public:
    explicit UCT_two_players(EnvironmentBase &environment);

    State run(int n_searches);

    int CurrentPlayer = 0;

  protected:
    Reward m_default_policy(State &state) override;
    std::shared_ptr<SearchNode> m_tree_policy(std::shared_ptr<SearchNode> node) override;
    std::shared_ptr<SearchNode> m_best_child(std::shared_ptr<SearchNode> node, double c) override;
    std::shared_ptr<SearchNode> m_expand(std::shared_ptr<SearchNode> node) override;
    void m_backpropagation(std::shared_ptr<SearchNode> node, Reward score) override;

    std::mt19937 generator;

  private:
    // UCT Two Player Backup
    BackupNegamax m_backup = BackupNegamax();

    // UCT TreePolicy setup
    std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode> node)> placeholderFunc =
        [](std::shared_ptr<SearchNode> node) { return node; };

    std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode> node, double c)> placeholderFunc2 =
        [](std::shared_ptr<SearchNode> node, double c) { return node; };

    UCT_TreePolicy m_tpolicy = UCT_TreePolicy(placeholderFunc, placeholderFunc2);

    // UCT Default Policy setup
    std::function<std::vector<State>(State &)> placeholderDefFunc = [](State &state) {
        std::vector<State> retVec{state};
        return retVec;
    };

    std::function<Reward(State &)> placeholderDefFunc2 = [](State &state) { return 0.2; };

    RandomSamplingDefaultPolicy m_defaultPolicy = RandomSamplingDefaultPolicy(placeholderDefFunc, placeholderDefFunc2);
};

#endif // MCTS_LIBRARY_UCT_TWO_PLAYERS_H
