#include "Lexer.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <sstream>
using namespace std;

/*
 * This func reads the data from the file.
 */
vector<string> Lexer::lexerFromFile(string file){
    string sentence;
    vector<string> vectorCommands;
    ifstream myFile;
    myFile.open(file);
    if(myFile.is_open()){
        while(getline(myFile, sentence)) {
            if (!sentence.empty()) {
                vectorCommands.push_back(sentence);
            }
        }
    }

    myFile.close();
    return vectorCommands;

}

/*
 * This func reads the data from the user.
 */
vector<string> Lexer::lexerFromConsole(){
    string command;
    vector<string> vectorCommands;
    //TODO check what the end key.
    while(command != "exit"){
        getline(cin, command);
        istringstream iss(command);
        vectorCommands.push_back(command);
    }
    return vectorCommands;

}