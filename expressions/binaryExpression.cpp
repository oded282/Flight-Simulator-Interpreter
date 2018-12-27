#include "binaryExpression.h"

binaryExpression::binaryExpression(Expression *left, Expression *right) {
    binaryExpression::left = left;
    binaryExpression::right = right;
}

double binaryExpression:: calculate(){}

double Mult::calculate() {
    return left->calculate() * right->calculate();
}

double Div::calculate() {
    return left->calculate() / right->calculate();
}

double Plus::calculate() {
    return left->calculate() + right->calculate();
}

double Minus:: calculate(){
    return left->calculate() - right->calculate();
}