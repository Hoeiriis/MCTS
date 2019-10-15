#include <DefaultPolicyBase.h>

using namespace boost;

DefaultPolicyBase::DefaultPolicyBase(function<States(State&)> getValidChildStates,
                                     function<Reward(State&)> evaluateTerminalState):
                                     getValidChildStates(getValidChildStates),
                                     evaluateTerminalState(evaluateTerminalState){}