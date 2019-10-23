#include <BasicBackup.h>

BasicBackup::BasicBackup(SearchNode *node, Reward defaultPolicyScore) : BackupBase(node, defaultPolicyScore) {
    std::vector<SearchNode *> ancestorList = {};
    this->ancestors = getAncestors(node, ancestorList);
};

void BasicBackup::backup(){
    for(SearchNode* currentNode:this->ancestors){
        currentNode->visits+=1;
        currentNode->score+=defaultPolicyScore;
        

    }
} 