//
// Created by Aspen on 11/21/2019.
//

#include "GuessMyNumber.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void GuessMyNumber::startGame() {
    displayInstructions();
    getNumber();
    getMove();  // getMove recursively checks for answers
    playAgain();
}

GuessMyNumber::GuessMyNumber()
{
    // C++ does not have a way of determining the difference between NULL and 0. Some other languages do.
    // Additionally, many compilers will throw warnings if NULL is assigned.
    // We will initialize to 0 to keep the program happy.
    number = 0;
    player_guess = 0;
    attempts = 0;
    valid = false;
    select = ' ';
}

void GuessMyNumber::displayInstructions()
{
    cout << "Welcome to Mallery's Guess My Number Game V1.0" << "\n"
         << "Please guess a number between 0 and 99 " << "\n"
         << "You will have unlimited attempts if guessed incorrectly" << endl;
}

int GuessMyNumber::getRand(){
    int _num = 0;

    // Seed the generator
    srand(static_cast<int>( time(nullptr)));

    _num = (rand() % 99);

    return _num;
}

void GuessMyNumber::getNumber() {
    do
    {
        number = getRand();
    }while(number > 100);  // number declared unsigned, negative values will not occur.
}

void GuessMyNumber::getMove() {

    // always set false upon recursive call
    valid = false;

    do
    {
        // Keep checking input while not an unsigned type.
        while(!(cin >> player_guess))
        {
            cout << "That is not a valid choice" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // When given a valid unsigned, check it's value to ensure it is between 0 and 99.
        if (player_guess < 0 || player_guess > 99)
            cout << "Please guess a number between 0 and 99" << endl;
        else
            // otherwise, flag as valid and break the loop.
            valid = true;

    }while(!(valid));

    checkMove();
}

void GuessMyNumber::checkMove(){

    if (player_guess == number)
        cout << "You won! " << "answer: " << number << "\n"
             << "Number of attempts: " << attempts << endl;
    else
        attempts += 1;

        if (player_guess > number)
            cout << "Too high" << endl;
        if (player_guess < number)
            cout << "Too low" << endl;

        cout << "Number of attempts: " << attempts << endl;

        getMove();
}

void GuessMyNumber::playAgain() {
    cout << "Would you like to play again?" << endl;

    cin >> select;

    if (select == 'y')
        startGame();

    // always clear the input buffer after the input a char, in the event of buffer overflow.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}