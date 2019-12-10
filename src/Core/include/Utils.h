#ifndef MCTS_LIBRARY_UTILS_H
#define MCTS_LIBRARY_UTILS_H

#include <SearchNode.h>
#include <functional>

class Utils {

  public:
    explicit Utils();
    static void print_tree_trace(std::shared_ptr<SearchNode> &node,
                                 std::function<std::vector<std::string>(State &)> statePrintFunction);

  private:

    static std::function<std::vector<std::string>(State &)> temp_print_bind;

    static std::vector<std::string> prepare_nodes_child_level(SearchNode &node);
};

#endif // MCTS_LIBRARY_UTILS_H