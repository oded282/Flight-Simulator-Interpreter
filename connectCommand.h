#ifndef FLIGHT_SIMULATOR_CONNECT_H
#define FLIGHT_SIMULATOR_CONNECT_H

#include <string>
#include "Commands.h"
#include "openClient.h"

using namespace std;

class connectCommand : public Commands {

    openClient *client;

public:
    connectCommand(mapCommand *commandMap, symbolTable *varTable, ShuntingYard* shuntingYard) :
            Commands(commandMap, varTable, shuntingYard) {
        connectCommand::client = nullptr;
    }

    virtual int execute();

    virtual void setCommand(string &);

};

#endif //FLIGHT_SIMULATOR_CONNECT_H
