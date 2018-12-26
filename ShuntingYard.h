#ifndef FLIGHT_SIMULATOR_SHUNTINGYARD_H
#define FLIGHT_SIMULATOR_SHUNTINGYARD_H

#include "Commands.h"
#include "commandExpression.h"
#include "symbolTable.h"
#include <string>
#include <map>

using namespace std;
#define MULT_OR_DIV 3
#define OPERATOR1 1
#define OPERATOR2 2
#define NOT_OPERATOR 0

class ShuntingYard {
    symbolTable* varMap;
public:
    ShuntingYard(symbolTable *varMap){
        ShuntingYard::varMap = varMap;
    }
     bool checkForValidation(string);
     Expression* shuntingYard(string);
     queue<string> putInQueue(string&);
     Expression* fromStringToExpresion(string,stack<Expression*>&);
     bool isdigit(char);
     bool isCharacter(char);
     string fromVectorToString(vector<string> &result, int i, int k);

     ~ShuntingYard(){};
};


#endif //FLIGHT_SIMULATOR_SHUNTINGYARD_H
