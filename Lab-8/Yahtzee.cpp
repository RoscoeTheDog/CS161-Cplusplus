/*******************************
 *
 * Yahtzee
 *
 * Starter code by Paul Wilkins
 * Last Modified: 11/18/2013
 *
 *******************************/


//
// Modified in collaboration by Aspen on 11/22/2019.
//

#include <algorithm>
#include "Yahtzee.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Default Constructor
Yahtzee::Yahtzee()
{
    // Initialize values to -1 upon startup.
    onesScore = twosScore = threesScore = foursScore = fivesScore = sixesScore = EMPTY;
    threeOfAKind = fourOfAKind = fullHouse = smallStraight = largeStraight = yahtzee = chance = EMPTY;

    // Welcome the players.
    cout << "Welcome to Yahtzee!" << endl;

    // Seed the random num generator
    srand(time(nullptr));

    // Iterate the game through the amount of allocated turns (12 times)
    for (int turn = 0; turn < NUM_CATEGORIES; turn++)
    {
        int round = 1;

        // Initialize our dice to 0.
        ones = twos = threes = fours = fives = sixes = 0;

        // Get a random number for each die.
        die1 = rand() % SIDES + 1;
        die2 = rand() % SIDES + 1;
        die3 = rand() % SIDES + 1;
        die4 = rand() % SIDES + 1;
        die5 = rand() % SIDES + 1;

        // Roll and print results for the user.
        printRoll();

        // Reroll the dice, if desired.
        do
        {
            redo1 = askReroll(1);
            redo2 = askReroll(2);
            redo3 = askReroll(3);
            redo4 = askReroll(4);
            redo5 = askReroll(5);

            if (redo1)
                die1 = rand() % SIDES + 1;
            if (redo2)
                die2 = rand() % SIDES + 1;
            if (redo3)
                die3 = rand() % SIDES + 1;
            if (redo4)
                die4 = rand() % SIDES + 1;
            if (redo5)
                die5 = rand() % SIDES + 1;

            printRoll();
            round++;
        } while ((redo1 || redo2 || redo3 || redo4 || redo5) && round < 3);

        ones = tabulateDice(1, die1, die2, die3, die4, die5);
        twos = tabulateDice(2, die1, die2, die3, die4, die5);
        threes = tabulateDice(3, die1, die2, die3, die4, die5);
        fours = tabulateDice(4, die1, die2, die3, die4, die5);
        fives = tabulateDice(5, die1, die2, die3, die4, die5);
        sixes = tabulateDice(6, die1, die2, die3, die4, die5);

        do
        {
            INVALID_CATAGORY = false;
            int scoreOption = getScoreOption();

            switch (scoreOption)
            {
                case ONES:
                    onesScore = scoreOnes();
                    break;
                case TWOS:
                    twosScore = scoreTwos();
                    break;
                case THREES:
                    threesScore = scoreThrees();
                    break;
                case FOURS:
                    foursScore = scoreFours();
                    break;
                case FIVES:
                    fivesScore = scoreFives();
                    break;
                case SIXES:
                    sixesScore = scoreSixes();
                    break;
                case THREE_OF_A_KIND:
                    threeOfAKind = scoreThreeOfAKind();
                    break;
                case FOUR_OF_A_KIND:
                    fourOfAKind = scoreFourOfAKind();
                    break;
                case FULL_HOUSE:
                    fullHouse = scoreFullHouse();
                    break;
                case SMALL_STRAIGHT:
                    smallStraight = scoreSmallStraight();
                    break;
                case LARGE_STRAIGHT:
                    largeStraight = scoreLargeStraight();
                    break;
                case YAHTZEE:
                    yahtzee = scoreYahtzee();
                    break;
                case CHANCE:
                    chance = scoreChance();
                    break;
            }

            // Warn the user they will receive score of 0 if category is used.
            // Allow them the option to deny or accept and continue to next turn.
            if (INVALID_CATAGORY)
                overrideCategory();

        } while (INVALID_CATAGORY);

        printScore();
    }
}

