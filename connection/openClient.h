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
    //constructor.
    openClient(string , int);
    // open client.
    void openSocketClient();
    // send commands to the simulator.
    void communicationClient(string );
    //destructor.
    ~openClient(){
        close(sockfd);
    }
};

#endif //FLIGHT_SIMULATOR_OPENCLIENT_H
