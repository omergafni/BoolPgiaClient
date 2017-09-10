#include <iostream>
#include "BPClient.h"
#include "GameProtocol.h"
#include "test/RunTest.h"

using namespace std;

int main(int argc, char ** argv) {

    if(argc==2){
        string flag = argv[1];
        if(flag == "-test"){
            RunTest test;
            test.start();
            return 0;
        }
    }

    int udpListeningPort = DEFAULT_UDP_LISTENING_PORT;
    int tcpListeningPort = DEFAULT_TCP_LISTENING_PORT;

    if(argc==3){
        tcpListeningPort=stoi(argv[1]);
        udpListeningPort=stoi(argv[2]);
    }

    BPClient* client = new BPClient(tcpListeningPort,udpListeningPort);
    ServerMessageHandler* clientServerMsgHandler = new ServerMessageHandler(client);
    TCPRecvThread* clientTcpRecvThread = new TCPRecvThread(client->getTcpSocket(),clientServerMsgHandler);
    client->setTCPRecvThread(clientTcpRecvThread);

    cout << "Trying to connect to server..." << endl;
    client->open(SERVER_IP,SERVER_PORT);

    string userInput;

    while(userInput!= "exit" && client->clientRunning()){
        getline(cin,userInput);
        client->sendMessage(userInput);
    }

    cout << "Closing client" << endl;

    return 0;
}