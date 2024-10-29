/**
 * @file server_config.h
 * @brief Defines the ServerConfig struct, which represents the configuration for the SimpleComplexRPG server.
 */

#ifndef SERVER_CONFIG_H
#define SERVER_CONFIG_H
#include <filesystem>
#include <string>

/**
 * @namespace SimpleComplexRPG::Server
 * @brief Contains all server-related networking structures and definitions for SimpleComplexRPG.
 */
namespace SimpleComplexRPG::Server {

    /**
     * @struct ServerConfig
     * @brief Represents the configuration settings for the SimpleComplexRPG server.
     *
     * The ServerConfig struct holds settings such as server name and the maximum number 
     * of clients allowed to connect. It provides methods to load, save, and reset configuration.
     */
    struct ServerConfig {
        std::string name; ///< Name of the server.
        uint64_t maxClients; ///< Maximum number of clients allowed on the server.

        /**
         * @brief Loads a server configuration from the specified file path.
         * @param path The filesystem path to the configuration file.
         * @return A ServerConfig object populated with settings from the file.
         */
        static ServerConfig Load(const std::filesystem::path& path);

        /**
         * @brief Loads a server configuration from a specified file path in string format.
         * @param path The string path to the configuration file.
         * @return A ServerConfig object populated with settings from the file.
         */
        static ServerConfig Load(const std::string& path);

        /**
         * @brief Saves the current server configuration to the specified file path.
         * @param path The filesystem path where the configuration file will be saved.
         */
        void Save(const std::filesystem::path& path);

        /**
         * @brief Saves the current server configuration to a specified file path in string format.
         * @param path The string path where the configuration file will be saved.
         */
        void Save(const std::string& path);

        /**
         * @brief Resets the server configuration to default settings.
         */
        void ToDefaults();
    };
}
#endif
