
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <iostream>
#include <sstream>
#include <pthread.h>
#include <thread>
#include "../commands/openServerCommand.h"
#include "dataReaderServer.h"
#include "../expressions/Number.h"
#include "../commands/VarCommand.h"

extern bool isStop;
extern pthread_mutex_t mutex;


vector<string> splitByComma(string str) {
    vector<string> result;
    string val;
    for (char itr : str) {
        if (itr != ',' && itr != '\n') {
            val += itr;
        } else {
            result.push_back(val);
            val.clear();
        }
    }
    return result;
}


dataReaderServer::dataReaderServer(int port, double pace, symbolTable *symbolMap) {
    dataReaderServer::port = port;
    dataReaderServer::pace = pace;
    dataReaderServer::symbolMap = symbolMap;
    dataReaderServer::pathsVector = {"instrumentation/airspeed-indicator/indicated-speed-kt",
                                     "instrumentation/altimeter/indicated-altitude-ft",
                                     "instrumentation/altimeter/pressure-alt-ft",
                                     "instrumentation/attitude-indicator/indicated-pitch-deg",
                                     "instrumentation/attitude-indicator/indicated-roll-deg",
                                     "instrumentation/attitude-indicator/internal-pitch-deg",
                                     "instrumentation/attitude-indicator/internal-roll-deg",
                                     "instrumentation/encoder/indicated-altitude-ft",
                                     "instrumentation/encoder/pressure-alt-ft",
                                     "instrumentation/gps/indicated-altitude-ft",
                                     "instrumentation/gps/indicated-ground-speed-kt",
                                     "instrumentation/gps/indicated-vertical-speed",
                                     "instrumentation/heading-indicator/indicated-heading-deg",
                                     "instrumentation/magnetic-compass/indicated-heading-deg",
                                     "instrumentation/slip-skid-ball/indicated-slip-skid",
                                     "instrumentation/turn-indicator/indicated-turn-rate",
                                     "instrumentation/vertical-speed-indicator/indicated-speed-fpm",
                                     "controls/flight/aileron", "controls/flight/elevator", "/controls/flight/rudder",
                                     "controls/flight/flaps", "engines/controls/current-engine/throttle",
                                     "engines/engine/rpm"};
}

int setTheReceivedData(char buffer[1024], symbolTable *symbolMap,
        vector<string> pathsVector ,int i , int pace)  {
    vector<string> values = splitByComma(buffer);
    while (i < (values.size()-1) && isStop) {
        if (i == pathsVector.size()){
            i = 0;
            sleep((unsigned) pace / 1000);
        }

        if (symbolMap->getVarByPath(pathsVector[i]) != nullptr) {
            //set the value of var.
            Expression* e = new Number(strtof((values[i]).data(), nullptr));
            VarCommand *v = symbolMap->getVarByPath(pathsVector[i]);
            //Expression* eOld = v->getValue();
            //delete eOld;
            v->setValue(e);
        }
        i++;
    }
    return i;
}


void *communicationServer(void *args) {
    struct MyParams* params = (MyParams *) args;
    char buffer[1024];
    ssize_t n;
    cout <<"check 4 communicationServer"<<endl;

    while (isStop) {
        cout << "check 5 communicationServer 1" << endl;
        bzero(buffer, 1024);


        n = read(params->newsockfd, buffer, 1024);

        if (n < 0) {
            perror("ERROR reading from socket");
            break;
        }

        params->i = setTheReceivedData(buffer, params->symbolMap, params->pathsVector,
                                       params->i, (int) params->pace);
    }

    return nullptr;
}


void dataReaderServer::openServer() {


    int sockfd, clilen;

    struct sockaddr_in serv_addr, cli_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons((uint16_t) port);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */
    cout <<"check 1"<<endl;
    listen(sockfd, 1);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    char buffer[1024] = {};
    /* If connection is established then start communicating */
    //bzero(buffer, 1024);
    cout <<"check 2"<<endl;

    while (strlen(buffer) == 0) {
        read(newsockfd, buffer, 1024);
    }
    pthread_t pthreadS;
    setTheReceivedData(buffer , symbolMap , pathsVector , 0 ,(int)pace);
    params = new MyParams();
    params->newsockfd = newsockfd;
    params->pace = pace;
    params->pathsVector = pathsVector;
    params->symbolMap = symbolMap;
    params->i = 0;

    cout <<"check 3"<<endl;
    pthread_create(&pthreadS, nullptr, communicationServer, (void *) params);
    //communicationServer(params);
}


