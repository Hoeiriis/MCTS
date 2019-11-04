#ifndef MCTS_LIBRARY_STATE_H
#define MCTS_LIBRARY_STATE_H

#include <any>
#include <memory>

/*
 * @brief      The State "interface" used for type erasure in the State class.
 *
 * @details    The functionality interface of State. It is necessary for type erasure
 * in State, and should only be used if one wants to extend State.
 */
struct StateConcept {
    virtual ~StateConcept() {}
    virtual std::any getData() const = 0;
};

template <typename T> struct StateModel : StateConcept {
    StateModel(const T &t) : m_data(t) {}

    std::any getData() const override { return m_data; }

  private:
    T m_data;
};

class State {
  public:
    template <typename T> State(T data) : m_data(std::make_unique<StateModel<T>>(data)){};

    template <typename T> T getData() const;

  protected:
    std::shared_ptr<const StateConcept> m_data;
};

#include "State.tcc"
#endif
