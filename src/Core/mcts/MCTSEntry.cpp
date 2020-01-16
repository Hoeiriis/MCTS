/*
 *  Copyright Peter G. Jensen, all rights reserved.
 */
#include <MCTSEntry.h>
#include <UCT_UPPAAL.h>
#include <queue>
#include <stack>

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

    states_explored = count_states(uct.root_node);

    return true;
}

int MCTSEntry::count_states(std::shared_ptr<SearchNode> &root) {

    int count = 1;

    std::queue<std::shared_ptr<SearchNode>> nodeQueue{};
    std::shared_ptr<SearchNode>& currentNode = root;

    while (count == 1 || !nodeQueue.empty()){
        auto children = currentNode->child_nodes;
        for(auto& child : children){
            nodeQueue.push(child);
            count ++;
        }

        currentNode = nodeQueue.front();
        nodeQueue.pop();
    }

    return count;
}


bool MCTSEntry::bfs(){

    std::queue<State> stateQueue{};
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
            if (terminalNodeScores.empty() || terminalNodeScores.back().score < termReward){
                auto newBestNode = TerminalNodeScore();
                newBestNode.score = termReward;
                newBestNode.node = nullptr;
                newBestNode.time_to_find = (time(nullptr) - max_start);
                // insert at beginning
                terminalNodeScores.push_back(newBestNode);
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

bool MCTSEntry::dfs() {

    std::stack<State> stateStack{};
    State rootState = _environment.GetStartState();

    time_t max_start = time(nullptr);
    long max_time = time_limit_sec;
    long max_timeLeft = max_time;

    int states_unrolled = 0;
    auto generator = std::mt19937(time(nullptr));

    State currentState = nullptr;

    while (max_timeLeft > 0){

        std::vector<State> unvisited_child_states = _environment.GetValidChildStates(rootState);
        bool isTerminal = false;

        // do random depth first search
        while (states_unrolled < 100000 && (!unvisited_child_states.empty()) && (!isTerminal)) {
            std::uniform_int_distribution<int> uniformIntDistribution(0, unvisited_child_states.size() - 1);
            int i_random = uniformIntDistribution(generator);
            currentState = unvisited_child_states[i_random];

            // Fetch info from the new child state
            unvisited_child_states = _environment.GetValidChildStates(currentState);
            isTerminal = _environment.IsTerminal(currentState);
            states_unrolled++;
        }

        states_unrolled = 0;

        if(isTerminal){
            Reward termReward = _environment.EvaluateRewardFunction(currentState);
            if (terminalNodeScores.empty() || terminalNodeScores.back().score < termReward){
                auto newBestNode = TerminalNodeScore();
                newBestNode.score = termReward;
                newBestNode.node = nullptr;
                newBestNode.time_to_find = (time(nullptr) - max_start);
                // insert at beginning
                terminalNodeScores.push_back(newBestNode);
            }
        }

        max_timeLeft = max_time - (time(nullptr) - max_start);
    }

    if(terminalNodeScores.empty()){
        std::cout << "No terminal node was found in the compute time given." << std::endl;
    } else {
        auto termNode = terminalNodeScores.back();
    }

    return true;
}


void MCTSEntry::dfsLoop(State& currentState, int levels){



    std::vector<State> unvisited_child_states = _environment.GetValidChildStates(currentState);
    for (auto unvisited_child_state : unvisited_child_states) {
        dfsLoop(unvisited_child_state, levels+1);
    }
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
