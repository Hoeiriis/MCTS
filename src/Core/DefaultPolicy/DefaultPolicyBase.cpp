#include <DefaultPolicyBase.h>

<<<<<<< HEAD
DefaultPolicyBase::DefaultPolicyBase(boost::function<States(State<boost::any> &)> &getValidChildStates,
                                     boost::function<Reward(State<boost::any> &)> &evaluateTerminalState)
    : getValidChildStates(getValidChildStates), evaluateTerminalState(evaluateTerminalState){};
=======
DefaultPolicyBase::DefaultPolicyBase(boost::function<States(State&)>& getValidChildStates,
                                     boost::function<Reward(State&)>& evaluateTerminalState):
                                     getValidChildStates(getValidChildStates),
                                     evaluateTerminalState(evaluateTerminalState){};
>>>>>>> origin/master
