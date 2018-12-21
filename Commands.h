#ifndef FLIGHT_SIMULATOR_COMMANDS_H
#define FLIGHT_SIMULATOR_COMMANDS_H
#include <stack>
#include <string>
#include <queue>
#include "Expression.h"

using namespace std;

class mapCommand;
class symbolTable;


class Commands {
protected:
    mapCommand* commandTable;
    symbolTable* varTable;

public:
    Commands(mapCommand* commandTable, symbolTable* varTable){};
    vector<string>cleanSpace(string);
    bool checkForValidation(string);
    virtual int execute(string str){};
    void cleanWhiteSpaces(string &sentence);
    Expression* shuntingYard(string);
    queue<string> putInQueue(string&);
    Expression* fromStringToExpresion(string,stack<Expression*>&);
    bool isdigit(char);
    bool isCharacter(char);
    vector<string> getParameters(string&);



};


#endif //FLIGHT_SIMULATOR_COMMANDS_H