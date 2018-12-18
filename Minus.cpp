#include "Minus.h"


double Minus:: calculate(){
    return left->calculate() - right->calculate();
}