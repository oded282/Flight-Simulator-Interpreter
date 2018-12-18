//
// Created by oded on 12/17/18.
//

#include "Lexer.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <sstream>
using namespace std;


//vector<string> lexerFromFile(string file){
//    string word;
//    vector<string> vectorCommands;
//    ifstream myFile;
//    myFile.open(file);
//    if(myFile.is_open()){
//        while(myFile >> word){
//            vectorCommands.push_back(word);
//        }
//    }
//    return vectorCommands;
//
//}
//
//vector<string> lexerFromConsole(){
//    string command;
//    vector<string> vectorCommands;
//    while(command != "print \"done\""){
//        getline(cin, command);
//        istringstream iss(command);
//        vector<std::string> results(istream_iterator<std::string>{iss},
//                                    istream_iterator<std::string>());
//        copy(results.begin(), results.end(), back_inserter(vectorCommands));
//    }
//    return vectorCommands;
//
//}
//

vector<string> Lexer::lexerFromFile(string file){
    string sentence;
    vector<string> vectorCommands;
    ifstream myFile;
    myFile.open(file);
    if(myFile.is_open()){
        while(getline(myFile, sentence)){
            vectorCommands.push_back(sentence);
        }
    }
    return vectorCommands;

}

vector<string> Lexer::lexerFromConsole(){
    string command;
    vector<string> vectorCommands;
    while(command != "print \"done\""){
        getline(cin, command);
        istringstream iss(command);
        vectorCommands.push_back(command);
    }
    return vectorCommands;

}