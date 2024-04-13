#ifndef GUESSINGGAME
#define GUESSINGGAME

#include <iostream>
using namespace std;
// Guessing game class definition
class NumberGame
{
private:
    int numberToGuess;
    int numberOfAttempts;
public:
    NumberGame();
    ~NumberGame();
    void playGame();
    bool isCorrectGuessing(int guessNum);
};

#endif


