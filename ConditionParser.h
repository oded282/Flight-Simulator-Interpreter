
#ifndef FLIGHT_SIMULATOR_CONDITIONPARSER_H
#define FLIGHT_SIMULATOR_CONDITIONPARSER_H


#include "Commands.h"
#include "Parser.h"

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
    bool isSecConditionValid(string str);
    bool isCondition(string::iterator &it);
    virtual void setCommand(string& data);
    string getFirstParameter(string :: iterator itBegin , string :: iterator itEnd );
    string bindString(string ::iterator it1, string ::iterator it2);
    virtual int execute();

};


#endif //FLIGHT_SIMULATOR_CONDITIONPARSER_H
