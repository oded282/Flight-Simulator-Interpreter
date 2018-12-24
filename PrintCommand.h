#ifndef FLIGHT_SIMULATOR_PRINTCOMMAND_H
#define FLIGHT_SIMULATOR_PRINTCOMMAND_H


#include "Commands.h"

class PrintCommand : public Commands {

    string str;

public:
    int execute();
    void setCommand(string&);


};


#endif //FLIGHT_SIMULATOR_PRINTCOMMAND_H
