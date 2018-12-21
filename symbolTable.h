#ifndef FLIGHT_SIMULATOR_SYMBOLTABLE_H
#define FLIGHT_SIMULATOR_SYMBOLTABLE_H

#include <map>
#include "Var.h"

class symbolTable {
    map<string,double> symbolMap;

public:
    map<string, double> &getSymbolMap();
    void addVar(string symbol,double value);
    double getVarValue(string symbol);
};


#endif //FLIGHT_SIMULATOR_SYMBOLTABLE_H