#include <MCTSCustom.h>
#include <functional>
#include <memory>

MCTSCustom::MCTSCustom(EnvironmentInterface &environment,
                       std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>)> &tree_policy,
                       std::function<Reward(State)> &default_policy,
                       std::function<void(std::shared_ptr<SearchNode>, int)> &backpropagation,
                       std::function<std::shared_ptr<SearchNode>(std::shared_ptr<SearchNode>)> &best_child)
    : m_environment(environment), m_root(SearchNode::create_SearchNode(nullptr, false)), m_tree_policy(tree_policy),
      m_default_policy(default_policy), m_backpropagation(backpropagation), m_best_child(best_child){};

void MCTSCustom::run(int n_searches) {
    State initialState = m_environment.GetStartState();
    std::vector<State> unvisited_child_states = m_environment.GetValidChildStates(initialState);
    m_root = SearchNode::create_SearchNode(nullptr, initialState, false);

    while (!m_environment.GetValidChildStates(m_root->state).empty()) {
        m_root = search(n_searches);
    }
}


std::shared_ptr<SearchNode> MCTSCustom::search(int n_searches) {

    for (int i = 0; i < n_searches; i++) {
        // TreePolicy runs to find an unexpanded node to expand
        auto node_to_expand = m_tree_policy(m_root);
        // From the unexpanded node, a simulation runs that returns a score
        Reward simulation_score = m_default_policy(node_to_expand->state);
        // The score is backpropagated up through the search tree
        m_backpropagation(node_to_expand, simulation_score);
    }
}
