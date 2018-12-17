#ifndef FLIGHT_SIMULATOR_COMMANDS_H
#define FLIGHT_SIMULATOR_COMMANDS_H

#include <string>
#include <map>

using namespace std;


class Commands {

    map<string, Commands> commandMap;
    map<string, Var> symbolTable;

    bool isVarExist(string expression){
        return symbolTable.find(expression) != symbolTable.end();

    }

    virtual int execute() = 0;

    void cleanWhiteSpaces(string &sentence);



};


#endif //FLIGHT_SIMULATOR_COMMANDS_H
