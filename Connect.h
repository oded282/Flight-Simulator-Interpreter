#ifndef FLIGHT_SIMULATOR_CONNECT_H
#define FLIGHT_SIMULATOR_CONNECT_H

#include <cstring>
#include "Commands.h"


class Connect : public Commands {

    int port;
    string ip;

public:
    Connect(int , string);
    virtual int execute();
    void openServer();

};

#endif //FLIGHT_SIMULATOR_CONNECT_H
