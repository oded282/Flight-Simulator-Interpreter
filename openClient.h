#ifndef FLIGHT_SIMULATOR_OPENCLIENT_H
#define FLIGHT_SIMULATOR_OPENCLIENT_H

#include <string>

using namespace std;


class openClient {

    int port;
    string ip;
    int sockfd;

public:
    openClient(string , int);
    void openSocketClient();
    void sendCommand(char *);


};


#endif //FLIGHT_SIMULATOR_OPENCLIENT_H
