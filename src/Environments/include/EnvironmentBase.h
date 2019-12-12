/**
 *
 * @file EnvironmentBase.h
 *
 * @author Alexander Larsen
 *
 * @date 18 Oct 2019
 *
 * @brief Defines the minimum requirements for an environment
 *
 * @details Minimum requirements are as follows: evaluate whether a
 * state is terminal; get the initial configuration of the environment
 * and; get all possible child configurations of a given
 * configuration.
 *
 */

#ifndef ENVIRONMENTBASE_H
#define ENVIRONMENTBASE_H

#include <State.h>
#include <stdexcept>
#include <vector>

typedef double Reward;

/**
 * @brief      Defines barebones requirements for an environment
 *
 *
 *
 * @return     Environmentbase
 */
class EnvironmentBase {

  public:
    // EnvironmentBase();

    /**
     * @brief      Get the initial environment state
     *
     * @details    Every environment must define a starting state
     *
     * @return     State
     */
    virtual State GetStartState() = 0;
    virtual std::vector<State> GetValidChildStates(State &state) = 0;
    virtual Reward EvaluateTerminalState(State &state) = 0;
    virtual Reward EvaluateRewardFunction(State& state) = 0;
    virtual bool IsTerminal(State&) = 0;
};

#endif // ENVIRONMENTBASE_H
