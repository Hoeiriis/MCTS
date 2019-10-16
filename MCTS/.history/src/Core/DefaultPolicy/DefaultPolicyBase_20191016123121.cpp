#include <DefaultPolicyBase.h>

DefaultPolicyBase::DefaultPolicyBase(boost::function<States(State&)>& getValidChildStates,
                                     boost::function<Reward(State&)>& evaluateTerminalState):
                                     getValidChildStates(getValidChildStates),
                                     evaluateTerminalState(evaluateTerminalState){};