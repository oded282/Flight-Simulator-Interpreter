
#ifndef FLIGHT_SIMULATOR_CONDITIONPARSER_H
#define FLIGHT_SIMULATOR_CONDITIONPARSER_H


#include "Commands.h"
#include "../utils/Parser.h"

class ConditionParser : public Commands {

protected:
    vector<commandExpression*> commands;
    Parser *parser;
    Expression *left;
    Expression *right;
    string condition;

public:
    ConditionParser() : Commands(nullptr, nullptr , nullptr) {};
    ConditionParser(Parser *parser, mapCommand *mapTable, symbolTable *varTable , ShuntingYard* shuntingYard) :
    Commands(mapTable, varTable  ,shuntingYard) {
        ConditionParser::parser = parser;
        left = nullptr;
        right = nullptr;
    }
    bool isCondition(string::iterator &it);
    string getExp(string ::iterator& it, string ::iterator itEnd);
    virtual void setCommand(string& data);
    virtual int execute();
    void cleanCommand(string &str, int size);
    bool checkOpenParanthesis(double counter);
    int numberOfWhileCommands();
};


#endif //FLIGHT_SIMULATOR_CONDITIONPARSER_H
