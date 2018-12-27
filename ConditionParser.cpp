
#include <algorithm>
#include <regex>
#include "ConditionParser.h"
#include "utils/ShuntingYard.h"

int ConditionParser::execute() {
    if (condition == ">") {
        return left->calculate() > right->calculate();
    } else if (condition == "<") {
        return left->calculate() < right->calculate();
    } else if (condition == "!=") {
        return left->calculate() != right->calculate();
    } else if (condition == "==") {
        return left->calculate() == right->calculate();
    } else if (condition == ">=") {
        return left->calculate() >= right->calculate();
    } else { // יש מצב לבאג
        return left->calculate() <= right->calculate();
    }
}

bool ConditionParser::isSecConditionValid(string str) {
    if (str == ">") {
        return true;
    } else if (str == "<") {
        return true;
    } else if (str == "==") {
        return true;
    } else if (str == "<=") {
        return true;
    } else if (str == ">=") {
        return true;
    } else if (str == "!=") { // have to be first
        return true;
    }
    return false;
}

bool ConditionParser::isCondition(string::iterator &it) {
    if (*it == '=') {
        return true;
    } else if (*it == '!') {
        return true;
    } else if (*it == '<') {
        return true;
    } else if (*it == '>') {
        return true;
    }
}

string ConditionParser::bindString(string::iterator it1, string::iterator it2) {
    string s;
    s = *it1;
    s += *it2;
    return s;
}

string ConditionParser::getFirstParameter(string::iterator itBegin, string::iterator itEnd) {
    string firstParam;
    while (itBegin != itEnd) {
        firstParam += *itBegin;
        itBegin++;
    }
    return firstParam;
}

string ConditionParser::getExp(string::iterator &it, string::iterator itEnd) {
    string temp;
    while (!isCondition(it) && it != itEnd && *it != '{') {
        temp += *it;
        it++;
    }
    return temp;
}


// Func initialize the condition parser and check validation of the data.
void ConditionParser::setCommand(string &data) { // I treat that string as "__firstExp__Opt__secExp__" for example.
    data.erase(remove(data.begin(), data.end(), ' '), data.end());
    vector<string> vector;
    string::iterator it;
    for (it = data.begin(); it != data.end(); it++) {
        vector.push_back(getExp(it, data.end()));
        if (isCondition(it += 1)) {
            string temp;
            temp += *(--it);
            temp += *(++it);
            vector.push_back(temp);
        } else {
            it--;
        }
        string temp;
        temp += *(it);
        vector.push_back(temp);
        vector.push_back(getExp(++it, data.end()));


        left = shuntingYard->shuntingYard(vector[0]);
        condition = vector[1];
        right = right = shuntingYard->shuntingYard(vector[2]);
        if (condition.empty()) { // Case the string doesn't contain any condition.
            throw "Invalid condition";
        }
        break;
    }
}

void ConditionParser::cleanCommand(string &str, int size){
    str = str.substr(size,str.size());
}

double jumpUponCommand(double counter,Parser* parser){
    while(parser->getVector()[(unsigned) counter].find('}') == string::npos){
        counter++;
    }
    return counter;
}

bool ConditionParser::checkOpenParanthesis(double counter){
    if(parser->getVector()[(unsigned) counter].find('{') != string::npos){
        cleanWhiteSpaces(parser->getVector()[(unsigned) counter]);
        if(parser->getVector()[(unsigned) counter] == "{"){
            return true;
        }
    }
    return false;
}

int ConditionParser::numberOfWhileCommands() {
    double counter = parser->getIndex();
    double num = 1;
    while (parser->getVector()[(unsigned) counter].find('}') == string::npos) {
        if(parser->getVector()[(unsigned) counter].find("if") != string::npos){ // jump upon nested 'if'
            counter = jumpUponCommand(counter,parser);

        }else if(parser->getVector()[(unsigned) counter].find("while") != string::npos){ // jump upon nested loop
            counter = jumpUponCommand(counter,parser);
        }
        if(checkOpenParanthesis(counter)){ // check if '}' got of it's own.. doesn't count and erase line.
            parser->getVector().erase(parser->getVector().begin() + counter);
            continue;
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
    return (int)num;
}