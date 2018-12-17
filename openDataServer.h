#ifndef FLIGHT_SIMULATOR_OPENDATASERVER_H
#define FLIGHT_SIMULATOR_OPENDATASERVER_H


#include "Expression.h"
#include "Commands.h"

class openDataServer : public Commands {


public:
    openDataServer();
    virtual int execute();

};


#endif //FLIGHT_SIMULATOR_OPENDATASERVER_H
