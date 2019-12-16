/*
 *  Copyright Peter G. Jensen, all rights reserved.
 */



#include <MCTSEntry.h>
#include <UCT.h>

MCTSEntry::MCTSEntry(EnvironmentBase& env) : _environment(env)
{
}


bool MCTSEntry::run()
{
    auto uct = UCT(_environment);
    auto endState = uct.run(5000);

    return true;
}
