
#include <map>
#include "Commands.h"
#include "symbolTable.h"

/*
 * This func add new command to the map.
 */
void symbolTable::addVar(string symbol,Var* value){
    symbolMap[symbol] = value;
}


/*
 * This func return the command if exist
 */
Var* symbolTable::getVarValue(string symbol){
    map<string,Var>:: iterator it;
    if(symbolMap.find(symbol) != symbolMap.end()){
        return symbolMap[symbol];
    }
    return nullptr;

}
/*
 * This func returns the all map.
 */
map<string, Var*>& symbolTable::getSymbolMap() {
    return symbolMap;
}