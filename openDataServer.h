#ifndef FLIGHT_SIMULATOR_OPENDATASERVER_H
#define FLIGHT_SIMULATOR_OPENDATASERVER_H


#include "Expression.h"
#include "Commands.h"

class openDataServer : public Commands {

    double port;
    double pace;

public:
    virtual int execute();
    void openServer();

};


#endif //FLIGHT_SIMULATOR_OPENDATASERVER_H
