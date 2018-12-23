
#ifndef FLIGHT_SIMULATOR_VARFACTORY_H
#define FLIGHT_SIMULATOR_VARFACTORY_H


#include "Commands.h"
#include "symbolTable.h"


class varFactory : public Commands {


public:
    varFactory(mapCommand* commandTable, symbolTable* varTable , ShuntingYard* shuntingYard);
    virtual int execute();
    virtual void setCommand(string& str) = 0;
    string getName(string::iterator it);
    string getSentence(string::iterator it,string::iterator itEnd);
    string::iterator jumpToStartOfVar(string::iterator it);
    string getVariables(string sentence,vector<string>& vector, bool isBind);
    string::iterator jumpSpace(string::iterator it);
    string::iterator jumpUponWord(string::iterator it);
    string::iterator jumpToSentence(string::iterator it);
};


#endif //FLIGHT_SIMULATOR_VARFACTORY_H
