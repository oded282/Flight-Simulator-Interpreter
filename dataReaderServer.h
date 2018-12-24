
#ifndef FLIGHT_SIMULATOR_DATAREADERSERVER_H
#define FLIGHT_SIMULATOR_DATAREADERSERVER_H


#include "symbolTable.h"

class dataReaderServer {

    int port;
    double pace;
    symbolTable* symbolMap;
    vector<string> pathsVector;
    /*privet method*/
    void setDataFlight(char*);
    void* communication (int);

public:
    dataReaderServer(int port, double pace , symbolTable* symbolMap);
    void openServer();

};


#endif //FLIGHT_SIMULATOR_DATAREADERSERVER_H
