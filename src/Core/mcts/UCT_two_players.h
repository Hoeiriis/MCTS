//
// Created by happysun on 05/12/2019.
//

#ifndef MCTS_LIBRARY_UCT_TWO_PLAYERS_H
#define MCTS_LIBRARY_UCT_TWO_PLAYERS_H


#include <UCT.h>
#include <BackupNegamax.h>

class UCT_two_players : public UCT {

public:
    explicit UCT_two_players(EnvironmentBase &environment);

    State run(int n_searches);

    int CurrentPlayer = 0;

protected:
    std::shared_ptr<SearchNode> m_best_child(std::shared_ptr<SearchNode> node, double c) override;
    std::shared_ptr<SearchNode> m_expand(std::shared_ptr<SearchNode> node) override;
    void m_backpropagation(std::shared_ptr<SearchNode> node, Reward score) override;


private:
    // UCT Two Player Backup
    BackupNegamax m_backup = BackupNegamax();
};


#endif //MCTS_LIBRARY_UCT_TWO_PLAYERS_H
