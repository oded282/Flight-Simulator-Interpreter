#include <sstream>
#include <algorithm>
#include <iostream>
#include <iterator>

#include "Commands.h"
#include "../expressions/Number.h"
#include "../expressions/binaryExpression.h"
#include "../utils/ShuntingYard.h"


#define MULT_OR_DIV 3
#define OPERATOR 1
#define NOT_OPERATOR 0

using namespace std;

//clean the white spaces from the string.
void Commands::cleanWhiteSpaces(string &sentence) {
    sentence.erase(remove(sentence.begin(), sentence.end(), ' '), sentence.end());
}

/*
 * Check for validation.
 */
bool legalExpression1(char c) {
    return c == ',' ;
}

/*
 * Check for validation.
 */
bool legalExpression2(vector<string> &v, int i) {
    // check if there is digit after digit (x x).
    return isdigit(v[i - 1][v[i - 1].size() - 1]) && isdigit(v[i][0]);
}


Commands::Commands(mapCommand *commandTable, symbolTable *varTable, ShuntingYard *shuntingYard) {
    Commands::commandTable = commandTable;
    Commands::varTable = varTable;
    Commands::shuntingYard = shuntingYard;
}

/*
 * Remove whitespaces.
 */
vector<string> Commands::cleanSpace(string str) {
    istringstream iss(str);
    vector<std::string> result(istream_iterator<std::string>{iss},
                               istream_iterator<std::string>());
    return result;
}

/*
 * This func takes the string and creates two expressions from him
 * with shunting yard algorithm help.
 */
vector<string> Commands::getParameters(string &str) {
    string parameter1, parameter2;
    vector<string> result = cleanSpace(str);
    vector<string> params;

    for (int i = 1; i < result.size(); i++) {
        if (legalExpression1(result[i][0]) || legalExpression2(result, i)) {
            params.push_back(shuntingYard->fromVectorToString(result , 1 , i ));
            params.push_back(shuntingYard->fromVectorToString(result , i,(unsigned)result.size()));
            break;
        }
    }
    return params;
}

/*
 * calculate the expression and return them inside vector.
 */
vector<string> Commands::getAssinParam(string str){
    string parameter1, parameter2;
    vector<string> result = cleanSpace(str);
    vector<string> params;
    params.push_back(shuntingYard->fromVectorToString(result , 0 , 1 ));
    params.push_back(shuntingYard->fromVectorToString(result , 2,(unsigned)result.size()));
    return params;
}
