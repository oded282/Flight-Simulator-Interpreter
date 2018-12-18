//
// Created by oded on 12/18/18.
//

#ifndef FLIGHT_SIMULATOR_MAPCOMMAND_H
#define FLIGHT_SIMULATOR_MAPCOMMAND_H

#include "Commands.h"

class mapCommand {
    map<string,Commands> commandMap;


public:

    const map<string, Commands> &getCommandMap() const;

    void addCommand(string symbol,Commands commands);
    Commands* getCommand(string symbol);
};


#endif //FLIGHT_SIMULATOR_MAPCOMMAND_H
