

#include "Connect.h"
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string>
#include <strings.h>
#include <cstring>

#define EXIT_FAILURE 1

using namespace std;

Connect::Connect(int port, char* ip) {
    Connect::port = port;
    Connect::ip = ip;
}

int Connect::execute() {


        int sockfd, portno, n;
        struct sockaddr_in serv_addr;
        struct hostent *server;

        char buffer[256];

        portno = port;

        /* Create a socket point */
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0) {
            perror("ERROR opening socket");
            exit(EXIT_FAILURE);
        }

        server = gethostbyname(ip);

        if (server == NULL) {
            fprintf(stderr, "ERROR, no such host\n");
            exit(EXIT_FAILURE);
        }

        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
        serv_addr.sin_port = htons(portno);

        /* Now connect to the server */
        if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            perror("ERROR connecting");
            exit(EXIT_FAILURE);
        }

        /* Now ask for a message from the user, this message
           * will be read by server
        */

        bzero(buffer, 256);
        fgets(buffer, 255, stdin);

        /* Send message to the server */
        n = write(sockfd, buffer, strlen(buffer));

        if (n < 0) {
            perror("ERROR writing to socket");
            exit(EXIT_FAILURE);
        }

        /* Now read server response */
        bzero(buffer, 256);
        n = read(sockfd, buffer, 255);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(EXIT_FAILURE);
        }

    }
