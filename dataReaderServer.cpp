
#include "openServerCommand.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>
#include <iostream>
#include <sstream>
#include <thread>
#include "dataReaderServer.h"
#include "Number.h"

vector<string> splitByComma(string str){
    vector <string> result;
    string val;
    for (char itr : str){
        if (itr != ',' && itr != '\n'){
            val += itr;
        } else{
            result.push_back(val);
            val.clear();
        }
    }
    return result;
}

void dataReaderServer::setDataFlight(char* str){

    vector<string> values = splitByComma(str);

    int i = 0;
    while (i < values.size()){
        if (symbolMap->getVarByPath(pathsVector[i]) != nullptr){
            //set the value of var.
            symbolMap->getVarByPath(pathsVector[i])->setValue(
                    new Number(strtof((values[i]).c_str(), nullptr)));
        }
        i++;
    }
}

void* dataReaderServer::communication (int newsockfd){
    char buffer[256];
    ssize_t n;
    /* If connection is established then start communicating */
    while (true) {
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);

        if (n < 0) {
            perror("ERROR reading from socket");
            break;
        }

        setDataFlight(buffer);

        sleep((unsigned)this->pace/1000);

    }
    return nullptr;
}






dataReaderServer::dataReaderServer(int port, double pace , symbolTable* symbolMap) {
    dataReaderServer::port = port;
    dataReaderServer::pace = pace;
    dataReaderServer::symbolMap = symbolMap;
    dataReaderServer::pathsVector = {"/instrumentation/airspeed-indicator/indicated-speed-kt",
                                     "/instrumentation/altimeter/indicated-altitude-ft",
                                     "/instrumentation/altimeter/pressure-alt-ft",
                                     "/instrumentation/attitude-indicator/indicated-pitch-deg",
                                     "/instrumentation/attitude-indicator/indicated-roll-deg",
                                     "/instrumentation/attitude-indicator/internal-pitch-deg",
                                     "/instrumentation/attitude-indicator/internal-roll-deg",
                                     "/instrumentation/encoder/indicated-altitude-ft",
                                     "/instrumentation/encoder/pressure-alt-ft",
                                     "/instrumentation/gps/indicated-altitude-ft",
                                     "/instrumentation/gps/indicated-ground-speed-kt",
                                     "/instrumentation/gps/indicated-vertical-speed",
                                     "/instrumentation/heading-indicator/indicated-heading-deg",
                                     "/instrumentation/magnetic-compass/indicated-heading-deg",
                                     "/instrumentation/slip-skid-ball/indicated-slip-skid",
                                     "/instrumentation/turn-indicator/indicated-turn-rate",
                                     "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
                                     "/controls/flight/aileron","/controls/flight/elevator","/controls/flight/rudder",
                                     "/controls/flight/flaps","/controls/engines/engine/throttle",
                                     "/engines/engine/rpm"};
}


void dataReaderServer:: openServer(){


    int sockfd, newsockfd, clilen;

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
    serv_addr.sin_port = htons((uint16_t)port);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd,1);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    //thread t1(communication(newsockfd));
    communication(newsockfd);
}


