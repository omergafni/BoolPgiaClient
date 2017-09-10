#ifndef BOOLPGIACLIENT_BPGAME_H
#define BOOLPGIACLIENT_BPGAME_H

#include <UDPSocket.h>

#define GUESS_LENGTH 4

using namespace networkingLab;

class BPGame {

private:
    UDPSocket* opponent;
    int secret[GUESS_LENGTH];
    int checkBool(int randomNum[], const char guessInput[]);
    int checkPgia(int randomNum[], const char guessInput[]);

public:
    bool opponentWon;
    bool iWon;
    BPGame(UDPSocket* opponent);
    int* generateRandomNumber();
    bool isValidGuess(const string &guess);
    string checkGuess(string guess);
    void notifyOpponentWon();
    string getSecretNumber();

    bool isRunning();
};


#endif //BOOLPGIACLIENT_BPGAME_H
