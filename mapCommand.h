#ifndef FLIGHT_SIMULATOR_MAPCOMMAND_H
#define FLIGHT_SIMULATOR_MAPCOMMAND_H

#include <string>
#include <map>
#include "commandExpression.h"

class Commands;
using namespace std;

class mapCommand {
    map<string,commandExpression*> commandMap;


public:
    mapCommand()= default;
    map<string, commandExpression*> &getCommandMap() ;

    void addCommand(string symbol,commandExpression* commands);
    commandExpression* getCommandExpression(string symbol);
};


#endif //FLIGHT_SIMULATOR_MAPCOMMAND_H
