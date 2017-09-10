#include "BPClient.h"

BPClient::BPClient(int tcpListeningPort, int udpListeningPort) : TCPClient(tcpListeningPort) {
    talkingOnUdp = false;
    isRunning = true;
	toOpponent = NULL;
	udpRecvThread = NULL;
    this->udpListeningPort = udpListeningPort;
}

void BPClient::startMatchWith(string ip, int port) {

    cout << "[System:]\n Starting match with ["  + ip + ":" + to_string(port) +"]"<< endl;

	toOpponent = new UDPSocket(udpListeningPort);
	toOpponent->connect(ip,port);
    talkingOnUdp=true;
    gameMsgHandler = new GameMessageHandler(this);

	udpRecvThread = new UDPRecvThread(toOpponent, gameMsgHandler);
    udpRecvThread->start();

}

void BPClient::won(){
    cout << "You won!" << endl;
    // winner notifies the server
    sendToOpponent("lost");
    closeMatch();
    send("win");
}

void BPClient::lost(){
    cout << "Sorry, you lost" << endl;
    closeMatch();
}

void BPClient::gameDisconnected(){}

void BPClient::closeMatch() {
    udpRecvThread->stop();
    talkingOnUdp = false;
    delete toOpponent;
    delete udpRecvThread;
}

void BPClient::sendToOpponent(string message) {
    toOpponent->write(message.c_str(), message.size());
}

void BPClient::sendMessage(string message) {
    if(talkingOnUdp)
        sendToOpponent(message);
    else send(message);

}

BPClient::~BPClient() {
    exit();
}

int BPClient::getUdpPort(){
    return udpListeningPort;
}

void BPClient::exit() {
    send("exit");
    if(gameMsgHandler!=NULL)
        delete gameMsgHandler;

}

void BPClient::stop(){
    isRunning = false;
    tcpRecvThread->stop();
}

bool BPClient::clientRunning(){return isRunning;}






