#ifndef FLIGHT_SIMULATOR_COMMANDS_H
#define FLIGHT_SIMULATOR_COMMANDS_H
#include <stack>
#include <string>
#include <map>
#include "Expression.h"

using namespace std;

class mapCommand;
class symbolMap;


class Commands {

    mapCommand* commandMap;
    symbolMap* symbolTable;

public:
    Commands(){};

//string charToString(char c);
    bool checkForValidation(string);
    virtual int execute(){};
    void cleanWhiteSpaces(string &sentence);
    Expression* shuntingYard(string);
    bool isdigit(char);
    bool isCharacter(char);
//    int isOperator(char c);



};


#endif //FLIGHT_SIMULATOR_COMMANDS_H
