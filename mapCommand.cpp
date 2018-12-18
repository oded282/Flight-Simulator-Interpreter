//
// Created by oded on 12/18/18.
//

#include "mapCommand.h"

/*
 * This func add command to the map.
 */
void mapCommand::addCommand(string symbol,Commands command){
    commandMap[symbol] = command;
}

/*
 * This func return specific command if exist.
 */
Commands* mapCommand::getCommand(string symbol){
    map<string,Commands>:: iterator it;
    if(commandMap.find(symbol) != commandMap.end()){
        return &commandMap[symbol];
    }
    return nullptr;

}

/*
 * This func return's the all map.
 */
const map<string, Commands> &mapCommand::getCommandMap() const {
    return commandMap;
}
