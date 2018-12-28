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
#define IP 1

using namespace std;
// get the socket client.
openClient* connectCommand::getClient(){
    return client;
}

// set the command.
void connectCommand::setCommand(string& str) {
    // get the string of the cod and return the parameters.
    vector<string> result = getParameters(str);
    string ip = result[IP];
    string expression = shuntingYard->fromVectorToString(result , 1 , (unsigned)result.size());
    int port = (int)shuntingYard->shuntingYard(expression)->calculate();
    this->client = new openClient(ip, port);
}
//open client
int connectCommand::execute() {
    client->openSocketClient();
    return 1;
}
