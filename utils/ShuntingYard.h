#ifndef FLIGHT_SIMULATOR_SHUNTINGYARD_H
#define FLIGHT_SIMULATOR_SHUNTINGYARD_H
#include <string>
#include <map>
#include <queue>
#include <stack>
class mapCommand;
class Expression;
class symbolTable;
using namespace std;
#define MULT_OR_DIV 3
#define OPERATOR1 1
#define OPERATOR2 2
#define NOT_OPERATOR 0

class ShuntingYard {
    symbolTable* varMap;
    mapCommand* commandTable;
    vector<Expression*> collectorDelet;
public:
    ShuntingYard(symbolTable *varMap ,mapCommand*  map) {
        ShuntingYard::varMap = varMap;
        ShuntingYard::commandTable = map;
    }
     bool checkForValidation(string);
     Expression* shuntingYard(string);
     queue<string> putInQueue(string&);
     Expression* fromStringToExpresion(string,stack<Expression*>&);
     bool isdigit(char);
     bool isCharacter(char);
     string fromVectorToString(vector<string> &result, int i, int k);

     ~ShuntingYard(){
         for (Expression* itr : collectorDelet){
             delete itr;
         }
     }

};


#endif //FLIGHT_SIMULATOR_SHUNTINGYARD_H
