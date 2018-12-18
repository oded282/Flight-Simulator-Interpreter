//
// Created by oded on 12/17/18.
//

#ifndef FLIGHT_SIMULATOR_LEXER_H
#define FLIGHT_SIMULATOR_LEXER_H
#include <string>
#include <vector>

using namespace std;

class Lexer {


public:
    vector<string> lexerFromConsole();
    vector<string> lexerFromFile(string file);
};


#endif //FLIGHT_SIMULATOR_LEXER_H
