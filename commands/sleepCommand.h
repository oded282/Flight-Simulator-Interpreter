#ifndef FLIGHT_SIMULATOR_SLEEPCOMMAND_H
#define FLIGHT_SIMULATOR_SLEEPCOMMAND_H


#include "Commands.h"

/*
 * This command responsible of sleep function.
 * it means the program waits for how long the command have been
 * initial at the constructor.
 */
class sleepCommand : public Commands {
    int time;
public:

    sleepCommand(mapCommand* commandMap , symbolTable* varTable, ShuntingYard* shuntingYard) :
    Commands(commandMap,varTable, shuntingYard) {
        sleepCommand::time = 0;
    }
    int execute();
    void setCommand(string&);
    ~sleepCommand(){}

};



#endif //FLIGHT_SIMULATOR_SLEEPCOMMAND_H