void Yahtzee::overrideCategory()
{
    char sel = ' ';

    cout << "You do not have the proper roll to receive a score." << "\n"
         << "Would you like to use this catagory anyway? (y/n)" << endl;

    cin >> sel;

    if (sel == 'y')
        INVALID_CATAGORY = false;
    else if (sel == 'n')
        INVALID_CATAGORY = true;
    else
        cout << "Please select (y/n)" << endl;
}

/*********************************************************
 *
 * printRoll
 * ------------------
 * This function prints out the current state of the dice,
 * with blank lines before and after the print-out.
 *
 *********************************************************/
void Yahtzee::printRoll()
{
    cout << endl;
    cout << "Your roll is:" << endl;
    cout << die1 << " " << die2 << " " << die3 << " " << die4 << " " << die5 << endl;
    cout << endl;
}

/*********************************************************
 *
 * askReroll
 * ------------------
 * This function ask the user if they'd like to reroll one
 * one of the dice.  The function takes an integer which is
 * the number of the die being rerolled, and returns true if
 * the die should be rerolled, false otherwise.  The integer
 * argument is used only for instruction display, this function
 * does not actually reroll any dice.  Responses accepted are
 * 'Y', 'N', 'y', and 'n'.
 *
 *********************************************************/
bool Yahtzee::askReroll(int n)
{
    char ch;
    while (true)
    {
        cout << "Would you like to reroll die " << n << "? (Y/N) ";
        cin >> ch;
        switch (ch)
        {
            case 'Y':
            case 'y':
                return true;
            case 'N':
            case 'n':
                return false;
            default:
                cout << "Invalid response" << endl;
        }
    }

}

/********************************
 *
 * printScore
 * --------------------
 * This function prints out the complete score table
 * for the yahtzee game in its current state.
 *
 ********************************/
void Yahtzee::printScore()
{
    printSeparator();
    printScoreLine("Ones", onesScore);
    printSeparator();
    printScoreLine("Twos", twosScore);
    printSeparator();
    printScoreLine("Threes", threesScore);
    printSeparator();
    printScoreLine("Fours", foursScore);
    printSeparator();
    printScoreLine("Fives", fivesScore);
    printSeparator();
    printScoreLine("Sixes", sixesScore);
    printSeparator();
    printScoreLine("Three of a kind", threeOfAKind);
    printSeparator();
    printScoreLine("Four of a kind", fourOfAKind);
    printSeparator();
    printScoreLine("Full House", fullHouse);
    printSeparator();
    printScoreLine("Small Straight", smallStraight);
    printSeparator();
    printScoreLine("Large Straight", largeStraight);
    printSeparator();
    printScoreLine("Yahtzee", yahtzee);
    printSeparator();
    printScoreLine("Chance", chance);
    printSeparator();
}

/********************************
 *
 * printSeperator
 * --------------------
 * This helper function prints out a single
 * separator line used as part of the score
 * printing function.
 *
 ********************************/
void Yahtzee::printSeparator()
{
    cout << "+-------------------+-------+" << endl;
}

/********************************
 *
 * printScoreLine
 * --------------------
 * This function prints out a single line of the score.
 * The string argument is the name of the category, while
 * the in is the value of the score.  The category name is left
 * aligned, while the score value is right aligned.
 *
 ********************************/
void Yahtzee::printScoreLine(string name, int score)
{
    cout << "| " << left << setw(18) << name << "| ";
    if (score >= 0)
    {
        cout << right << setw(5) << score;
    }
    else
    {
        cout << "     ";
    }
    cout << " |" << endl;
}

/********************************
 *
 * getScoreOption
 * --------------------
 * This function gets the score category which the player wishes to score
 * with the current roll.  The function ensures that the response corresponds
 * to a valid category.  It also check to make sure that the selected category
 * has not yet been scored (unscored categories contain the value EMPTY).
 *
 ********************************/
