#ifndef MCTS_LIBRARY_STATE_H
#define MCTS_LIBRARY_STATE_H

#include <any>
#include <memory>

struct Concept { // (5)
    virtual ~Concept() {}
    virtual std::any getData() const = 0;
};

template <typename T> struct Model : Concept {
    Model(const T &t) : m_data(t) {}

    std::any getData() const override { return m_data; }

  private:
    T m_data;
};

class State {
  public:
    template <typename T> State(T data) : m_data(std::make_shared<Model<T>>(std::move(data))){};

    template <typename T> T getData() const;

  protected:
    std::shared_ptr<const Concept> m_data;
};

#include "State.tcc"
#endif
