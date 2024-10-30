#include "simple_complex_rpg/common/command_handler.h"

using namespace SimpleComplexRPG::Common;

void CommandHandler::AddCommand(Command command) {
    commands.push_back(command);
}

void CommandHandler::ExecuteCommand(std::string initializer, const std::vector<Parameter>& parameters) {
    for (Command command : commands) {
        if (command.name == initializer) {
            command.function(*this, parameters);
        }
    }
}