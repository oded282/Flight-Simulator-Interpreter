#include <sstream>
#include <algorithm>
#include <queue>
#include "Commands.h"
#include "Expression.h"

using namespace std;

bool Commands::isNumber(char c) {
    return c <= '9' && c >= '0';
}

int Commands::isOperator(char c) {
    switch (c) {
        case '+':
            return 1;
        case '-':
            return 1;
        case '/':
            return 2;
        case '*':
            return 2;
        case ')':
            return -1;
        case '(':
            return -1;
        default:
            return 0;
    }

}


void Commands::cleanWhiteSpaces(string &sentence) {
    sentence.erase(remove(sentence.begin(), sentence.end(), ' '), sentence.end());
}

//bool isVarExist(string expression){
//    return symbolTable.find(expression) != symbolTable.end();
//
//}

Expression* Commands::shuntingYard(string infx) {
    queue<string> queue;
    stack<char> stack;
    vector<char> temp;
    string str;
    string::iterator itr;
    for (itr = infx.begin(); itr != infx.end(); itr++) {
        if (*itr == '(') {
            stack.push('(');
            itr++;
        }
        while (isOperator(*itr) == 0) {
            str.push_back(*itr);
            itr++;
        }
        //TODO
        queue.push(str);
        str = "";
        if (*itr == ')') {
            while (true) {
                if (stack.top() != '(') {
                    queue.push(stack.top());
                    stack.pop();
                } else {
                    stack.pop();
                    break;
                }
            }
        }

        while (true) {
            if (stack.empty() || isOperator(*itr) > isOperator(stack.top())) {
                stack.push(*itr);
                break;
            }
            temp.push_back(stack.top());
            stack.pop();
        }
        while (!temp.empty()) {
            stack.push(temp[temp.size() - 1]);
            temp.pop_back();
        }

    }
    return nullptr;
}
int main(){
    string string1 = "5*(10+3)/4";
    string string2 = "(5-6)*(10+3)/4";
    Commands* c;
    c->shuntingYard(string1);
    c->shuntingYard(string2);


}