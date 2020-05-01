#ifndef MCTS_LIBRARY_STATE_H
#define MCTS_LIBRARY_STATE_H

#include <any>
#include <memory>
#include <iostream>

/*
 * @brief      The State "interface" used for type erasure in the State class.
 *
 * @details    The functionality interface of State. It is necessary for type erasure
 * in State, and should only be used if one wants to extend State.
 */


// https://stackoverflow.com/questions/22758291/how-can-i-detect-if-a-type-can-be-streamed-to-an-stdostream
template<typename S, typename T>
class is_streamable
{
    template<typename SS, typename TT>
    static auto test(int)
    -> decltype( std::declval<SS&>() << std::declval<TT>(), std::true_type() );

    template<typename, typename>
    static auto test(...) -> std::false_type;

public:
    static const bool value = decltype(test<S,T>(0))::value;
};

struct StateConcept {
    virtual ~StateConcept() {}
    virtual std::any getData() const = 0;
    virtual void print(std::ostream& os) const  = 0;

};

template <typename T> struct StateModel : StateConcept {
    StateModel(const T &t) : m_data(t) {}

    std::any getData() const override { return m_data; }
    void print(std::ostream& os) const 
    {
        if constexpr (is_streamable<std::stringstream, T>::value)
            std::cerr << m_data << std::endl;
    }
  private:
    T m_data;
};

class State {
  public:
    template <typename T> State(T data) : m_data(std::make_unique<StateModel<T>>(data)){};

    template <typename T> T getData() const;

    void print(std::ostream& o) const { if(m_data) m_data->print(o); }

  protected:
    std::shared_ptr<const StateConcept> m_data;
};

#include "State.tcc"
#endif
