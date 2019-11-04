/**
 *
 * @file State.tcc
 *
 * @author Alexander Larsen
 *
 * @date 01 Nov 2019
 *
 * @brief Implement templates
 *
 * @details detailed description
 *
 */

#ifndef STATE_TCC
#define STATE_TCC

#include <iostream>

template <typename T> T State::getData() const {
    try {
        return std::any_cast<T>(m_data->getData());
    } catch (const std::bad_any_cast &e) {
        throw;
    }
}

#endif // STATE_TCC
