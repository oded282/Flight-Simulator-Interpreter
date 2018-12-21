#ifndef FLIGHT_SIMULATOR_OPENCLIENT_H
#define FLIGHT_SIMULATOR_OPENCLIENT_H


class openClient {

    int port;
    char* ip;

public:
    openClient(char* , int);
    void openSocketClient();



};


#endif //FLIGHT_SIMULATOR_OPENCLIENT_H
