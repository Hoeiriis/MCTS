/*
 *  Copyright Peter G. Jensen, all rights reserved.
 */



#include <MCTSEntry.h>
#include <UCT.h>

MCTSEntry::MCTSEntry(EnvironmentInterface& env) : _environment(env)
{
}


bool MCTSEntry::run()
{
    auto uct = UCT(_environment);

    int sec = 30;
    auto endNode = uct.search_time_limit(sec);
    state_trace = compute_state_trace(endNode);

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
