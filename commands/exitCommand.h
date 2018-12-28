#ifndef FLIGHT_SIMULATOR_EXITCOMMAND_H
#define FLIGHT_SIMULATOR_EXITCOMMAND_H


#include "../commands/Commands.h"
#include "../utils/ShuntingYard.h"
#include "../data/mapCommand.h"
#include "../data/symbolTable.h"

class exitCommand : public Commands {


public:

    exitCommand(mapCommand* mapCommand1 , symbolTable* varTable , ShuntingYard* shuntingYard ) :
    Commands(mapCommand1 , varTable , shuntingYard){}

    virtual int execute();

    virtual void setCommand(string &str);


};


#endif //FLIGHT_SIMULATOR_EXITCOMMAND_H
