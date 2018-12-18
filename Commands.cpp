#include <sstream>
#include <algorithm>
#include <iostream>
//#include "mapCommand.h"
//#include "symbolTable.h"
#include "Commands.h"
#include "Number.h"
#include "Mult.h"
#include "Div.h"
#include "Plus.h"
#include "Minus.h"

using namespace std;

int isOperator(char c) {
    switch (c) {
        case '+':
            return 2;
        case '-':
            return 2;
        case '/':
            return 3;
        case '*':
            return 3;
        case ')':
            return 1;
        case '(':
            return 1;
        default:
            return 0;
    }

}

bool Commands::checkForValidation(string str) {
    int countParenthesis = 0;
    string::iterator itr;
    for (itr = str.begin(); itr != str.end(); itr++) {
        if (itr == str.begin() && isOperator(*itr) == 3){
            return false;
        }
        // check if the is to operators in a row.
        if (isOperator(*itr) > 1 && isOperator(*(itr + 1)) > 1) {
            return false;
        }
        // check if the is "x(..." x is number or var.
        if (isOperator(*itr) == 0 && *(itr + 1) == '(') {
            return false;
        }
        if (*itr == '(') {
            countParenthesis++;
        }
        // check of there is ')' with '(' before.
        if (*itr == ')') {
            if (countParenthesis > 0) {
                countParenthesis--;
            } else {
                return false;
            }
        }


        //TODO check if the var is exists
        // check valid var
//       string var;
//       while (isCharacter(*itr)){


//            itr++;
//       }

    }

    if (countParenthesis != 0) {
        return false;
    }
    return true;
}


string charToString(char c) {
    string s(1, c);
    return s;
}

bool Commands::isCharacter(char c) {
    return (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A');
}

bool Commands::isdigit(char c) {
    return c <= '9' && c >= '0';
}


void Commands::cleanWhiteSpaces(string &sentence) {
    sentence.erase(remove(sentence.begin(), sentence.end(), ' '), sentence.end());
}

//bool isVarExist(string expression){
//    return symbolTable.find(expression) != symbolTable.end();
//
//}

void readString(string::iterator &itr, queue<string> &queue, string &infx) {
    string str;
    while (itr != infx.end() && isOperator(*itr) == 0) {
        str.push_back(*itr);
        itr++;
    }
    if (!str.empty()) {
        queue.push(str);
    }
}

void openParenthesis(string::iterator &itr, stack<char> &stack) {
    if (*itr == '(') {
        stack.push('(');
        itr++;
    }
}

void closeParenthesis(string::iterator &itr, stack<char> &stack, queue<string> &queue) {
    if (*itr == ')') {
        while (true) {
            // push all the operator in the top of the stack to the queue,
            // until there is '(' on the top of the stack.
            if (stack.top() != '(') {
                queue.push(charToString(stack.top()));
                stack.pop();
            } else {
                stack.pop();
                itr++;
                break;
            }
        }
    }
}

void pointOnOperator(string::iterator &itr, stack<char> &stack) {
    vector<char> temp;
    if (isOperator(*itr) != 0) {
        while (true) {

            if (stack.empty() || isOperator(*itr) >= isOperator(stack.top())) {
                //the stack is empty or the operator in the itr is with higher priority.
                //push to the stack.
                stack.push(*itr);
                break;
            }
            //else save the top operator on the stack and pop the operator.
            temp.push_back(stack.top());
            stack.pop();
            itr++;
        }
    }
    // return all the operator to the stack.
    while (!temp.empty()) {
        stack.push(temp[temp.size() - 1]);
        temp.pop_back();
    }

}

queue<string> Commands::putInQueue(string &infx) {
    queue<string> queue;
    stack<char> stack;
    string::iterator itr;

    if (!checkForValidation(infx)) {
        throw "Invalid Expression!";
    }

    for (itr = infx.begin(); itr != (infx.end() + 1); itr++) {
        if (itr == infx.begin() && isOperator(*itr) == 2){
            queue.push("0");
        }

        // check if itr point on '('.
        openParenthesis(itr, stack);

        // check if itr point on number or var.
        readString(itr, queue, infx);

        // check if itr point on ')'.
        closeParenthesis(itr, stack, queue);

        // if itr point on operator.
        pointOnOperator(itr, stack);

    }
    // put all in the queue.
    while (!stack.empty()) {
        queue.push(charToString(stack.top()));
        stack.pop();
    }
    return queue;

}

Expression *Commands::fromStringToExpresion(string s, stack<Expression *> &stack) {

    if (isdigit(s[0])) {
        Expression* e = new Number(stoi(s));
        return e;
    }
//    if (isCharacter(s[0])) {
//        stack.push((Expression)table->getSymbol(s))
//        return stack.top();
//    }

    if (s == "*") {
        Expression *e1 = stack.top();
        stack.pop();
        Expression *e2 = stack.top();
        stack.pop();
        Expression *e = new Mult(e2, e1);
        return e;
    }
    if (s == "/") {
        Expression *e1 = stack.top();
        stack.pop();
        Expression *e2 = stack.top();
        stack.pop();
        Expression *e = new Div(e2, e1);
        return e;
    }
    if (s == "+") {
        Expression *e1 = stack.top();
        stack.pop();
        Expression *e2 = stack.top();
        stack.pop();
        Expression *e = new Plus(e2, e1);
        return e;
    }
    if (s == "-") {
        Expression *e1 = stack.top();
        stack.pop();
        Expression *e2 = stack.top();
        stack.pop();
        Expression *e = new Minus(e2, e1);
        return e;
    }

    return nullptr;
}


Expression *Commands::shuntingYard(string infx) {

    queue<string> queue = putInQueue(infx);
    stack<Expression*> stack;
    while (!queue.empty()) {

        string str;
        str = queue.front();
        queue.pop();
        Expression* e = fromStringToExpresion(str , stack);
        stack.push(e);
    }
    return stack.top();
}


int main() {
    string string1 = "-5*(10+3)/4";
    string string2 = "(5-6)*(10+3)/4";
    Commands *c;
    Expression* e = c->shuntingYard(string1);
    double d = e->calculate();
    e = c->shuntingYard(string2);
    d = e->calculate();

    cout << " " << endl ;
}