#ifndef FLIGHT_SIMULATOR_PRINTCOMMAND_H
#define FLIGHT_SIMULATOR_PRINTCOMMAND_H


#include "Commands.h"

/*
 * This command responsible to print the expression value.
 */
class PrintCommand : public Commands {

    string str;

public:
    PrintCommand(mapCommand* commandMap , symbolTable* varTable, ShuntingYard* shuntingYard) :
            Commands(commandMap,varTable, shuntingYard){};
    int execute();
    void setCommand(string&);

    ~PrintCommand(){}

};


#endif //FLIGHT_SIMULATOR_PRINTCOMMAND_H
