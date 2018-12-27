#ifndef FLIGHT_SIMULATOR_OPENCLIENT_H
#define FLIGHT_SIMULATOR_OPENCLIENT_H

#include <string>
#include <unistd.h>

using namespace std;


class openClient {

    int port;
    int sockfd;
    string ip;

public:
    openClient(string , int);
    void openSocketClient();
    void sendCommand(char *);
    void communicationClient(string );
    void setCommand(const string &command);
    ~openClient(){
        close(sockfd);
    }
};


#endif //FLIGHT_SIMULATOR_OPENCLIENT_H
