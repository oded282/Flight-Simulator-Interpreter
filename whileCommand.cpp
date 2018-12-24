

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


void whileCommand::setCommand(string &str) {
    ConditionParser::setCommand(str);
}

void whileCommand::setParser(Parser *p) {
    whileCommand::parser = p;
}