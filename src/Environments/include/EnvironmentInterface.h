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

#ifndef ENVIRONMENTINTERFACE_H
#define ENVIRONMENTINTERFACE_H

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
class EnvironmentInterface {

  public:
    /**
     * @brief      Get the initial environment state
     *
     * @details    Every environment must define a starting state
     *
     * @return     State
     */
    virtual State GetStartState() = 0;

    /**
     * @brief      Return successor states of a state
     *
     * @details    Given a representation of a state, return a vector of all
     * possible successor states of that state.
     *
     * @param      &state
     *
     * @return     vector<state>
     */
    virtual std::vector<State> GetValidChildStates(State &state) = 0;

    /**
     * @brief      Evaluate a given states reward function
     *
     * @details    Given a state, computes a reward that should match the state with
     * the underlying reward function.
     *
     * @param      State&
     *
     * @return     double
     */
    virtual Reward EvaluateRewardFunction(State &state) = 0;

    /**
      * @brief      Evaluate wether a given states is a terminal state or not
      *
      * @details    Given a state, computes wether the state is a terminal state or not
      *
      * @param      State&
      *
      * @return     bool
      */

    virtual bool IsTerminal(State &state) = 0;
};

#endif // ENVIRONMENTINTERFACE_H
