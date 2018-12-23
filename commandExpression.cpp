#include "commandExpression.h"



double commandExpression::calculate(){
    return this->command->execute();
}


