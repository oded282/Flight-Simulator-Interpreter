#ifndef FLIGHT_SIMULATOR_DATAREADERSERVER_H
#define FLIGHT_SIMULATOR_DATAREADERSERVER_H


#include <unistd.h>
#include <vector>
#include "../data/symbolTable.h"
using namespace std;

//struct for the thread.
struct MyParams {
    vector <Expression*>* collector;
    int newsockfd;
    int i;
    symbolTable *symbolMap;
    double pace;
    vector<string> pathsVector;
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
    //constructor.
    dataReaderServer(int port, double pace , symbolTable* symbolMap);
    //open server.
    void openServer();
    //destructor.
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
