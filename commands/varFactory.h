
#ifndef FLIGHT_SIMULATOR_VARFACTORY_H
#define FLIGHT_SIMULATOR_VARFACTORY_H


#include "Commands.h"
#include "../data/symbolTable.h"
#include "../data/mapCommand.h"


class varFactory : public Commands {
    Expression* numZero;

public:

    varFactory(mapCommand* commandTable, symbolTable* varTable , ShuntingYard* shuntingYard);
    virtual int execute();
    virtual void setCommand(string& str);
    string getName(string::iterator& it,string::iterator itEnd);
    string getSentence(string::iterator& it,string::iterator itEnd);
    string::iterator jumpToStartOfVar(string::iterator it);
    void getVariables(string sentence,vector<string>& vector, bool isBind);
    string::iterator jumpSpace(string::iterator& it);
    string::iterator jumpUponWord(string::iterator it);
    string::iterator jumpToSentence(string::iterator it);
    ~varFactory(){
        delete numZero;
    }
};


#endif //FLIGHT_SIMULATOR_VARFACTORY_H
