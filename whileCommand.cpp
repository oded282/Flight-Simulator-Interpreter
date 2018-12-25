

#include "whileCommand.h"

int whileCommand::numberOfWhileCommands() {
    double counter = parser->getIndex();
    while (!parser->getVector()[(unsigned) counter].find('}')) {
        counter++;
    }
    string temp = parser->getVector()[(unsigned) counter];
    cleanWhiteSpaces(temp);
    if (temp[0] == '}') {
        counter -= 1;
        parser->getVector().erase(parser->getVector().begin() + counter);

    }
    removeClosingParanthesis(counter);
    return (int)counter;
}

int whileCommand::execute() {
    vector<commandExpression*> ::iterator it;
    it = commands.begin();
    if(ConditionParser::execute()){
        commands = parser->doParser(numberOfWhileCommands());
    }
    while (ConditionParser::execute()) {
        for(commandExpression* val: commands){
            val->calculate();
        }
    }

    return 1;
}


void whileCommand::removeClosingParanthesis(double counter) {
    parser->getVector()[counter].erase(parser->getVector()[counter].begin() + counter);
}

string:: iterator iterateToCondition(string:: iterator it){
    while(*it != '('){
        it++;
    }
    return it++;
}

string getTheCondition(string:: iterator it){
    string temp;
    while(*it != ')'){
        temp += *it;
    }
    return temp;
}

void cleanCommand(string &str){
    str = str.substr(5,str.size());
}


void whileCommand::setCommand(string &str) {
    cleanWhiteSpaces(str);
    cleanCommand(str);
    ConditionParser::setCommand(str);
}

void whileCommand::setParser(Parser *p) {
    whileCommand::parser = p;
}