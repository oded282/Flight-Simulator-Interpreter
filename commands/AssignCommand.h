#ifndef FLIGHT_SIMULATOR_ASSIGNCOMMAND_H
#define FLIGHT_SIMULATOR_ASSIGNCOMMAND_H


#include "Commands.h"
#include "VarCommand.h"
#include "connectCommand.h"

class connectCommand;

class AssignCommand : public Commands {

    connectCommand *connect;
    VarCommand *left;
    Expression* right;
    Expression* value;
    vector<Expression*> colector;

public:
    AssignCommand(connectCommand* ,mapCommand *commandTable, symbolTable *varTable, ShuntingYard *shuntingYard);

    void setConnectCommand(connectCommand* c);

    virtual int execute();

    virtual void setCommand(string &str);

    void setFriends(VarCommand* var);

    ~AssignCommand(){
        for (Expression* itr : colector){
            delete itr;
        }
    }

};


#endif //FLIGHT_SIMULATOR_ASSIGNCOMMAND_H
