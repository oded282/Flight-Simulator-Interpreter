#include "Parser.h"

Parser::Parser(const vector<string> &parser, int index) {

    Parser::vectorInfo = parser;
    Parser::index = index;

}

const vector<string> &Parser::getParser() const {
    return vectorInfo;
}

int Parser::getIndex() const {
    return index;
}

void Parser::setParser(const vector<string> &parser) {
    Parser::vectorInfo = parser;
}



void Parser::doParser() {









}