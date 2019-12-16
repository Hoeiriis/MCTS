/*
 *  Copyright Peter G. Jensen, all rights reserved.
 */

/* 
 * File:   MCTSEntry.h
 * Author: Peter G. Jensen <root@petergjoel.dk>
 *
 * Created on December 12, 2019, 10:27 AM
 */

#ifndef MCTSENTRY_H
#define MCTSENTRY_H

#include <EnvironmentBase.h>

class MCTSEntry {
protected:
    EnvironmentBase& _environment;
public:
    explicit MCTSEntry(EnvironmentBase& env);
    bool run();
};


#endif /* MCTSENTRY_H */

