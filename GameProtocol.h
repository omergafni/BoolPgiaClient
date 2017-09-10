/*
 * TCPMessengerProtocol.h
 *
 *  Created on: Feb 13, 2013
 *      Author: efi
 */

#ifndef GAMEPROTOCOL_H_
#define GAMEPROTOCOL_H_

/**
 * TCP Messenger protocol:
 * all messages are of the format [Command 4 byte int]
 * and optionally data follows in the format [Data length 4 byte int][ Data ]
 */
#define SERVER_PORT 3346
#define SERVER_IP "127.0.0.1"
#define DEFAULT_UDP_LISTENING_PORT 6666
#define DEFAULT_TCP_LISTENING_PORT 4444


#endif /* GAMEPROTOCOL_H_ */
