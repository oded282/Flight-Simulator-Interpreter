#ifndef FLIGHT_SIMULATOR_COMMANDS_H
#define FLIGHT_SIMULATOR_COMMANDS_H
#include <stack>
#include <string>
#include <queue>
#include "Expression.h"

using namespace std;

class mapCommand;
class symbolTable;
class ShuntingYard;


class Commands {
protected:
    mapCommand* commandTable;
    symbolTable* varTable;
    ShuntingYard* shuntingYard;

public:
    Commands(mapCommand* commandTable, symbolTable* varTable , ShuntingYard* shuntingYard);
    vector<string>cleanSpace(string);
    virtual int execute() = 0;
    virtual void setCommand(string& str) = 0;
    void cleanWhiteSpaces(string &sentence);
    vector<string> getParameters(string&);
    vector<string> getAssinParam(string);

};


#endif //FLIGHT_SIMULATOR_COMMANDS_H