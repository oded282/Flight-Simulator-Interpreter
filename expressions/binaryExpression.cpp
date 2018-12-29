#include "binaryExpression.h"

binaryExpression::binaryExpression(Expression *left, Expression *right) {
    binaryExpression::left = left;
    binaryExpression::right = right;
}

float binaryExpression:: calculate(){return 1;}

/*
 * This func calc the multiply of two expressions.
 */
float Mult::calculate() {
    return left->calculate() * right->calculate();
}
/*
 * This func calc the deviation of two expressions.
 */
float Div::calculate() {
    return left->calculate() / right->calculate();
}
/*
 * This func calc the sum of two expressions.
 */
float Plus::calculate() {
    return left->calculate() + right->calculate();
}
/*
 * This func calc the subtraction of two expressions.
 */
float Minus:: calculate(){
    return left->calculate() - right->calculate();
}