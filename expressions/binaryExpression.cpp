#include "binaryExpression.h"

binaryExpression::binaryExpression(Expression *left, Expression *right) {
    binaryExpression::left = left;
    binaryExpression::right = right;
}

float binaryExpression:: calculate(){}

float Mult::calculate() {
    return left->calculate() * right->calculate();
}

float Div::calculate() {
    return left->calculate() / right->calculate();
}

float Plus::calculate() {
    return left->calculate() + right->calculate();
}

float Minus:: calculate(){
    return left->calculate() - right->calculate();
}