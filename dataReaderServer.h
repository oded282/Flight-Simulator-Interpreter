//
// Created by oded on 12/17/18.
//

#ifndef FLIGHT_SIMULATOR_DATAREADERSERVER_H
#define FLIGHT_SIMULATOR_DATAREADERSERVER_H


class dataReaderServer {

    int port;
    double pace;

public:
    dataReaderServer(int port, double pace);
    void openServer();
};


#endif //FLIGHT_SIMULATOR_DATAREADERSERVER_H
