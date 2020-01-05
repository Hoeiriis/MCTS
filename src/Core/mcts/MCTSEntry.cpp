/*
 *  Copyright Peter G. Jensen, all rights reserved.
 */
#include <MCTSEntry.h>
#include <UCT_UPPAAL.h>
#include <queue>

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

bool MCTSEntry::bfs(){

    std::queue<State> stateQueue{};
    std::vector<TerminalNodeScore> termsFound;
    State currentState = _environment.GetStartState();

    time_t max_start = time(nullptr);
    long max_time = time_limit_sec;
    long max_timeLeft = max_time;

    while (max_timeLeft > 0){

        std::vector<State> unvisited_child_states = _environment.GetValidChildStates(currentState);
        for (const auto & unvisited_child_state : unvisited_child_states) {
            stateQueue.push(unvisited_child_state);
        }

        if(_environment.IsTerminal(currentState)){
            Reward termReward = _environment.EvaluateRewardFunction(currentState);
            if (termsFound.empty() || termsFound.back().score < termReward){
                auto newBestNode = TerminalNodeScore();
                newBestNode.score = termReward;
                newBestNode.node = nullptr;
                newBestNode.time_to_find = (time(nullptr) - max_start);
                // insert at beginning
                termsFound.push_back(newBestNode);
            }
        }

        currentState = stateQueue.front();
        stateQueue.pop();

        max_timeLeft = max_time - (time(nullptr) - max_start);
    }

    if(terminalNodeScores.empty()){
        std::cout << "No terminal node was found in the compute time given." << std::endl;
    } else {
        auto termNode = terminalNodeScores.back();
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
