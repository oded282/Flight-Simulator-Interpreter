#ifndef FLIGHT_SIMULATOR_COMMANDS_H
#define FLIGHT_SIMULATOR_COMMANDS_H
#include <string>
using namespace std;
class Commands
{

    virtual int execute() = 0;
    void cleanWhiteSpaces(string& sentence);

};


#endif //FLIGHT_SIMULATOR_COMMANDS_H
