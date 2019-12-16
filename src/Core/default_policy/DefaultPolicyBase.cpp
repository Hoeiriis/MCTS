#include <DefaultPolicyBase.h>

DefaultPolicyBase::DefaultPolicyBase(std::function<std::vector<State>(State &)> &getValidChildStates,
                                     std::function<Reward(State &)> &evaluateTerminalState)
    : getValidChildStates(getValidChildStates), evaluateTerminalState(evaluateTerminalState),
      generator(std::mt19937(time(nullptr))){};