#include <sstream>
#include <algorithm>
#include <iostream>
#include <iterator>

#include "Commands.h"
#include "Number.h"
#include "binaryExpression.h"
#include "ShuntingYard.h"


#define MULT_OR_DIV 3
#define OPERATOR 1
#define NOT_OPERATOR 0

using namespace std;

//clean the white spaces from the string.
void Commands::cleanWhiteSpaces(string &sentence) {
    sentence.erase(remove(sentence.begin(), sentence.end(), ' '), sentence.end());
}


bool legalExpression1(char c) {
    return c == ',';
}

bool legalExpression2(vector<string> &v, int i) {
    // check if there is digit after digit (x x).
    return isdigit(v[i - 1][v[i - 1].size() - 1]) && isdigit(v[i][0]);
}


Commands::Commands(mapCommand *commandTable, symbolTable *varTable, ShuntingYard *shuntingYard) {
    Commands::commandTable = commandTable;
    Commands::varTable = varTable;
    Commands::shuntingYard = shuntingYard;
}

vector<string> Commands::cleanSpace(string str) {
    istringstream iss(str);
    vector<std::string> result(istream_iterator<std::string>{iss},
                               istream_iterator<std::string>());
    return result;
}

vector<string> Commands::getParameters(string &str) {
    string parameter1, parameter2;
    vector<string> result = cleanSpace(str);
    for (int i = 1; i < result.size(); i++) {
        if (legalExpression1(result[i][0]) || legalExpression2(result, i)) {
            result.clear();
            result.push_back(shuntingYard->fromVectorToString(result , 1 , i ));
            result.push_back(shuntingYard->fromVectorToString(result , i, );
            break;
        }
    }
    return result;
}


///test.
//nt main() {
//   string string1 = "-5*(10+3)/4";
//   string string2 = "(5-6)*(10+3)/4";
//   Commands *c;
//   Expression* e = c->shuntingYard(string1);
//   double d = e->calculate();
//   e = c->shuntingYard(string2);
//   d = e->calculate();

//   cout << " " << endl ;
//