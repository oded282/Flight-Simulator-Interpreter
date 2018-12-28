#ifndef FLIGHT_SIMULATOR_CONNECT_H
#define FLIGHT_SIMULATOR_CONNECT_H

#include <string>
#include "Commands.h"
#include "../connection/openClient.h"

using namespace std;

class connectCommand : public Commands {

    openClient *client;

public:
    //constructor.
    connectCommand(mapCommand *commandMap, symbolTable *varTable, ShuntingYard* shuntingYard) :
            Commands(commandMap, varTable, shuntingYard) {
        connectCommand::client = nullptr;
    }

    // open the client
    virtual int execute();
    // get the client
    openClient* getClient();
    //destructor.
    virtual void setCommand(string &);
    ~connectCommand(){
        delete client;
    }
};

#endif //FLIGHT_SIMULATOR_CONNECT_H
