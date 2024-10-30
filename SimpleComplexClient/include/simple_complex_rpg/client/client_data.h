#ifndef CLIENT_DATA_H
#define CLIENT_DATA_H
#include <string>

namespace SimpleComplexRPG::Client {
    enum UIState {
        MAIN_MENU,
        GAME,
        TEMP,
    };

    struct ClientData {
        ClientData();

        bool debugMenu = true;
        bool quit = false;

        UIState currentUIState;

        std::string dataDirectory;
        std::string textureDataDirectory;
        std::string saveDirectory;
    };
}

#endif