#include "openClient.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string>
#include <cstring>


openClient::openClient(string ip,int port) {
    openClient::port = port;
    openClient::ip = ip;
}

void openClient::openSocketClient() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    portno = this->port;
    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        throw("ERROR opening socket");
    }

    server = gethostbyname(ip.data());

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons((uint16_t)portno);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        throw "ERROR connecting";
    }
    //string ip_adress = ip ;
    //int sockfd, portno;
    //struct sockaddr_in serv_addr;
    //struct hostent *server;
    //portno = this->port;
    ///* Create a socket point */
    //sockfd = socket(AF_INET, SOCK_STREAM, 0);
    //if (sockfd < 0) {
    //    throw("ERROR opening socket");
    //}
    //server = gethostbyname(ip_adress.c_str());
//
    //if (server == NULL) {
    //    fprintf(stderr,"ERROR, no such host\n");
    //    exit(0);
    //}
    //bzero((char *) &serv_addr, sizeof(serv_addr));
    //serv_addr.sin_family = AF_INET;
    //bcopy(server->h_addr, (char *)&serv_addr.sin_addr.s_addr, (size_t)server->h_length);
    //serv_addr.sin_port = htons((uint16_t)portno);
//
    ///* Now connect to the server */
    //if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    //    throw "ERROR connecting";
    //}
}

void openClient::sendCommand(char * command){
    // char buffer[256];
    /* Now ask for a message from the user, this message
          * will be read by server
    */
    //bzero(buffer, 1025);
    //fgets(buffer, 255, stdin);


    /* Send message to the server */
    ssize_t n = write(sockfd, command, strlen(command));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }

}
