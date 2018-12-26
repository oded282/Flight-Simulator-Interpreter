

#ifndef FLIGHT_SIMULATOR_ASSIGNCOMMAND_H
#define FLIGHT_SIMULATOR_ASSIGNCOMMAND_H


#include "Commands.h"
#include "Var.h"
#include "connectCommand.h"

class connectCommand;

class AssignCommand : public Commands {

    connectCommand *connect;
    Var *left;
    Expression* right;
    Expression* value;

public:
    AssignCommand(connectCommand* ,mapCommand *commandTable, symbolTable *varTable, ShuntingYard *shuntingYard);

    void setConnectCommand(connectCommand* c);


    virtual int execute();

    virtual void setCommand(string &str);

    void setFriends(Var* var);

    ~AssignCommand(){}

};


#endif //FLIGHT_SIMULATOR_ASSIGNCOMMAND_H
