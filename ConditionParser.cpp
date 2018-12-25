
#include <algorithm>
#include <regex>
#include "ConditionParser.h"
#include "ShuntingYard.h"

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

string ConditionParser::getExp(string ::iterator& it, string ::iterator itEnd){
    string temp;
    while(!isCondition(it) && it != itEnd && *it != '{'){
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
        }
        it--;
        string temp;
        temp += *(it);
        vector.push_back(temp);
        vector.push_back(getExp(++it, data.end()));



  //      if (isCondition(it)) {// Case the first operator is valid.
  //          if (isCondition(it += 1)) { // Case the sec operator is valid.
  //              it--;
  //              if (isSecConditionValid(bindString(it, it += 1))) { // If two operator combined to one valid operator.
  //                  it--;
  //                  condition = *it;
  //                  condition += *(it + 1);
  //                  left = shuntingYard->shuntingYard(getFirstParameter(data.begin(), it)); // What to do if it is a var? example in main
  //                  right = shuntingYard->shuntingYard(getFirstParameter(it += 2, data.end()));
  //              } else {
  //                  throw "Invalid condition";
//
  //              }
  //          } else {
  //              it--;
  //              condition = *it;
  //              left = shuntingYard->shuntingYard(getFirstParameter(data.begin(), it)); // What to do if it is a var? example in main
  //              right = shuntingYard->shuntingYard(getFirstParameter(it += 1, data.end()));
  //          }
  //      }
    }
    left = shuntingYard->shuntingYard(vector[0]);
    condition = vector[1];
    right = right = shuntingYard->shuntingYard(vector[2]);
    if (condition.empty()) { // Case the string doesn't contain any condition.
        throw "Invalid condition";
    }
}

//nt main() {
//   ConditionParser cond;
//   string s = "var <= 1000";
//   cond.setExpressions(s);
