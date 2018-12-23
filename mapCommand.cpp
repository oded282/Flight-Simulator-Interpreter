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
    map<string,Commands>:: iterator it;
    if(commandMap.find(symbol) != commandMap.end()){
        return commandMap[symbol];
    }
    return nullptr;

}

/*
 * This func return's the all map.
 */
map<string, commandExpression*> &mapCommand::getCommandMap() {
    return commandMap;
}
