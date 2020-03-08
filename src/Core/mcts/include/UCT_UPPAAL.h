//
// Created by happysun on 27/12/2019.
//

#ifndef MCTS_UCT_UPPAAL_H
#define MCTS_UCT_UPPAAL_H


#include "MCTSInterface.h"
#include <functional>
#include <BasicBackup.h>
#include <random>
#include <UCT_TreePolicy.h>
#include <UPPAAL_RandomSamplingDefaultPolicy.h>

class TerminalNodeScore {
    public:
        //TerminalNodeScore(std::shared_ptr<SearchNode> &terminalNode, double terminalScore):node{terminalNode}, score(terminalScore){}

        std::shared_ptr<SearchNode> node;
        double score;
        long time_to_find;
};

class UCT_UPPAAL : public MCTSInterface {
    public:
        explicit UCT_UPPAAL(EnvironmentInterface &environment);
        State run(int n_searches) override;
        inline EnvironmentInterface &getEnvironment() override { return _environment; }
        inline std::vector<TerminalNodeScore> &getBestTerminalNodeScore() { return bestTerminalNodesFound; }

        std::shared_ptr<SearchNode> root_node;
        std::shared_ptr<SearchNode> last_expanded_node;

        std::mt19937 generator;



protected:
        Reward m_default_policy(State &state) override;
        std::shared_ptr<SearchNode> m_search(int n_searches) override;
        std::shared_ptr<SearchNode> m_tree_policy(std::shared_ptr<SearchNode> node) override;
        std::shared_ptr<SearchNode> m_best_child(std::shared_ptr<SearchNode> node, double c) override;
        std::shared_ptr<SearchNode> m_expand(std::shared_ptr<SearchNode> node) override;
        void m_backpropagation(std::shared_ptr<SearchNode> node, Reward score) override;

        EnvironmentInterface &_environment;
        bool best_proved = false;
        std::vector<TerminalNodeScore> bestTerminalNodesFound;



    private:
        // UCT Backup setup
        BasicBackup _backup = BasicBackup();

        // UCT TreePolicy setup
        std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode> node)> placeholderFunc =
                [](std::shared_ptr<SearchNode> node) { return node; };

        std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode> node, double c)> placeholderFunc2 =
                [](std::shared_ptr<SearchNode> node, double c) { return node; };

        UCT_TreePolicy _tpolicy = UCT_TreePolicy(placeholderFunc, placeholderFunc2);

        // UCT Default Policy setup
        UPPAAL_RandomSamplingDefaultPolicy _defaultPolicy;

        //Reward min/max
        std::pair<double,double> rewardMinMax = {0, 0};
};


#endif //MCTS_UCT_UPPAAL_H
