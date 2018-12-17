#ifndef FLIGHT_SIMULATOR_CONNECT_H
#define FLIGHT_SIMULATOR_CONNECT_H

#include <string>
#include "Commands.h"

using namespace std;

class Connect : public Commands {

    int port;
    char* ip;

public:
    Connect(int , char*);


    virtual int execute();

};

#endif //FLIGHT_SIMULATOR_CONNECT_H
