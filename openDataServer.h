#ifndef FLIGHT_SIMULATOR_OPENDATASERVER_H
#define FLIGHT_SIMULATOR_OPENDATASERVER_H


#include "Expression.h"
#include "Commands.h"

class openDataServer : public Commands {

    int port;
    double pace;

public:
    openDataServer(int port, double pace);
    virtual int execute();
    void openServer();

};


#endif //FLIGHT_SIMULATOR_OPENDATASERVER_H
