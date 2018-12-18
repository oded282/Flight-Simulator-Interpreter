
#include "Commands.h"
#include "symbolTable.h"

/*
 * This func add new command to the map.
 */
void symbolTable::addSymbol(string symbol,Var var){
    symbolMap[symbol] = var;
}


/*
 * This func return the command if exist
 */
Var* symbolTable::getSymbol(string symbol){
    map<string,Var>:: iterator it;
    if(symbolMap.find(symbol) != symbolMap.end()){
        return &symbolMap[symbol];
    }
    return nullptr;

}
/*
 * This func returns the all map.
 */
const map<string, Var> &symbolTable::getSymbolMap() const {
    return symbolMap;
}