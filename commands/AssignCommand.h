#ifndef FLIGHT_SIMULATOR_ASSIGNCOMMAND_H
#define FLIGHT_SIMULATOR_ASSIGNCOMMAND_H


#include "Commands.h"
#include "VarCommand.h"
#include "connectCommand.h"

class connectCommand;
/*
 * This class used to assign values to some variable.
 * Every assign command have the expression left to the equal sign and
 * the expression right to the equal sign, and the evaluated parameter.
 */
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
