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

//constructor.
openClient::openClient(string ip, int port) {
    openClient::port = port;
    openClient::ip = ip;
}

// get string command and send her to the simulator.
void openClient::communicationClient(string command) {
            /* Send message to the server */
            ssize_t n = write(sockfd, command.c_str(), strlen(command.c_str()));
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(EXIT_FAILURE);
            }
}

//open client for connect to the server.
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
        close(sockfd);
        fprintf(stderr, "ERROR, no such host\n");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, (char *) &serv_addr.sin_addr.s_addr, (size_t)server->h_length);
    serv_addr.sin_port = htons((uint16_t) portno);

    /* Now connect to the server */
    if (connect(this->sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        cout << "ERROR CONNECTING"<< endl;
        close(sockfd);
        throw "ERROR connecting";
    }
}
