
#ifndef FLIGHT_SIMULATOR_DATAREADERSERVER_H
#define FLIGHT_SIMULATOR_DATAREADERSERVER_H


#include <unistd.h>
#include <vector>
#include "../data/symbolTable.h"
using namespace std;

struct MyParams {
    int newsockfd;
    int i;
    double pace;
    symbolTable *symbolMap;
    vector<string> pathsVector;
    vector <Expression*>* collector;
};


class dataReaderServer {

    int port;
    int newsockfd;
    double pace;
    struct MyParams *params;
    symbolTable* symbolMap;
    vector<string> pathsVector;
    vector<Expression*>* collector;

public:
    dataReaderServer(int port, double pace , symbolTable* symbolMap);
    void openServer();
    ~dataReaderServer(){
        for (Expression* it :(*collector) ){
            delete it;
        }
        close(newsockfd);
        delete params;
        delete collector;
    }
};


#endif //FLIGHT_SIMULATOR_DATAREADERSERVER_H
