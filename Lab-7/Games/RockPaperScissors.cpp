#include "RockPaperScissors.h"
#include <string>
#include <iostream>

using namespace std;

void RockPaperScissors::startNewGame(){
    displayInstructions();
    getMove();
    setPlayerAnswer();
    setOpponentAnswer();
    getWinner();
}

RockPaperScissors::RockPaperScissors() {
    player_select = ' ';
    valid_choice = false;
    player_answer = " ";
    opponent_answer = " ";
    choice[0] = 'r';
    choice[1] = 'p';
    choice[2] = 's';
    repeat = false;
}

// If we can pass a pointer down, we can signal to the outside loop to re-instantiate the class and start a new game.
RockPaperScissors::RockPaperScissors(bool &play_again){
    player_select = ' ';
    valid_choice = false;
    player_answer = " ";
    opponent_answer = " ";
    choice[0] = 'r';
    choice[1] = 'p';
    choice[2] = 's';
    bool* prepeat = &play_again;
}

void RockPaperScissors::clearStdin(){
cout << "That is not a valid choice" << endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int RockPaperScissors::getRand(){
    int _num = 0;

    // Seed the generator
    srand(static_cast<int>( time(nullptr)));

    _num = (rand() % 9);

    return _num;
}


void RockPaperScissors::displayInstructions(){
    cout << "Welcome to Mallery's Rock, Paper, Scissors Game V1.1" << "\n"
         << "Please select from one of the following: " << "\n"
         << "Rock (r) Paper(p) Scissors(s)" << endl;
}

void RockPaperScissors::getMove(){
    do
    {
        // get input
        cin >> player_select;
        // force lowercase
        player_select = tolower(player_select);

        // iterate through our acceptable answers, enable flag if it's valid.
        for (char i : choice)
        {
            if (player_select == i)
                valid_choice = true;
        }

        if (!(valid_choice))
            // Clear the buffer
            clearStdin();

    }while(!(valid_choice));
}

void RockPaperScissors::setPlayerAnswer(){
    if (player_select == 'r')
        player_answer = "Rock";
    if (player_select == 'p')
        player_answer = "Paper";
    if (player_select == 's')
        player_answer = "Scissors";

    cout << "You choose: " << player_answer << endl;
}

void RockPaperScissors::setOpponentAnswer(){
    int _rand = 3;

    do
        _rand = getRand();
    while(_rand > 2);

    switch(_rand)
    {
        case 0: opponent_answer = "Rock"; break;
        case 1: opponent_answer = "Paper"; break;
        case 2: opponent_answer = "Scissors"; break;
    }
    cout << "Your opponent chooses: " << opponent_answer << endl;
}

void RockPaperScissors::getWinner(){
    char new_game = ' ';

    // TODO: This could be refactored to be more efficient. But I'm lazy and want to focus on other things :lol:
    if (player_select == 'r' && opponent_answer == "Rock")
        game_result = "Draw!";
    if (player_select == 'r' && opponent_answer == "Paper")
        game_result = "You lose";
    if (player_select == 'r' && opponent_answer == "Scissors")
        game_result = "You win!";

    if (player_select == 'p' && opponent_answer == "Rock")
        game_result = "You Win!";
    if (player_select == 'p' && opponent_answer == "Paper")
        game_result = "Draw!";
    if (player_select == 'p' && opponent_answer == "Scissors")
        game_result = "You lose";

    if (player_select == 's' && opponent_answer == "Rock")
        game_result = "You lose";
    if (player_select == 's' && opponent_answer == "Paper")
        game_result = "You win!";
    if (player_select == 's' && opponent_answer == "Scissors")
        game_result = "Draw!";

    cout << game_result << "\n"
         << "Play another round? (y/n)" << endl;

    cin >> new_game;
    if (tolower(new_game) == 'y')   //TODO: bug -- this condition is always true for some reason.

        // point to our outer restart flag (to indicate the loop of class type to continue)
        repeat = true;

        // OR

        // directly call constructor to reset member values.
        RockPaperScissors();
        // and call a new game.
        startNewGame();
}