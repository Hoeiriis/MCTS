/*
 *  Copyright Peter G. Jensen, all rights reserved.
 */
#include <MCTSEntry.h>
#include <UCT_UPPAAL.h>

MCTSEntry::MCTSEntry(EnvironmentInterface& env) : _environment(env)
{
}


bool MCTSEntry::run()
{
    UCT_UPPAAL uct = UCT_UPPAAL(_environment);

    int min = 60;
    int time_limit_sec = 1*min;

    uct.run(time_limit_sec);
    auto termNode = uct.getBestTerminalNodeScore().at(0);
    state_trace = compute_state_trace(termNode.node);

    return true;
}


std::vector<State> MCTSEntry::compute_state_trace(const std::shared_ptr<SearchNode>& endNode) {
    std::vector<State> trace{endNode->state};

    auto current_node = endNode->parent;
    while(current_node->parent){
        trace.insert(trace.begin(), current_node->state);
        current_node = current_node->parent;
    }
    return trace;
}
