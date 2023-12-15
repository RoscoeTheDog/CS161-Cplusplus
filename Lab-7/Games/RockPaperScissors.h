#ifndef LAB_7_ROCKPAPERSCISSORS_H
#define LAB_7_ROCKPAPERSCISSORS_H

#include <cstdlib>
#include <time.h>
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

class RockPaperScissors
{
private:
    /// Declare class members (our Variables) to be used.
    char player_select;
    bool valid_choice;
    string player_answer;
    string opponent_answer;
    string game_result;
    char choice[3];
    bool repeat;

public:
    /// Constructor (ie. Function). Automatically assigns values upon startup.
    RockPaperScissors();

    /// Constructor Overload (ie. same Function but w/ passed args).
    RockPaperScissors(bool &play_again);

    /// Clear the input overflow (if any)
    void clearStdin();

    /// Random number generator, used to pick an answer for the opponent AI.
    int getRand();

    /// Start a new game. This just recursively calls things in the correct order. Keeps our main{} function a bit cleaner.
    void startNewGame();

    /// A simple prompt that displays the introduction.
    void displayInstructions();

    /// Get the User's move.
    void getMove();

    /// Translate User's char into string for prettier output of selected move.
    void setPlayerAnswer();

    /// Generate a random number & set the corresponding move for the opponent.
    void setOpponentAnswer();

    /// Determine the winner.
    void getWinner();
};

#endif //LAB_7_ROCKPAPERSCISSORS_H
