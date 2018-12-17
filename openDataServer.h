#ifndef FLIGHT_SIMULATOR_OPENDATASERVER_H
#define FLIGHT_SIMULATOR_OPENDATASERVER_H


#include <string>
#include "Expression.h"
#include "Commands.h"

class openDataServer : public Commands {

public:
    openDataServer(){};
    bool checkLegality(string);
    int execute(string){
        return 1;
    };


};


#endif //FLIGHT_SIMULATOR_OPENDATASERVER_H
