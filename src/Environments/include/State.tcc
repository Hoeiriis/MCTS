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

template <typename T> T State::getData() const {
    // TODO: wrap in try-catch
    return std::any_cast<T>(m_data->getData());
}

#endif // STATE_TCC
