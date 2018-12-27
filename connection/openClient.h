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
    void communicationClient(string );
    ~openClient(){
        close(sockfd);
    }
};


#endif //FLIGHT_SIMULATOR_OPENCLIENT_H
