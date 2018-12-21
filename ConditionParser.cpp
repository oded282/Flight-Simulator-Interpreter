
#include <algorithm>
#include <regex>
#include "ConditionParser.h"
#include "ShuntingYard.h"

int ConditionParser:: execute(string str){
    setExpressions(str);
    if(condition == ">"){
        return left->calculate() > right->calculate();
    }else if(condition == "<"){
        return left->calculate() < right->calculate();
    }else if(condition == "!="){
        return left->calculate() != right->calculate();
    }else if(condition == "=="){
        return left->calculate() == right->calculate();
    }else if(condition == ">="){
        return left->calculate() >= right->calculate();
    }else if(condition == "<="){
        return left->calculate() <= right->calculate();
    }
}

bool ConditionParser::isCondition(string str){
    if(str == ">" || str == "<" || str == "!="
       || str == "==" || str == ">=" || str == "<="){
        return true;
    }
}

void ConditionParser::setExpressions(string& data){ // I treat that string as "__firstExp__Opt__secExp__" for example.
    vector<string> dataVector;
    dataVector = cleanSpace(data);
    for(int i = 0; i < dataVector.size(); i++){
        if(isCondition(dataVector[i])) {
            if(!isCondition(dataVector[i + 1])){
                string left = ShuntingYard::fromVectorToString(dataVector, 0, i - 1);
                string right = ShuntingYard::fromVectorToString(dataVector, i + 1, dataVector.size());
            }

        }

    }

}

vector<string> getExprs(string data){
    vector<string> exp;

}