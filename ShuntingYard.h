//
// Created by oded on 12/21/18.
//

#ifndef FLIGHT_SIMULATOR_SHUNTINGYARD_H
#define FLIGHT_SIMULATOR_SHUNTINGYARD_H

#include "Commands.h"
#include <string>
using namespace std;
#define MULT_OR_DIV 3
#define OPERATOR 1
#define NOT_OPERATOR 0

class ShuntingYard {

public:
    static bool checkForValidation(string);
    static Expression* shuntingYard(string);
    static queue<string> putInQueue(string&);
    static Expression* fromStringToExpresion(string,stack<Expression*>&);
    static bool isdigit(char);
    static bool isCharacter(char);
    static string fromVectorToString(vector<string> &result, int i, int k);

};


#endif //FLIGHT_SIMULATOR_SHUNTINGYARD_H
