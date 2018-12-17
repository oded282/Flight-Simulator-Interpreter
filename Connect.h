#ifndef FLIGHT_SIMULATOR_CONNECT_H
#define FLIGHT_SIMULATOR_CONNECT_H

#include <string>
#include "Commands.h"

using namespace std;

class Connect : public Commands {

    int port;
    string ip;

public:
    Connect(int , string);

    virtual int execute();

};

#endif //FLIGHT_SIMULATOR_CONNECT_H
