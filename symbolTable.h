#ifndef FLIGHT_SIMULATOR_SYMBOLTABLE_H
#define FLIGHT_SIMULATOR_SYMBOLTABLE_H

#include "Var.h"

class symbolTable {
    map<string,Var> symbolMap;

public:

    const map<string, Var> &getSymbolMap() const;

    void addSymbol(string symbol,Var var);
    Var* getSymbol(string symbol);
};


#endif //FLIGHT_SIMULATOR_SYMBOLTABLE_H