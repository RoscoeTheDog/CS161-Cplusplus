#include <iostream>
#include "Games/RockPaperScissors.h"
#include "Games/GuessMyNumber.h"

using namespace std;

class GameHub
{
private:
    bool play_again = false;
    bool* pplay_again = &play_again;
public:
    void selectGame()
    {
        unsigned sel;

        cout << "Welcome to Mallery's game hub v1.0" << "\n"
             << "Please select a game to play: " << "\n"
             << "1) Rock Paper Scissors (V1.1)" << "\n"
             << "2) Guess My Number (V1.0)" << endl;

        while (!(cin >> sel) || (sel > 2))
        {
            cout << "That is not a valid selection" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (sel)
        {
            case 1:
            {
                do
                {
                    RockPaperScissors Game(play_again);
                    Game.startNewGame();
                }while(play_again);

                break;
            }

            case 2:
            {
                do
                {
                    GuessMyNumber Game;
                    Game.startGame();
                }while(play_again);

                break;
            }

        }
    }
};

int main()
{
    //TODO: Allow the user to exit the game back to main menu. From main menu, allow user to exit program completely (with Third option).
    GameHub App;
    App.selectGame();

//    /// Initialize our class instance and start a new game.
//    RockPaperScissors App;
//    App.startNewGame();
//
//    GuessMyNumber App2;
//    App2.startGame();

    return 0;
}