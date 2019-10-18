#ifndef MCTS_LIBRARY_SEARCHNODE_H
#define MCTS_LIBRARY_SEARCHNODE_H
#include <State.h>
#include <boost/any.hpp>

class SearchNode {
    public:
        SearchNode(SearchNode *parent_node, State<boost::any> &state);
        int visits;
        double score;
        State<boost::any> state;
        std::vector<State<boost::any>> unvisited_child_states;
        SearchNode *parent;
        std::vector<SearchNode> child_nodes;
        

        void add_child(SearchNode &child_node);
        void set_unvisited_child_states(std::vector<State<boost::any>> &possible_child_states);
};


#endif //MCTS_LIBRARY_SEARCHNODE_H
