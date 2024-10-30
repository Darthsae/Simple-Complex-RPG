/**
 * @file command_handler.h
 * @brief Defines the CommandHandler class for handling commands in the SimpleComplexRPG.
 */

#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H
/**
 * @namespace SimpleComplexRPG::Common
 * @brief Contains common structs and enums for the SimpleComplexRPG.
 */
namespace SimpleComplexRPG::Common {
    class CommandHandler;
}
#include "simple_complex_rpg/common/command.h"
#include <vector>
#include <string>

/**
 * @namespace SimpleComplexRPG::Common
 * @brief Contains common structs and enums for the SimpleComplexRPG.
 */
namespace SimpleComplexRPG::Common {
    /**
     * @class CommandHandler
     * @brief Manages the addition and execution of commands in the SimpleComplexRPG server.
     *
     * CommandHandler provides functionality to register commands and execute them by name,
     * handling associated parameters and executing the corresponding function.
     */
    class CommandHandler {
    public:
        std::vector<Command> commands; ///< A collection of available commands.

        /**
         * @brief Adds a new command to the CommandHandler.
         * @param command The command to add, including its name, description, parameters, and function.
         */
        void AddCommand(Command command);

        /**
         * @brief Executes a command based on its name and parameters.
         * @param initializer The name of the command to execute.
         * @param parameters The parameters to pass to the command's function.
         *
         * Searches for the command by name and, if found, executes the command's function
         * with the provided parameters.
         */
        void ExecuteCommand(std::string initializer, const std::vector<Parameter>& parameters);
    };
}
#endif