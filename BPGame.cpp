#include <string.h>
#include "BPGame.h"

BPGame::BPGame(UDPSocket *opponent) {
    this->opponent = opponent;
    opponentWon = false;
    iWon = false;
}

int BPGame::checkBool(int randomNum[], const char guessInput[]) {

    int counter = 0;

    for(int i = 0; i < GUESS_LENGTH; i++) {
        if((int)guessInput[i] - 48 == randomNum[i])
            counter++;
    };
    return counter;
}

int BPGame::checkPgia(int randomNum[], const char guessInput[]) {

    int counter = 0;
    for(int i = 0; i < GUESS_LENGTH; i++) {
        for(int j = 0; j < GUESS_LENGTH; j++) {
            if((int)guessInput[i] - 48 == randomNum[j]) {
                counter++;
                break;
            };
        };
    };
    return counter;
}

int* BPGame::generateRandomNumber() {
    srand(time(NULL));
    int r = rand();
    string s;
    for(int i = 0; i < GUESS_LENGTH; i++) {
        secret[i] = r%10;
        s += to_string(secret[i]);
        r = r/10;
    };
    cout << "Your secret number is: " << s << endl;
    return secret;
}

bool BPGame::isValidGuess(const string &guess){
    if(guess.length() != GUESS_LENGTH){
        return false;
    }
//    opponent->write(guess.c_str(),guess.length());
    return true;
}

string BPGame::checkGuess(string guess) {

    if(!isValidGuess(guess))
        return "Error: guess must be " +  to_string(GUESS_LENGTH) + " digits!";

    const char* g = guess.c_str();
    int numOfBool = checkBool(secret,g);
    int numOfPgia = checkPgia(secret,g);

    if(numOfBool == GUESS_LENGTH){
        opponentWon = true;
        return "win";
    }

    string result = "Bool: " + to_string(numOfBool) + " | " +
                    "Pgia: " + to_string(numOfPgia);
    return result;
}



bool BPGame::isRunning(){
    return (!iWon && !opponentWon);
}


