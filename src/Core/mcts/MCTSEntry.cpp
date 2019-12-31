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

    uct.run(time_limit_sec);

    terminalNodeScores = uct.getBestTerminalNodeScore();

    if(terminalNodeScores.empty()){
        std::cout << "No terminal node was found in the compute time given." << std::endl;
    } else {
        auto termNode = terminalNodeScores.back();
        state_trace = compute_state_trace(termNode.node);
    }

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
