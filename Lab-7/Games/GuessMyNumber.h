/*

Guess	My	Number
Create	a	mul5-func5on	version	of	the	Guess	My	Number	game.	Your	game	should	generate	a	random	number
between 1 and 99, ask the user for a guess, and respond to each guess with correct, too high, or too	low as
needed. Once the user guessesthe number correctly, report how many guessesit took and ask if they	want	to
play	again.
You	need	to	have	at	least	the	following	three	func5ons:
	 displayInstruc5ons	—	no	inputs,	displays	the	instruc5ons
	 getNumber	—	inputs	are	min	and	max,	returns	a	random	number	between	min	and	max
	 getMove	—	inputs	are	min	and	max,	gets,	validates,	returns	an	integer	from	the	user
	 	 that	is	between	min	and	max
	 playAgain	—	no	inputs,	return	true	if	the	user	wants		to	go	again,	false	if	they	do	not
Your program should have appropriate comments(including at least one per func5on) and you should use
constants	where	appropriate.	All	input	should	be validated.

 */

#ifndef LAB_7_GUESSMYNUMBER_H
#define LAB_7_GUESSMYNUMBER_H


class GuessMyNumber
{
private:
    unsigned number;
    int player_guess;
    int attempts;
    bool valid;
    char select;

public:

    GuessMyNumber();

    void displayInstructions();

    void getNumber();

    void getMove();

    void playAgain();

    void startGame();

    int getRand();

    void checkMove();
};


#endif //LAB_7_GUESSMYNUMBER_H
