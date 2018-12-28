#ifndef FLIGHT_SIMULATOR_SYMBOLTABLE_H
#define FLIGHT_SIMULATOR_SYMBOLTABLE_H

#include <map>
#include "../commands/VarCommand.h"

/*
 *This class holds a map of all vars.
 */
class symbolTable {
    map<string,VarCommand*> symbolMap;

public:
    map<string, VarCommand*> &getSymbolMap();
    void addVar(VarCommand* value);
    VarCommand* getVar(string symbol);
    Expression* getVarValue(string symbol);
    string getVarPath(string symbol);
    VarCommand* getVarByPath(string);
};


#endif //FLIGHT_SIMULATOR_SYMBOLTABLE_H