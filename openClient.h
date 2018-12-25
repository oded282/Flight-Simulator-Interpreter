#ifndef FLIGHT_SIMULATOR_OPENCLIENT_H
#define FLIGHT_SIMULATOR_OPENCLIENT_H

#include <string>

using namespace std;


class openClient {

    int port;
    int sockfd;
    string ip;
    string command;
    bool isSendCommand;

public:
    openClient(string , int);
    void openSocketClient();
    void sendCommand(char *);

    void setCommand(const string &command);


};


#endif //FLIGHT_SIMULATOR_OPENCLIENT_H
