#ifndef FLIGHT_SIMULATOR_CONNECT_H
#define FLIGHT_SIMULATOR_CONNECT_H

#include <string>
#include "Commands.h"

using namespace std;

class connectCommand : public Commands {

    int port;
    char* ip;

public:
    connectCommand(mapCommand* commandMap , symbolTable* varTable) : Commands(commandMap,varTable) {}
    connectCommand(int , char*);
    virtual int execute(string);

};

#endif //FLIGHT_SIMULATOR_CONNECT_H
