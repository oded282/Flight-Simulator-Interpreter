#include "Parser.h"

Parser::Parser(const vector<string> &parser, int index) {

    Parser::parser = parser;
    Parser::index = index;

}

const vector<string> &Parser::getParser() const {
    return parser;
}

int Parser::getIndex() const {
    return index;
}

void Parser::setParser(const vector<string> &parser) {
    Parser::parser = parser;
}



void Parser::doParser() {









}