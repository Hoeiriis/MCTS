/*
 *  Copyright Peter G. Jensen, all rights reserved.
 */

/* 
 * File:   MCTSEntry.h
 * Author: Peter G. Jensen <root@petergjoel.dk>
 *
 * Created on December 12, 2019, 10:27 AM
 */

#ifndef MCTSENTRY_H
#define MCTSENTRY_H

#include <EnvironmentInterface.h>
#include <SearchNode.h>
#include "UCT_UPPAAL.h"

class MCTSEntry {

public:
    explicit MCTSEntry(EnvironmentInterface& env);
    std::vector<State> state_trace{};
    bool run();
    int time_limit_sec = 10;
    std::vector<TerminalNodeScore> terminalNodeScores;

protected:
    EnvironmentInterface& _environment;
    std::vector<State> compute_state_trace(const std::shared_ptr<SearchNode>& final_node);
};


#endif /* MCTSENTRY_H */

