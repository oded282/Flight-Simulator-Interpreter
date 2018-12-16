//
// Created by oded on 12/16/18.
//

#include "Minus.h"

Minus::Minus(Expression* left, Expression* right){
    Minus::left = left;
    Minus::right = right;
}

double Minus:: calculate(){
    return left->calculate() - right->calculate();
}