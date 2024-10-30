#include "simple_complex_rpg/client/client_data.h"
#include <filesystem>
#include <sago/platform_folders.h>

using namespace SimpleComplexRPG::Client;

ClientData::ClientData() {
    currentUIState = UIState::MAIN_MENU;

    #pragma region Directories
    dataDirectory = sago::getDataHome() + "/SimpleComplexRPG/";
    textureDataDirectory = dataDirectory + "Textures/";
    saveDirectory = sago::getSaveGamesFolder1() + "/SimpleComplexRPG/";

    if (!std::filesystem::exists(dataDirectory)) {
        std::filesystem::create_directories(dataDirectory);
    }

    if (!std::filesystem::exists(textureDataDirectory)) {
        std::filesystem::create_directories(textureDataDirectory);
    }

    if (!std::filesystem::exists(saveDirectory)) {
        std::filesystem::create_directories(saveDirectory);
    }
    #pragma endregion
}