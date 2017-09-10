//
// Created by user on 11/09/17.
//

#ifndef BOOLPGIA_GAMEMESSAGEHANDLER_H
#define BOOLPGIA_GAMEMESSAGEHANDLER_H


#include <string>
#include "BPClient.h"
#include "MessageHandler.h"
#include <vector>
#include <sstream>
#include "BPGame.h"

using namespace std;
using namespace networkingLab;

class BPClient;
class GameMessageHandler : public MessageHandler {

protected:
    BPClient* client;
    BPGame* game;
public:
    GameMessageHandler(BPClient* client);
    void handleMessage(string message);
    ~GameMessageHandler(){};

    bool isDisconnectMessage(string message);
    bool youWinMessage(string message);
    bool youLost(string message);

    bool resultMessage(string message);

    bool errorMessage(string message);

    bool exitMessage(string message);
};



#endif //BOOLPGIA_GAMEMESSAGEHANDLER_H
