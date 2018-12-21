#ifndef FLIGHT_SIMULATOR_PARSER_H
#define FLIGHT_SIMULATOR_PARSER_H

#include <vector>
#include <string>

using namespace std;

class Parser
{
    vector<string> parser;
    int index;

public:
    Parser(){};

    Parser(const vector<string> &parser, int index);

    const vector<string> &getParser() const;

    int getIndex() const;

    void setParser(const vector<string> &parser);

    void setIndex(int index);
};



#endif //FLIGHT_SIMULATOR_PARSER_H
