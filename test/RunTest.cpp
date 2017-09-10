//
// Created by root on 9/10/17.
//

#include "RunTest.h"
#include "../BPClient.h"

void RunTest::start() {

    BPClient* client1 = new BPClient(4444,3333);
    BPClient* client2 = new BPClient(5555,6666);
    TCPRecvThread* rt1 = new TCPRecvThread(client1->getTcpSocket(),new ServerMessageHandler(client1));
    TCPRecvThread* rt2 = new TCPRecvThread(client2->getTcpSocket(),new ServerMessageHandler(client2));
    client1->setTCPRecvThread(rt1);
    client2->setTCPRecvThread(rt2);

    client1->startMatchWith("127.0.0.1",6666); sleep(1);
    client2->startMatchWith("127.0.0.1",3333); sleep(1);

    client1->sendMessage("1111"); sleep(1);
    client2->sendMessage("2222"); sleep(1);

    client1->sendMessage("win"); sleep(2);

    delete client1, client2, rt1, rt2;

}
