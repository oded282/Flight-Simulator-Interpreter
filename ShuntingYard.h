#ifndef FLIGHT_SIMULATOR_SHUNTINGYARD_H
#define FLIGHT_SIMULATOR_SHUNTINGYARD_H

#include "Commands.h"
#include "commandExpression.h"
#include <string>
#include <map>

using namespace std;
#define MULT_OR_DIV 3
#define OPERATOR 1
#define NOT_OPERATOR 0

class ShuntingYard {
    map<string , commandExpression*>* varMap;
public:
    ShuntingYard(map <string , commandExpression*> *varMap){
        ShuntingYard::varMap = varMap;
    }
     bool checkForValidation(string);
     Expression* shuntingYard(string);
     queue<string> putInQueue(string&);
     Expression* fromStringToExpresion(string,stack<Expression*>&);
     bool isdigit(char);
     bool isCharacter(char);
     string fromVectorToString(vector<string> &result, int i, int k);

};


#endif //FLIGHT_SIMULATOR_SHUNTINGYARD_H
