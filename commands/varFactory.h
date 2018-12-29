
#ifndef FLIGHT_SIMULATOR_VARFACTORY_H
#define FLIGHT_SIMULATOR_VARFACTORY_H


#include "Commands.h"
#include "../data/symbolTable.h"
#include "../data/mapCommand.h"

/*
 * Tihs class is a factory who creates variables.
 */
class varFactory : public Commands {
    Expression* numZero;

public:

    varFactory(mapCommand* commandTable, symbolTable* varTable , ShuntingYard* shuntingYard);
    virtual int execute();
    virtual void setCommand(string& str);
    string getName(string::iterator& it,string::iterator itEnd);
    string getSentence(string::iterator& it,string::iterator itEnd);
    void getVariables(string sentence,vector<string>& vector, bool isBind);
    string::iterator jumpToSentence(string::iterator it);
    ~varFactory(){
        delete numZero;
    }
};


#endif //FLIGHT_SIMULATOR_VARFACTORY_H
