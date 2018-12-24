

#ifndef FLIGHT_SIMULATOR_ASSIGNCOMMAND_H
#define FLIGHT_SIMULATOR_ASSIGNCOMMAND_H


#include "Commands.h"
#include "Var.h"
#include "connectCommand.h"

class connectCommand;

class AssignCommand : public Commands {


    connectCommand *connect;
    Var *left;
    Expression *right;

public:
    AssignCommand(mapCommand *commandTable, symbolTable *varTable, ShuntingYard *shuntingYard,
                  connectCommand *connect);

    virtual int execute();

    virtual void setCommand(string &str);


};


#endif //FLIGHT_SIMULATOR_ASSIGNCOMMAND_H
