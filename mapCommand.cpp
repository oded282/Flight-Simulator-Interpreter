#include "mapCommand.h"
#include "Commands.h"


/*
 * This func add command to the map.
 */
void mapCommand::addCommand(string symbol,commandExpression* command){
    commandMap[symbol] = command;
}

/*
 * This func return specific command if exist.
 */
commandExpression* mapCommand::getCommandExpression(string symbol){
    if(commandMap.find(symbol) != commandMap.end()){
        return commandMap.find(symbol)->second;
    }
    commandMap.erase(symbol);
    return nullptr;
}

/*
 * This func return's the all map.
 */
map<string, commandExpression*> &mapCommand::getCommandMap() {
    return commandMap;
}
