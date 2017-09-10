#include "GameMessageHandler.h"

GameMessageHandler::GameMessageHandler(BPClient *client) {
    this->client = client;
    // Initialize game
    game = new BPGame(client->getUdpSocket());
    game->generateRandomNumber();
}

void GameMessageHandler::handleMessage(string message) {

    if (youWinMessage(message))
        client->won();
    else if (youLost(message))
        client->lost();
    else if (exitMessage(message)) {
        client->closeMatch();

    } else if (!resultMessage(message) && !errorMessage(message)) {
        string result = game->checkGuess(message);
        client->sendMessage(result);
        cout << "Enter your guess: " << endl;

    } else
        cout << message << endl;

}

bool GameMessageHandler::youWinMessage(string message) {
    std::size_t found = message.find("win");
    return found != std::string::npos;
}

bool GameMessageHandler::youLost(string message) {
    std::size_t found = message.find("lost");
    return found != std::string::npos;
}

bool GameMessageHandler::isDisconnectMessage(string message) {
    std::size_t found = message.find("disconnect");
    return found != std::string::npos;
}

bool GameMessageHandler::resultMessage(string message) {
    std::size_t found = message.find("Bool");
    return found != std::string::npos;
}

bool GameMessageHandler::errorMessage(string message) {
    std::size_t found = message.find("Error");
    return found != std::string::npos;
}

bool GameMessageHandler::exitMessage(string message) {
    std::size_t found = message.find("exit");
    return found != std::string::npos;
}

