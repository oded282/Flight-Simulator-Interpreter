#include <iostream>
#include <algorithm>
#include "ShuntingYard.h"
#include "../expressions/binaryExpression.h"
#include "../expressions/Number.h"


string charToString(char c) {
    string s(1, c);
    return s;
}

// check if the char is character.
bool ShuntingYard::isCharacter(char c) {
    return (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A');
}

// check if the char is digit.
bool ShuntingYard::isdigit(char c) {
    return c <= '9' && c >= '0';
}

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

//check if the string is ligal.
bool ShuntingYard::checkForValidation(string str) {
    int countParenthesis = 0;
    string::iterator itr;
    //run over the string char by char.
    for (itr = str.begin(); itr != str.end(); itr++) {
        // check if the first char is operator '*' or '/'.
        if (itr == str.begin() && isOperator(*itr) == MULT_OR_DIV) {
            return false;
        }
        // check if the is to operators in a row.
        if (isOperator(*itr) > OPERATOR1 && isOperator(*(itr + 1)) > OPERATOR2) {
            return false;
        }
        // check if the is "x(..." x is number or var.
        if (isOperator(*itr) == NOT_OPERATOR && *(itr + 1) == '(') {
            return false;
        }
        //count the open parenthesis.
        if (*itr == '(') {
            countParenthesis++;
        }
        // check if there is ')' with '(' before.
        if (*itr == ')') {
            if (countParenthesis > 0) {
                countParenthesis--;
            } else {
                return false;
            }
        }
        string var;
        if (isCharacter(*itr)) {
            while (isOperator(*itr) == 0 && itr != str.end()){
                var += *itr;
                itr++;
            };
            itr--;
        }
        if (!var.empty()) {
            map<string, commandExpression *>::iterator it;
            Var* v = varMap->getVar(var);
            if (v == nullptr) {
                return false;
            }
        }
    }
    return countParenthesis == 0;
}

//read the number or var from the string, and push to the queue.
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

// push operator to the stack.
void pointOnOperator(string::iterator &itr, stack<char> &stack, queue<string> &queue) {
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
            queue.push(charToString(stack.top()));
            stack.pop();
        }
    }
    // return all the operator to the stack.
    while (!temp.empty()) {
        stack.push(temp[temp.size() - 1]);
        temp.pop_back();
    }

}

//get string of expression and return expression.
Expression *ShuntingYard::fromStringToExpresion(string s, stack<Expression *> &stack) {
    //send the number expression.
    if (isdigit(s[0])) {
        Expression *e = new Number(stoi(s));
        collectorDelet.push_back(e);
        return e;
    }

    //send the var Expression.
    if (isCharacter(s[0])) {
        Expression *e = commandTable->getCommandExpression(s);
        return e;
    }

    if (s == "*") {
        Expression *e1 = stack.top();
        stack.pop();
        Expression *e2 = stack.top();
        stack.pop();
        Expression *e = new Mult(e2, e1);
        collectorDelet.push_back(e);
        return e;
    }
    if (s == "/") {
        Expression *e1 = stack.top();
        stack.pop();
        Expression *e2 = stack.top();
        stack.pop();
        Expression *e = new Div(e2, e1);
        collectorDelet.push_back(e);
        return e;
    }
    if (s == "+") {
        Expression *e1 = stack.top();
        stack.pop();
        Expression *e2 = stack.top();
        stack.pop();
        Expression *e = new Plus(e2, e1);
        collectorDelet.push_back(e);
        return e;
    }
    if (s == "-") {
        Expression *e1 = stack.top();
        stack.pop();
        Expression *e2 = stack.top();
        stack.pop();
        Expression *e = new Minus(e2, e1);
        collectorDelet.push_back(e);
        return e;
    }

    return nullptr;
}


//push '(' to the stack.
void openParenthesis(string::iterator &itr, stack<char> &stack) {
    if (*itr == '(') {
        stack.push('(');
        itr++;
    }
}

// put the string in queue by order.
queue<string> ShuntingYard::putInQueue(string &infx) {
    queue<string> queue;
    stack<char> stack;
    string::iterator itr;

    if (!checkForValidation(infx)) {
        throw "Invalid Expression!";
    }

    for (itr = infx.begin(); itr != (infx.end() + 1); itr++) {
        //if the first char is '-' or '+', push 0 to the queue.
        if (itr == infx.begin() && isOperator(*itr) == 2) {
            queue.push("0");
            itr++;
            readString(itr, queue, infx);
            queue.push("-");
        }

        // check if itr point on '('.
        openParenthesis(itr, stack);

        // check if itr point on number or var.
        readString(itr, queue, infx);

        // check if itr point on ')'.
        closeParenthesis(itr, stack, queue);

        // if itr point on operator.
        pointOnOperator(itr, stack, queue);

    }
    // put all in the queue.
    while (!stack.empty()) {
        queue.push(charToString(stack.top()));
        stack.pop();
    }
    return queue;
}


// the main func of shunting yard algorithm.
Expression *ShuntingYard::shuntingYard(string infx) {

    queue<string> queue = putInQueue(infx);
    stack<Expression *> stack;
    while (!queue.empty()) {

        string str;
        str = queue.front();
        queue.pop();
        Expression *e = fromStringToExpresion(str, stack);
        if (e == nullptr) {
            throw "Invalid VarCommand!";
        }
        stack.push(e);
    }
    return stack.top();
}

string ShuntingYard::fromVectorToString(vector<string> &result, int i, int k) {
    string parameter;
    //copy to parameter 1 and parameter 2.
    while (i < k) {
        parameter += result[i];
        i++;
    }
    return parameter;

}
