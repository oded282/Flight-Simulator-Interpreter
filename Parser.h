#ifndef FLIGHT_SIMULATOR_PARSER_H
#define FLIGHT_SIMULATOR_PARSER_H

#include <vector>
#include <string>
#include "mapCommand.h"

using namespace std;

class Parser
{
    vector<string> vectorInfo;
    double index;
    mapCommand * commandmap;

public:
    Parser(){
        index = 0;
    };

    Parser(const vector<string> &vectorInfo, mapCommand*);

    const vector<string> &getVector() const;

    double getIndex() const;

    void setParser(const vector<string> &vector);

    void setIndex(int index);

    void setMap(mapCommand*);

    vector<commandExpression*> doParser(int);
};



#endif //FLIGHT_SIMULATOR_PARSER_H
