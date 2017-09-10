//
// Created by user on 11/09/17.
//

#ifndef BOOLPGIA_GAMESMESSAGEHANDLER_H
#define BOOLPGIA_GAMESMESSAGEHANDLER_H

#include <string>
#include "BPClient.h"
#include "MessageHandler.h"
#include <vector>
#include <sstream>

using namespace std;
using namespace networkingLab;

class BPClient;
class ServerMessageHandler : public MessageHandler {

protected:
    BPClient* client;
    bool isStartMessage(string message);
    bool isAskForUdpPort(string message);

public:
    ServerMessageHandler(BPClient* client);
    void handleMessage(string message);
    ~ServerMessageHandler(){};

    vector<string> getOpponentDetailsFromMessage(string message);

    vector<string> split(string str, char delimiter);

    bool isCloseMessage(string message);
};


#endif //BOOLPGIA_GAMESMESSAGEHANDLER_H
