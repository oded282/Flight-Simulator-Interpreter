#ifndef FLIGHT_SIMULATOR_COMMANDS_H
#define FLIGHT_SIMULATOR_COMMANDS_H
#include <stack>
#include <string>
#include <map>
#include "Expression.h"

using namespace std;


class Commands {

    //map<string, Commands> commandMap;
    //map<string, Var> symbolTable;
public:
    virtual int execute() = 0;
    void cleanWhiteSpaces(string &sentence);
    Expression* shuntingYard(string);
    bool isNumber(char);
    int isOperator(char c);



};


#endif //FLIGHT_SIMULATOR_COMMANDS_H
