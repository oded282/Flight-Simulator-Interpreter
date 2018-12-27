
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
    //cout << "lock add var" << endl;
    string name = value->getName();
    symbolMap[name] = value;
    //cout << "unlock add var" << endl;
    // unlock thread.
    pthread_mutex_unlock(&mutex);

}


/*
 * This func return the command if exist
 */

VarCommand *symbolTable::getVar(string symbol) {
    // lock thread.
    pthread_mutex_lock(&mutex);
    //cout << "lock gat var" << endl;
    if (symbolMap.find(symbol) != symbolMap.end()) {
        VarCommand* v = symbolMap[symbol];
      //  cout << "unlock gat var" << endl;
        // unlock thread.
        pthread_mutex_unlock(&mutex);
        return v;
    }
    symbolMap.erase(symbol);
    //cout << "unlock get var" << endl;
    // unlock thread.
    pthread_mutex_unlock(&mutex);
    return nullptr;
}

Expression *symbolTable::getVarValue(string symbol) {
// lock thread.
    pthread_mutex_lock(&mutex);
    //cout << "lock add var" << endl;
    if (symbolMap.find(symbol) != symbolMap.end()) {
        Expression* e = symbolMap[symbol]->getValue();
      //  cout << "unlock var value" << endl;
        // unlock thread.
        pthread_mutex_unlock(&mutex);
        return e;
    }
    symbolMap.erase(symbol);
    //cout << "unlock var value" << endl;
    // unlock thread.
    pthread_mutex_unlock(&mutex);
    return nullptr;

}

string symbolTable::getVarPath(string symbol) {
     // lock thread.
     pthread_mutex_lock(&mutex);
    // cout << "lock var path"<<endl;
    if (symbolMap.find(symbol) != symbolMap.end()) {
        string path = symbolMap[symbol]->getSentence();
      //  cout << "unlock var path" << endl;
        // unlock thread.
        pthread_mutex_unlock(&mutex);
        return path;
    }
    symbolMap.erase(symbol);
    //cout << "unlock var path" << endl;
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
    //cout << "lock get var by path"<<endl;
    map<string, VarCommand *>::iterator it;
    for (it = symbolMap.begin(); it != symbolMap.end(); it++) {
        if (it->second->getSentence() == path) {
            VarCommand* v = it->second;
      //      cout << "lock get var by path" << endl;
            // unlock thread.
            pthread_mutex_unlock(&mutex);
            return v;
        }
    }
    //cout << "unlock get var by path" << endl;
    // unlock thread.
    pthread_mutex_unlock(&mutex);
    return nullptr;
}