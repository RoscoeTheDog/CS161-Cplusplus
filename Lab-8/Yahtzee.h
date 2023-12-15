//
// Created and modified by Aspen on 11/22/2019.
//

#ifndef LAB_8_YAHTZEE_H
#define LAB_8_YAHTZEE_H

#include <string>

using namespace std;

class Yahtzee {
private:
    const int NUM_CATEGORIES = 13;
    const int SIDES = 6;
    const int EMPTY = -1;
    bool INVALID_CATAGORY = false;

    // Enum will index the variables names starting from the beginning value.
    enum Category {
        ONES = 1, TWOS, THREES, FOURS, FIVES, SIXES, THREE_OF_A_KIND,
        FOUR_OF_A_KIND, FULL_HOUSE, SMALL_STRAIGHT, LARGE_STRAIGHT,
        YAHTZEE, CHANCE
    };

    int die1, die2, die3, die4, die5;
    bool redo1, redo2, redo3, redo4, redo5;

    int ones, twos, threes, fours, fives, sixes;

    int onesScore, twosScore, threesScore, foursScore, fivesScore, sixesScore;
    int threeOfAKind;
    int fourOfAKind;
    int fullHouse;
    int smallStraight;
    int largeStraight;
    int yahtzee;
    int chance;


public:

    Yahtzee();

    void printRoll();

    bool askReroll(int n);

    void printSeparator();

    void printScore();

    void printScoreLine(string name, int score);

    int getScoreOption();

    int tabulateDice(int n, int d1, int d2, int d3, int d4, int d5);

    int scoreOnes();

    int scoreTwos();

    int scoreThrees();

    int scoreFours();

    int scoreFives();

    int scoreSixes();

    int scoreThreeOfAKind();

    int scoreFourOfAKind();

    int scoreYahtzee();

    void clearStdin();

    int scoreChance();

    int scoreSmallStraight();

    int scoreLargeStraight();

    int scoreFullHouse();

    void overrideCategory();
};


#endif //LAB_8_YAHTZEE_H
