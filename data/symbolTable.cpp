
#include <map>
#include <iostream>
#include "../commands/Commands.h"
#include "symbolTable.h"
#include "../commands/VarCommand.h"

extern pthread_mutex_t mutex;

/*
 * This func add new command to the map.
 */
void symbolTable::addVar(VarCommand *value) {
    // lock thread.
    pthread_mutex_lock(&mutex);
    string name = value->getName();
    symbolMap[name] = value;
    // unlock thread.
    pthread_mutex_unlock(&mutex);

}


/*
 * This func return the command if exist
 */

VarCommand *symbolTable::getVar(string symbol) {
    // lock thread.
    pthread_mutex_lock(&mutex);
    if (symbolMap.find(symbol) != symbolMap.end()) {
        VarCommand* v = symbolMap[symbol];
        // unlock thread.
        pthread_mutex_unlock(&mutex);
        return v;
    }
    symbolMap.erase(symbol);
    // unlock thread.
    pthread_mutex_unlock(&mutex);
    return nullptr;
}

Expression *symbolTable::getVarValue(string symbol) {
// lock thread.
    pthread_mutex_lock(&mutex);
    if (symbolMap.find(symbol) != symbolMap.end()) {
        Expression* e = symbolMap[symbol]->getValue();
        // unlock thread.
        pthread_mutex_unlock(&mutex);
        return e;
    }
    symbolMap.erase(symbol);
    // unlock thread.
    pthread_mutex_unlock(&mutex);
    return nullptr;

}

string symbolTable::getVarPath(string symbol) {
     // lock thread.
     pthread_mutex_lock(&mutex);
    if (symbolMap.find(symbol) != symbolMap.end()) {
        string path = symbolMap[symbol]->getSentence();
        // unlock thread.
        pthread_mutex_unlock(&mutex);
        return path;
    }
    symbolMap.erase(symbol);
    // unlock thread.
    pthread_mutex_unlock(&mutex);
    return nullptr;
}

/*
 * This func returns the all map.
 */
map<string, VarCommand *> &symbolTable::getSymbolMap() {
    return symbolMap;
}

/*
 * return the var by the path.
 */
VarCommand *symbolTable::getVarByPath(string path) {
    // lock thread.
    pthread_mutex_lock(&mutex);
    map<string, VarCommand *>::iterator it;
    for (it = symbolMap.begin(); it != symbolMap.end(); it++) {
        if (it->second->getSentence() == path) {
            VarCommand* v = it->second;
            // unlock thread.
            pthread_mutex_unlock(&mutex);
            return v;
        }
    }
    // unlock thread.
    pthread_mutex_unlock(&mutex);
    return nullptr;
}