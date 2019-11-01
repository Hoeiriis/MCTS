#include <State.h>

template<typename T>
T State::getData() const {                           
    //TODO: wrap in try-catch
    return std::any_cast<T>(m_data->getData());
}