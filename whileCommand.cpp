

#include "whileCommand.h"

double jumpUponCommand(double counter,Parser* parser){
    while(parser->getVector()[(unsigned) counter].find('}') == string::npos){
        counter++;
    }
    return ++counter;
}

int whileCommand::numberOfWhileCommands() {
    double counter = parser->getIndex();
    double num = 1;
    while (parser->getVector()[(unsigned) counter].find('}') == string::npos) {
        if(parser->getVector()[(unsigned) counter].find("if") != string::npos){
            counter = jumpUponCommand(counter,parser);

        }else if(parser->getVector()[(unsigned) counter].find("while") != string::npos){
            counter = jumpUponCommand(counter,parser);
        }
        counter++;
        num++;
    }
    string& temp = parser->getVector()[(unsigned) counter];
    cleanWhiteSpaces(temp);
    if (temp[0] == '}') {
        num -= 1;

        parser->getVector().erase(parser->getVector().begin() + counter);

    }
    //removeClosingParanthesis(counter);
    return (int)num;
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