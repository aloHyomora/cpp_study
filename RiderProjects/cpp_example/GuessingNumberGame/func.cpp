#include "NumberGame.h"
#include <cstdlib>
#include <ctime>

// Constructor to initialize game with a random number
NumberGame::NumberGame()
{
    // Seed the random number generator
    // 랜덤 숫자 생성기 초기화
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random number between 1 and 100
    numberToGuess = rand() % 100 + 1;
    numberOfAttempts = 0;
}
NumberGame::~NumberGame()
{
    
}
void NumberGame::playGame()
{
    int guessNum;
    cout << "Guess a number between 1 and 100 " <<endl;

    do
    {
        cin >> guessNum;
        numberOfAttempts++;
    }
    while (!isCorrectGuessing(guessNum));

    cout << "Correct! You guessed the number in " << numberOfAttempts << " attempts. " <<endl;
}
bool NumberGame::isCorrectGuessing(int guessNum)
{
    if (guessNum == numberToGuess) return true;
    else
    {
        cout << "Wrong Guess. ";
        if (guessNum > numberToGuess)
            cout << "lower!";
        else if (guessNum < numberToGuess)
            cout << "higher!";
        return false;
    }
}

