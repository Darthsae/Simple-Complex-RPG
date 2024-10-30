#include "simple_complex_rpg/common/command.h"
#include <vector>
#include <sstream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <iostream>

using namespace SimpleComplexRPG::Common;

Command::Command(std::string name, std::string description) {
    this->name = name;
    this->description = description;
}

Command::Command(std::string name, std::function<void(const CommandHandler& commandHandler, std::vector<Parameter>)> function) {
    this->name = name;
    this->function = function;
}

Command::Command(std::string name, std::string description, std::function<void(const CommandHandler& commandHandler, std::vector<Parameter>)> function) {
    this->name = name;
    this->description = description;
    this->function = function;
}

void Command::AddParameter(ParameterType param) {
    parameters.push_back(param);
}

void Command::Tokenize(std::istringstream& stream, std::vector<Parameter>& parameters) {
    bool inQuotes = false;
    bool hasBeenString = false;

    std::string currentParam = "";

    // Loop over each character in the stream
    while (stream.good()) {
        char c = stream.get();
        if (!isprint(c) && c != ' ' && c != '"') {
            std::cout << "Non-printable character: " << c << std::endl;
            continue;
        }
        if (c == '"') {
            hasBeenString = true;
            inQuotes = !inQuotes;
            continue;
        }
        if (c == ' ' && !inQuotes && currentParam != "") {
            if (currentParam != "") {
                // Add the parameter to the result, make sure to parse the correct type
                if (hasBeenString) {
                    parameters.push_back(Parameter(currentParam));
                    std::cout << "Pushed string: " << currentParam << std::endl;
                    hasBeenString = false;
                } else if (currentParam == "true" || currentParam == "false") {
                    parameters.push_back(Parameter(currentParam == "true"));
                    std::cout << "Pushed bool: " << currentParam << std::endl;
                } else {
                    try {
                        if (currentParam.find('.') != std::string::npos) {
                            parameters.push_back(Parameter(std::stod(currentParam)));
                            std::cout << "Pushed double: " << currentParam << std::endl;
                        } else {
                            parameters.push_back(Parameter(std::stoi(currentParam)));
                            std::cout << "Pushed int: " << currentParam << std::endl;
                        }
                    } catch (const std::invalid_argument&) {
                        parameters.push_back(Parameter(currentParam));  // Fallback to string, even if quotes weren't triggered
                        hasBeenString = false;
                        std::cout << "Pushed string: " << currentParam << std::endl;
                    }
                }
                //parameters.push_back(Parameter(currentParam));
                currentParam = "";
            }
            continue;
        }
        currentParam += c;
    }

    // Push the last parameter if any
    if (!currentParam.empty()) {
        if (hasBeenString) {
            parameters.push_back(Parameter(currentParam));
        } else if (currentParam == "true" || currentParam == "false") {
            parameters.push_back(Parameter(currentParam == "true"));
        } else {
            try {
                if (currentParam.find('.') != std::string::npos) {
                    parameters.push_back(Parameter(std::stod(currentParam)));
                } else {
                    parameters.push_back(Parameter(std::stoi(currentParam)));
                }
            } catch (const std::invalid_argument&) {
                parameters.push_back(Parameter(currentParam));
            }
        }
    }
}