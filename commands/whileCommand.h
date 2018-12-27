
#ifndef FLIGHT_SIMULATOR_WHILECOMMAND_H
#define FLIGHT_SIMULATOR_WHILECOMMAND_H


#include "Commands.h"
#include "../data/mapCommand.h"
#include "../ConditionParser.h"

class whileCommand : public ConditionParser{
    int count = 0;
    bool isParsedNeeded = true;

public:

    virtual int execute();
    whileCommand(Parser* parser, mapCommand* mapTable , symbolTable* varTable , ShuntingYard* shuntingYard) :
    ConditionParser(parser, mapTable,varTable , shuntingYard){}
    virtual void setCommand(string& str);
    int numberOfWhileCommands();
    bool checkOpenParanthesis(double counter);
    void removeClosingParanthesis(double counter);
    void setParser(Parser*);
    double setIndex();
    ~whileCommand(){}

};

#endif //FLIGHT_SIMULATOR_WHILECOMMAND_H
