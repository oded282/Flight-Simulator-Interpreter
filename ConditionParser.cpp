
#include <algorithm>
#include <regex>
#include "ConditionParser.h"
int ConditionParser:: execute(){
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

void ConditionParser::setExpressions(string data){ // I treat that string as "__firstExp__Opt__secExp__" for example.
    string ::iterator it;
    data.erase(remove(data.begin(), data.end(), " "), data.end());
    vector<string> expressions = getExprs();


}

vector<string> getExprs(string data){
    vector<string> exp;

}