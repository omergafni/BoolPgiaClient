/*
 * BPClient.h
 *
 *  Created on: Sep 7, 2017
 *      Author: user
 */

#ifndef BPCLIENT_H_
#define BPCLIENT_H_
#include "TCPClient.h"
#include "UDPSocket.h"
#include "ServerMessageHandler.h"
#include "GameMessageHandler.h"
#include "UDPRecvThread.h"
#include "BPGame.h"

using namespace std;
using namespace networkingLab;
class GameMessageHandler;
class BPClient : public TCPClient {

private:
    bool talkingOnUdp;
	bool isRunning;
	UDPSocket* toOpponent;
	UDPRecvThread* udpRecvThread;
	GameMessageHandler* gameMsgHandler;
	int udpListeningPort;

public:
	BPClient(int tcpListeningPort, int udpListeningPort);
	virtual ~BPClient();
    UDPSocket* getUdpSocket(){return toOpponent;};
	void sendToOpponent(string message);
	void startMatchWith(string ip, int port);
	void closeMatch();
    void sendMessage(string message);
	void won();
	void lost();
	void gameDisconnected();
	int getUdpPort();
	void exit();
	void stop();
	bool clientRunning();
};

#endif /* BPCLIENT_H_ */
