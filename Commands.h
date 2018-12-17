#ifndef FLIGHT_SIMULATOR_COMMANDS_H
#define FLIGHT_SIMULATOR_COMMANDS_H
#include <string>
#include "Expression.h"

using namespace std;
class Commands
{
public:
    virtual int execute() = 0;
    void cleanWhiteSpaces(string& sentence);
    Expression shuntingYard(string);
    bool isNumber(char);



};


#endif //FLIGHT_SIMULATOR_COMMANDS_H
