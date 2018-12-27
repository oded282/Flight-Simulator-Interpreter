
#ifndef FLIGHT_SIMULATOR_DATAREADERSERVER_H
#define FLIGHT_SIMULATOR_DATAREADERSERVER_H


#include <unistd.h>
#include "../data/symbolTable.h"

struct MyParams {
    int newsockfd;
    int i;
    double pace;
    symbolTable *symbolMap;
    vector<string> pathsVector;

};


class dataReaderServer {

    int port;
    int newsockfd;
    double pace;
    struct MyParams *params;
    symbolTable* symbolMap;
    vector<string> pathsVector;


public:
    dataReaderServer(int port, double pace , symbolTable* symbolMap);
    void openServer();
    ~dataReaderServer(){
        close(newsockfd);
        delete params;
    }

    //static void *helpFunc(void *dataReader, int newsockfd);
};


#endif //FLIGHT_SIMULATOR_DATAREADERSERVER_H
