#ifndef MCTS_LIBRARY_STATE_H
#define MCTS_LIBRARY_STATE_H

template <class T>
class State
{
    public:
        State(T data):data(data){};
        T data;
};

#endif