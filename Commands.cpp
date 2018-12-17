#include <sstream>
#include <stack>
#include <algorithm>
#include <queue>
#include "Commands.h"

using namespace std;

bool Commands::isNumber (char c){
    return c <= '9' && c >= '0';
}

int Commands::isOperator(char c){
    switch (c) {
        case '+':
            return 1;
        case '-':
            return 1;
        case '/':
            return 2;
        case '*':
            return 2;
        default:
            return 0;
    }

}


void Commands::cleanWhiteSpaces(string& sentence){
    sentence.erase( remove( sentence.begin(), sentence.end(), ' ' ), sentence.end() );
}

Expression Commands::shuntingYard(string infx) {
    queue <string> queue;
    stack <char> stack;
    stack <char> tempStack;
    string str;
    string::iterator itr;
    for(itr = infx.begin() ; itr != infx.end() ; itr++){
        if (isOperator(*itr)){
            throw "Invalid Expression!";
        }
        if (infx[0] == '('){
            stack.push('(');
            itr++;
        }
        while (!isOperator(*itr)){
            str.push_back(*itr);
            itr++;
        }
        queue.push(str);

        while (true){
            if (isOperator(*itr) > isOperator(stack.top())){
                stack.push(*itr);
                break;
            }
            tempStack.push(stack.pop());
        }
        while (tempStack.isEmpty()){
            stack.push(tempStack.pop());
        }









    }





}