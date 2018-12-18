#ifndef FLIGHT_SIMULATOR_COMMANDS_H
#define FLIGHT_SIMULATOR_COMMANDS_H
#include <stack>
#include <string>
#include <map>
#include "Expression.h"

using namespace std;

class mapCommand;
class symbolTable;


class Commands {
protected:
    mapCommand* commandMap;
    symbolTable* symbolTable;

public:
    Commands(){};

//string charToString(char c);
    bool checkForValidation(string);
    virtual int execute(){};
    void cleanWhiteSpaces(string &sentence);
    Expression* shuntingYard(string);
    queue<string> putInQueue(string&);
    Expression* fromStringToExpresion(string);
    bool isdigit(char);
    bool isCharacter(char);
//    int isOperator(char c);



};


#endif //FLIGHT_SIMULATOR_COMMANDS_H
