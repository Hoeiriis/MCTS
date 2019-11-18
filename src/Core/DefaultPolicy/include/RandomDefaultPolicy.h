#ifndef MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H
#define MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H

#include <DefaultPolicyBase.h>

typedef std::vector<State> States;

class RandomDefaultPolicy : DefaultPolicyBase {
  public:
<<<<<<< HEAD
    RandomDefaultPolicy(boost::function<States(State<boost::any> &)> &getValidChildStates,
                        boost::function<Reward(State<boost::any> &)> &evaluateTerminalState);
    ~RandomDefaultPolicy();
    virtual Reward defaultPolicy(State<boost::any>) override;
=======
    RandomDefaultPolicy(boost::function<States(State &)> &getValidChildStates,
                        boost::function<Reward(State &)> &evaluateTerminalState);
    ~RandomDefaultPolicy();

    virtual Reward defaultPolicy(State) override;
>>>>>>> origin/master

  private:
    States validStates;
};

<<<<<<< HEAD
#endif // MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H
=======
#endif // MCTS_LIBRARY_RANDOMDEFAULTPOLICY_H
>>>>>>> origin/master
