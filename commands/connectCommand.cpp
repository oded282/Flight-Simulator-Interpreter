#include "connectCommand.h"
#include "../connection/openClient.h"
#include "../utils/ShuntingYard.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string>
#include <cstring>

#define EXIT_FAILURE 1

using namespace std;

openClient* connectCommand::getClient(){
    return client;
}


void connectCommand::setCommand(string& str) {

    vector<string> result = getParameters(str);

    string ip = result[0];
    string expression = shuntingYard->fromVectorToString(result , 1 , (unsigned)result.size());
    int port = (int)shuntingYard->shuntingYard(expression)->calculate();

    this->client = new openClient(ip, port);

}

int connectCommand::execute() {
    client->openSocketClient();
    return 1;
}