int Yahtzee::getScoreOption()
{
    int ans;
    bool valid = false;
    cout << "Here are the categories: " << endl;
    cout << "1. Ones" << endl;
    cout << "2. Twos" << endl;
    cout << "3. Threes" << endl;
    cout << "4. Fours" << endl;
    cout << "5. Fives" << endl;
    cout << "6. Sixes" << endl;
    cout << "7. Three of a kind" << endl;
    cout << "8. Four of a kind" << endl;
    cout << "9. Full House" << endl;
    cout << "10. Small Straight" << endl;
    cout << "11. Large Straight" << endl;
    cout << "12. Yahtzee" << endl;
    cout << "13. Chance" << endl;
    do
    {
        cout << "How would you like to score this? ";
        while (!(cin >> ans))
        {
            cout << "Please enter an integer value" << endl;
            clearStdin();
        }
        while (ans < 0 || ans > NUM_CATEGORIES)
        {
            cout << "Please enter a number between 1 and " << NUM_CATEGORIES << ": ";

            if (!(cin >> ans))
                clearStdin();
        }
        switch (ans)
        {
            case ONES:
                if (onesScore == EMPTY) valid = true;
                break;
            case TWOS:
                if (twosScore == EMPTY) valid = true;
                break;
            case THREES:
                if (threesScore == EMPTY) valid = true;
                break;
            case FOURS:
                if (foursScore == EMPTY) valid = true;
                break;
            case FIVES:
                if (fivesScore == EMPTY) valid = true;
                break;
            case SIXES:
                if (sixesScore == EMPTY) valid = true;
                break;
            case THREE_OF_A_KIND:
                if (threeOfAKind == EMPTY) valid = true;
                break;
            case FOUR_OF_A_KIND:
                if (fourOfAKind == EMPTY) valid = true;
                break;
            case FULL_HOUSE:
                if (fullHouse == EMPTY) valid = true;
                break;
            case SMALL_STRAIGHT:
                if (smallStraight == EMPTY) valid = true;
                break;
            case LARGE_STRAIGHT:
                if (largeStraight == EMPTY) valid = true;
                break;
            case YAHTZEE:
                if (yahtzee == EMPTY) valid = true;
                break;
            case CHANCE:
                if (chance == EMPTY) valid = true;
                break;
        }
        if (!valid)
        {
            cout << "That category has already been used" << endl;
        }
    } while (!valid);

    return ans;
}

/********************************
 *
 * tabulateDice
 * --------------------
 * This function calculates and returns the number of dice
 * which show the value n.
 *
 ********************************/
int Yahtzee::tabulateDice(int n, int d1, int d2, int d3, int d4, int d5)
{
    int ans = 0;
    if (d1 == n) ans++;
    if (d2 == n) ans++;
    if (d3 == n) ans++;
    if (d4 == n) ans++;
    if (d5 == n) ans++;
    return ans;
}

int Yahtzee::scoreOnes()
{
    int score = 0;
    const int _num = 1;
    int rtd_values[5] = {die1, die2, die3, die4, die5};

    for (int rtd_value : rtd_values)
        if (rtd_value == _num)
            score += _num;

    if (score == 0)
        INVALID_CATAGORY = true;

    return score;
}

int Yahtzee::scoreTwos()
{
    int score = 0;
    const int _num = 2;
    int rtd_values[5] = {die1, die2, die3, die4, die5};

    for (int rtd_value : rtd_values)
        if (rtd_value == _num)
            score += _num;

    if (score == 0)
        INVALID_CATAGORY = true;

    return score;
}

int Yahtzee::scoreThrees()
{
    int score = 0;
    const int _num = 3;
    int rtd_values[5] = {die1, die2, die3, die4, die5};

    for (int rtd_value : rtd_values)
        if (rtd_value == _num)
            score += _num;

    if (score == 0)
        INVALID_CATAGORY = true;
    return score;
}

int Yahtzee::scoreFours()
{
    int score = 0;
    const int _num = 4;
    int rtd_values[5] = {die1, die2, die3, die4, die5};

    for (int rtd_value : rtd_values)
        if (rtd_value == _num)
            score += _num;

    if (score == 0)
        INVALID_CATAGORY = true;

    return score;
}

