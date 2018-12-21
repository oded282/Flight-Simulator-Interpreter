#include "mapCommand.h"
#include "Commands.h"


/*
 * This func add command to the map.
 */
void mapCommand::addCommand(string symbol,Commands* command){
    commandMap[symbol] = command;
}

/*
 * This func return specific command if exist.
 */
Commands* mapCommand::getCommand(string symbol){
    map<string,Commands>:: iterator it;
    if(commandMap.find(symbol) != commandMap.end()){
        return commandMap[symbol];
    }
    return nullptr;

}

/*
 * This func return's the all map.
 */
map<string, Commands*> &mapCommand::getCommandMap() {
    return commandMap;
}
