
#include <map>
#include <iostream>
#include "../commands/Commands.h"
#include "symbolTable.h"
#include "../commands/VarCommand.h"

extern pthread_mutex_t mutex;

/*
 * This func add new command to the map.
 */
void symbolTable::addVar(VarCommand* value){
    // lock thread.
   // pthread_mutex_lock(&mutex);
  //  cout << "lock add var"<<endl;
    string name = value->getName();
    symbolMap[name] = value;
    //cout << "unlock add var"<<endl;
    // unlock thread.
   // pthread_mutex_unlock(&mutex);

}


/*
 * This func return the command if exist
 */
VarCommand* symbolTable::getVar(string symbol){
    if(symbolMap.find(symbol) != symbolMap.end()){
        return symbolMap[symbol];
    }
    symbolMap.erase(symbol);
    return nullptr;
}

Expression* symbolTable::getVarValue(string symbol){

    if(symbolMap.find(symbol) != symbolMap.end()){
        return symbolMap[symbol]->getValue();
    }
    symbolMap.erase(symbol);
    return nullptr;

}

string symbolTable::getVarPath(string symbol){
    // lock thread.
   // pthread_mutex_lock(&mutex);
   // cout << "lock add var"<<endl;
    if(symbolMap.find(symbol) != symbolMap.end()){
        return symbolMap[symbol]->getSentence();
    }
    symbolMap.erase(symbol);
    return nullptr;

}
/*
 * This func returns the all map.
 */
map<string, VarCommand*>& symbolTable::getSymbolMap() {
    // lock thread.
    //pthread_mutex_lock(&mutex);
    cout << "lock add var"<<endl;

    return symbolMap;

}

/*
 * return the var by the path.
 */
VarCommand* symbolTable::getVarByPath(string path) {
    // lock thread.
    //pthread_mutex_lock(&mutex);
    //cout << "lock add var"<<endl;
    map<string , VarCommand*>::iterator it;
    for (it = symbolMap.begin() ; it != symbolMap.end(); it++){
        if (it->second->getSentence() == path){
            return it->second;
        }
    }
    return nullptr;
}