int Yahtzee::scoreFives()
{
    int score = 0;
    const int _num = 5;
    int rtd_values[5] = {die1, die2, die3, die4, die5};

    for (int rtd_value : rtd_values)
        if (rtd_value == _num)
            score += _num;

    if (score == 0)
        INVALID_CATAGORY = true;

    return score;
}

int Yahtzee::scoreSixes()
{
    int score = 0;
    const int _num = 6;
    int rtd_values[5] = {die1, die2, die3, die4, die5};

    for (int rtd_value : rtd_values)
        if (rtd_value == _num)
            score += _num;

    if (score == 0)
        INVALID_CATAGORY = true;

    return score;
}


int Yahtzee::scoreThreeOfAKind()
{
    int score = 0;

    if (ones == 3 ||
        twos == 3 ||
        threes == 3 ||
        fours == 3 ||
        fives == 3 ||
        sixes == 3)
        score = scoreChance();

    if (score == 0)
        INVALID_CATAGORY = true;

    return score;
}

int Yahtzee::scoreFourOfAKind()
{
    int score = 0;

    if (ones == 4 ||
        twos == 4 ||
        threes == 4 ||
        fours == 4 ||
        fives == 4 ||
        sixes == 4)
        score = scoreChance();

    if (score == 0)
        INVALID_CATAGORY = true;

    return score;
}

int Yahtzee::scoreFullHouse()
{
    int score = 0;
    // Use the previous 'counter' variables from tabulateDice() function instead.
    int rtd_count[] = {ones, twos, threes, fours, fives, sixes};

    // Declare two booleans variables to flag whether there are two sets.
    bool pairOfTwo = false;
    bool pairOfThree = false;

    // Iterate through all the variables.
    for (int i = 0; i < sizeof(rtd_count) / sizeof(rtd_count[0]); i++)
    {
        // Check if a set of 2 or 3.
        // If they do, flag the set as true.
        // There is no need to check the dice values anymore to see if they are the same.
        if (rtd_count[i] == 2)
            pairOfTwo = true;
        if (rtd_count[i] == 3)
            pairOfThree = true;
    }

    // Validate whether or not they have the two sets.
    if (pairOfTwo and pairOfThree)
        score = 25;

    // Flag the catagory as invalid if they do not have the correct dice to use.
    if (score == 0)
        INVALID_CATAGORY = true;

    return score;
}

int Yahtzee::scoreSmallStraight()
{
    int score = 0;
    int rtd_values[5] = {die1, die2, die3, die4, die5};


    if (ones == 1 &&
        twos == 1 &&
        threes == 1 &&
        fours == 1)
        score = 30;
    if (twos == 1 &&
        threes == 1 &&
        fours == 1 &&
        fives == 1)
        score = 30;
    if (threes == 1 &&
        fours == 1 &&
        fives == 1 &&
        sixes == 1)
        score = 30;

    if (score == 0)
        INVALID_CATAGORY = true;

    return score;
}

int Yahtzee::scoreLargeStraight()
{
    int score = 0;

    if (ones == 1 &&
        twos == 1 &&
        threes == 1 &&
        fours == 1 &&
        fives == 1)
        score = 30;
    if (twos == 1 &&
        threes == 1 &&
        fours == 1 &&
        fives == 1 &&
        sixes == 1)
        score = 30;


    if (score == 0)
        INVALID_CATAGORY = true;

    return score;
}

int Yahtzee::scoreYahtzee()
{
    int score = 0;
    int rtd_quantities[6] = {ones, twos, threes, fours, fives, sixes};

    for (int i=0; i<6; ++i)
        if (rtd_quantities[i] == 6)
            score = 50;


    if (score == 0)
        INVALID_CATAGORY = true;

    return score;
}

int Yahtzee::scoreChance()
{
    int score = 0;
    int rtd_values[5] = {die1, die2, die3, die4, die5};

    for (int i = 0; i < sizeof(rtd_values) / sizeof(rtd_values[0]); i++)
        score += rtd_values[i];


    if (score == 0)
        INVALID_CATAGORY = true;

    return score;
}

void Yahtzee::clearStdin()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

