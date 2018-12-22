#ifndef FLIGHT_SIMULATOR_OPENCLIENT_H
#define FLIGHT_SIMULATOR_OPENCLIENT_H

#include <string>

using namespace std;


class openClient {

    int port;
    char* ip;
    int sockfd;

public:
    openClient(char* , int);
    void openSocketClient();
    void sendCommand(char *);


};


#endif //FLIGHT_SIMULATOR_OPENCLIENT_H
