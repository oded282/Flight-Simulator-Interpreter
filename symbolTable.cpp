
#include <map>
#include "Commands.h"
#include "symbolTable.h"

/*
 * This func add new command to the map.
 */
void symbolTable::addVar(Var* value){

    string name = value->getName();
    symbolMap[name] = value;
}


/*
 * This func return the command if exist
 */
Var* symbolTable::getVar(string symbol){
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
    if(symbolMap.find(symbol) != symbolMap.end()){
        return symbolMap[symbol]->getSentence();
    }
    symbolMap.erase(symbol);
    return nullptr;
}
/*
 * This func returns the all map.
 */
map<string, Var*>& symbolTable::getSymbolMap() {
    return symbolMap;
}

/*
 * return the var by the path.
 */
Var* symbolTable::getVarByPath(string path) {

    map<string , Var*>::iterator it;
    for (it = symbolMap.begin() ; it != symbolMap.end(); it++){
        if (it->second->getSentence() == path){
            return it->second;
        }
    }
    return nullptr;
}