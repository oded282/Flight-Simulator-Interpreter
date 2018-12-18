#ifndef FLIGHT_SIMULATOR_COMMANDS_H
#define FLIGHT_SIMULATOR_COMMANDS_H
#include <stack>
#include <string>
#include <map>
#include "Expression.h"
#include "mapCommand.h"

using namespace std;


class Commands {

    mapCommand commandMap;
    symbolMap symbolTable;

public:
    string charToString(char c);
    bool checkForValidation(string);
    virtual int execute() = 0;
    void cleanWhiteSpaces(string &sentence);
    Expression* shuntingYard(string);
    bool isdigit(char);
    bool isCharacter(char);
    int isOperator(char c);



};


#endif //FLIGHT_SIMULATOR_COMMANDS_H
