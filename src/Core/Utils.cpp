#include <Utils.h>

void Utils::print_tree_trace(std::shared_ptr<SearchNode> &node,
                             std::function<std::vector<std::string>(State &)> statePrintFunction) {
    temp_print_bind = statePrintFunction;

    std::vector<std::string> print_vec{};

}


std::vector<std::string> Utils::prepare_nodes_child_level(SearchNode &node) {

    std::vector<std::string> result_vec{};

    // check if node actually has any children, if not return empty vector
    if(node.child_nodes.empty()){
        return result_vec;
    } else {
        int n_children = node.child_nodes.size();

        auto first_state = temp_print_bind(node.child_nodes.at(0)->state);
        int n_print_levels = first_state.size();

        // add first state representation to result_vec
        for(const auto& state_str : first_state){
            result_vec.push_back(state_str);
        }

        // add following state representations to result_vec
        for (int i = 1; i < n_children; ++i) {
            auto current_state_rep = temp_print_bind(node.child_nodes.at(i)->state);

            // concatenate current strings with 3 spaces and the next state representation
            for (int j = 0; j < n_print_levels; ++j) {
                result_vec.at(j) = result_vec.at(j) + "   " + current_state_rep.at(j);
            }

        }

        // finally add newlines to all strings
        for(std::string done_str : result_vec){
            done_str.append("\n");
        }
    }

    return result_vec;
}
