#ifndef FLIGHT_SIMULATOR_OPENDATASERVER_H
#define FLIGHT_SIMULATOR_OPENDATASERVER_H


#include <string>
#include "Expression.h"
#include "Commands.h"

class openServerCommand : public Commands {

public:
    openServerCommand(){};
    bool checkLegality(string);
    int execute(string){
        return 1;
    };


};


#endif //FLIGHT_SIMULATOR_OPENDATASERVER_H
