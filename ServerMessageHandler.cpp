//
// Created by user on 11/09/17.
//

#include "ServerMessageHandler.h"

bool ServerMessageHandler::isStartMessage(string message) {
    std::size_t found = message.find("start-match");
    return found != std::string::npos;
}

bool ServerMessageHandler::isAskForUdpPort(string message){
    std::size_t found = message.find("udp-port?");
    return found != std::string::npos;
    //return message == "udp-port?";
}

bool ServerMessageHandler::isCloseMessage(string message) {
    std::size_t found = message.find("close");
    return found != std::string::npos;
}

ServerMessageHandler::ServerMessageHandler(BPClient *client) {
    this->client = client;
}

void ServerMessageHandler::handleMessage(string message) {
    if (isStartMessage(message)){
        vector<string> opponentDetails = getOpponentDetailsFromMessage(message);
        // [1] - opponent IP, [2] - opponent port
        client->startMatchWith(opponentDetails[1], stoi(opponentDetails[2]));
    }
    else if(isAskForUdpPort(message)){
        string udpPort = to_string(client->getUdpPort());
        client->send(udpPort);
    }
    else if(isCloseMessage(message)){
        client->stop();
    }
    else
        cout << "[System message]:\n" + message << endl;
}

vector<string> ServerMessageHandler::getOpponentDetailsFromMessage(string message) {
    return split(message,':');
}

vector<string> ServerMessageHandler::split(string str, char delimiter){

    vector<string> internal;
    stringstream ss(str);
    string tok;

    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }

    return internal;
}

