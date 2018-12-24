#ifndef FLIGHT_SIMULATOR_SYMBOLTABLE_H
#define FLIGHT_SIMULATOR_SYMBOLTABLE_H

#include <map>
#include "Var.h"

class symbolTable {
    map<string,Var*> symbolMap;

public:
    map<string, Var*> &getSymbolMap();
    void addVar(string symbol, Var* value);
    Var* getVar(string symbol);
    Expression* getVarValue(string symbol);
    string getVarPath(string symbol);
    Var* getVarByPath(string);
};


#endif //FLIGHT_SIMULATOR_SYMBOLTABLE_H