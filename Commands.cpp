#include <sstream>
#include <algorithm>
#include <iostream>

#include "Commands.h"
#include "Number.h"
#include "binaryExpression.h"


#define MULT_OR_DIV 3
#define OPERATOR 1
#define NOT_OPERATOR 0

using namespace std;

//check if the char is operator
//return 0 if not ,1 if '(' or ')' ,2 if '+' or '-' else 3 its '*' or '/'.
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
bool Commands::checkForValidation(string str) {
    int countParenthesis = 0;
    string::iterator itr;
    //run over the string char by char.
    for (itr = str.begin(); itr != str.end(); itr++) {
        // check if the first char is operator '*' or '/'.
        if (itr == str.begin() && isOperator(*itr) == MULT_OR_DIV){
            return false;
        }
        // check if the is to operators in a row.
        if (isOperator(*itr) > OPERATOR && isOperator(*(itr + 1)) > OPERATOR) {
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

        //TODO check if the var is exists
        // check valid var
//       string var;
//       while (isCharacter(*itr)){
//            itr++;
//       }
    }
    return countParenthesis == 0;
}

//TODO is var exist.
//bool isVarExist(string expression){
//    return symbolTable.find(expression) != symbolTable.end();
//
//}

// get char return string.
string charToString(char c) {
    string s(1, c);
    return s;
}

// check if the char is character.
bool Commands::isCharacter(char c) {
    return (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A');
}

// check if the char is digit.
bool Commands::isdigit(char c) {
    return c <= '9' && c >= '0';
}

//clean the white spaces from the string.
void Commands::cleanWhiteSpaces(string &sentence) {
    sentence.erase(remove(sentence.begin(), sentence.end(), ' '), sentence.end());
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

//push '(' to the stack.
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

// push operator to the stack.
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

// put the string in queue by order.
queue<string> Commands::putInQueue(string &infx) {
    queue<string> queue;
    stack<char> stack;
    string::iterator itr;

    if (!checkForValidation(infx)) {
        throw "Invalid Expression!";
    }

    for (itr = infx.begin(); itr != (infx.end() + 1); itr++) {
        //if the first char is '-' or '+', push 0 to the queue.
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

//get string of expression and return expression.
Expression *Commands::fromStringToExpresion(string s, stack<Expression *> &stack) {

    if (isdigit(s[0])) {
        Expression* e = new Number(stoi(s));
        return e;
    }

    //TODO push the var to the stack.
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

// the main func of shunting yard algorithm.
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

//test.
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