
#include "whileCommand.h"


//double jumpUponCommand(double counter,Parser* parser){
//    while(parser->getVector()[(unsigned) counter].find('}') == string::npos){
//        counter++;
//    }
//    return counter;
//}
//
//bool whileCommand::checkOpenParanthesis(double counter){
//    if(parser->getVector()[(unsigned) counter].find('{') != string::npos){
//        cleanWhiteSpaces(parser->getVector()[(unsigned) counter]);
//        if(parser->getVector()[(unsigned) counter] == "{"){
//            return true;
//        }
//    }
//    return false;
//}
//
//int whileCommand::numberOfWhileCommands() {
//    double counter = parser->getIndex();
//    double num = 1;
//    while (parser->getVector()[(unsigned) counter].find('}') == string::npos) {
//        if(parser->getVector()[(unsigned) counter].find("if") != string::npos){ // jump upon nested 'if'
//            counter = jumpUponCommand(counter,parser);
//
//        }else if(parser->getVector()[(unsigned) counter].find("while") != string::npos){ // jump upon nested loop
//            counter = jumpUponCommand(counter,parser);
//        }
//        if(checkOpenParanthesis(counter)){ // check if '}' got of it's own.. doesn't count and erase line.
//            parser->getVector().erase(parser->getVector().begin() + counter);
//            continue;
//        }
//        counter++;
//        num++;
//    }
//    string& temp = parser->getVector()[(unsigned) counter];
//    cleanWhiteSpaces(temp);
//    if (temp[0] == '}') {
//        num -= 1;
//        parser->getVector().erase(parser->getVector().begin() + counter);
//    }
//    return (int)num;
//}

int whileCommand::execute() {
    if(ConditionParser::execute()){
        commands = parser->doParser(ConditionParser::numberOfWhileCommands());
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


void whileCommand::setCommand(string &str) {
    cleanWhiteSpaces(str);
    cleanCommand(str, 5);
    ConditionParser::setCommand(str);
}

void whileCommand::setParser(Parser *p) {
    whileCommand::parser = p;
}