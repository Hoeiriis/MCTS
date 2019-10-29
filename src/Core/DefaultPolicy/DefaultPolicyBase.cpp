#include <DefaultPolicyBase.h>

DefaultPolicyBase::DefaultPolicyBase(boost::function<States(State<boost::any> &)> &getValidChildStates,
                                     boost::function<Reward(State<boost::any> &)> &evaluateTerminalState)
    : getValidChildStates(getValidChildStates), evaluateTerminalState(evaluateTerminalState){};