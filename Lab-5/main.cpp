#include <iostream>
#include <limits>

using namespace std;

int player = 1;
int num_sticks = 11;

int get_player_answer()
{
    int player_answer;

    cout << "Player " << player << ", please select a number of sticks between 1 and 3" << endl;
    cin >> player_answer;

    while(cin.fail())
    {
        cout << "Please enter your answer as an Integer number" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (player_answer > num_sticks)
    {
        cout << "That is not a valid answer. Your answer must be less or equal to the number of sticks remaining." << endl;
        get_player_answer();
    }
    else if (!((0 < player_answer) && (player_answer <= 3)))
        get_player_answer();
    else if ( (0 < player_answer) && (player_answer <= 3) )
    {
        cout << endl;
        return player_answer;
    }
}

void draw_board()
{
    for ( int i=0; i<num_sticks; i++)
        cout << "|";

    cout << endl;
}

int main() {

    // initialization
    // define variables
    // set number of sticks
    // see if computer or two people
    bool playing = true;

    cout << "Welcome to Nim!" << "\n"
         << "Players will take turns removing 1, 2, or 3 sticks from the initial 11. " << "\n"
         << "The player removing the last stick wins!" << "\n" << endl;

    while ( playing )
    {
        // 1 -- display board
        // should use for loop
        draw_board();

        // 2 -- get and validate input
        // integer between 1 and 3
        // not greater than num_sticks sticks
        int player_answer = get_player_answer();

        // 3 -- update board
        // subtract move from number of sticks num_sticks
        num_sticks -= player_answer;

        // 4 -- see if done
        // if number of sticks is zero, set playing to false
        if (num_sticks == 0)
        {
            playing = false;
        }

        // 5 -- if not done, alternate player
        // if player 1, go to player 2
        // if player 2, go to player 1
        if (player == 1)
            player = 2;
        else
            player = 1;
    }

    // announce winner using player number
    cout << "Congratulations, Player " << player << ". You win!" << endl;

    // exit.
    return 0;
}
