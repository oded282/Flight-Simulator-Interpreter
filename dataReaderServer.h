
#ifndef FLIGHT_SIMULATOR_DATAREADERSERVER_H
#define FLIGHT_SIMULATOR_DATAREADERSERVER_H


#include "symbolTable.h"

class dataReaderServer {

    int port;
    double pace;
    symbolTable* symbolMap;
    vector<string> pathsVector;
    /*privet method*/


public:
    void setDataFlight(char*);
    void communication (int);
    dataReaderServer(int port, double pace , symbolTable* symbolMap);
    void openServer();

    static void *helpFunc(void *dataReader, int newsockfd);
};


#endif //FLIGHT_SIMULATOR_DATAREADERSERVER_H
