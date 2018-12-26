#include "openClient.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string>
#include <cstring>
#include <iostream>

extern bool isStop;
extern pthread_mutex_t mutex;

/*
struct MyParams {
    int sockfd;
    string &command;
    bool isSendCommand;
    MyParams();
};
*/
void openClient::communicationClient(string command) {

    //struct MyParams *params = (MyParams *) ;


        // lock thread.
        pthread_mutex_lock(&mutex);
        cout << "lock open client======================"<<endl;
        //if (params->isSendCommand) {
            /* Send message to the server */
            ssize_t n = write(sockfd, command.c_str(), strlen(command.c_str()));
            cout << "client data!!!!!!!!!!!!!!!!!!!!"<< endl;
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(EXIT_FAILURE);
            }
            //params->isSendCommand = false;
       // }
    cout << "unlock open client===================="<<endl;
    // unlock thread.
        pthread_mutex_unlock(&mutex);
   // return nullptr;
}

openClient::openClient(string ip, int port) {
    openClient::port = port;
    openClient::ip = ip;

}

void openClient::openSocketClient() {
    int portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    portno = this->port;
    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        throw ("ERROR opening socket");
    }

    server = gethostbyname(ip.data());

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons((uint16_t) portno);

    /* Now connect to the server */
    if (connect(this->sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        throw "ERROR connecting";
    }

   //struct MyParams *params = new MyParams();
   //params->sockfd = sockfd;
   //params->isSendCommand = this->isSendCommand;
    //params->command = command;


    //pthread_t clientThread;
    //pthread_create(&clientThread, nullptr, communicationClient, (void *) params);
  // communicationClient(sockfd);

}

//id openClient::setCommand(const string &command) {
//  openClient::command = command;
//  openClient::isSendCommand = true;
//
