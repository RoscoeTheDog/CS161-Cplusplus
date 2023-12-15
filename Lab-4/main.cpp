#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
/*
 1. Write a program that allows the user to enter a positive integer and displays a list of the
factors of that integer. Factors are those numbers that evenly divide a number, for
example the factors of 12 are 1, 2, 3, 4, 6, and 12. If the user enters zero or a negative
number, the program should request the user to enter a new number. As an extra
challenge, you can have your program loop until the user no longer wants to enter a number.
 */

// Parser: Handles data type conversions
class Parser
{
public:
    // static string-to-int method. Use cases for parsing getline(cin, <string>)
    static int StringToInt(const string& simpleString);
};

int Parser::StringToInt(const string& simpleString)
{
    int value = 0;

    stringstream parser(simpleString);
    parser >> value;

    return value;
}


void PrintFactors(int x)
{

    cout << "The Factors of " << x << " are: " << endl;
    for (int i=1; i <= x; i++)
    {
        if ( x % i == 0)
        {
            cout << i << endl;
        }
    }
    cout << endl;
}

void PromptFactor()
{
    int num = 1;
    string num_input;

    do
    {
        cout << "Please enter a positive integer to factor: " << "\n";

        getline(cin, num_input);
        num = Parser::StringToInt(num_input);

        PrintFactors(num);

    }   while (num < 1);

}

void EnterNumber() {
    string user_input;  // string input, for easier handling of input buffer.
    int num = 1;    // value of 1, so loop is not canceled immediately.
    vector<int> v;     // empty v to hold all entered answers.

    int smallest = 0;
    int largest = 0;

    cout << "Please enter a number between 0 and 100." << endl;

    for (int i = 0; num != 0; i++)
    {
        getline(cin, user_input);
        num = Parser::StringToInt(user_input);

        if (100 > 0 < num) {
            // append current entry to the end of vector
            v.insert(v.end(), num);

            // iterate through all of our stored answers.
            for ( unsigned y=0; y<v.size(); y++)
            {
                // temp store the value for current working iteration of vector position (Note: variable 'x' is just so it's easier to read).
                int working_value = v[y];

                smallest = 0;
                largest = 0;

                /*
                 *  on first iteration, conditional of > or < will not be stored, they will be ==.
                 *  to circumvent this, check if first iteration and do not check against vector value.
                */

                if ( i == 0)
                {
                    if (working_value > largest)
                        largest = working_value;

                    if (working_value < largest)
                        smallest = working_value;
                }

                else
                {
                    // iterate through vector again and compare the first positions value against others.
                    for ( unsigned z=0; z<v.size(); z++)
                    {
                        if (working_value > largest)
                            largest = working_value;

                        if (working_value < largest)
                            smallest = working_value;

                        if (v[y] > v[z])
                            largest = v[y];

                        if (v[y] < v[z])
                            smallest = v[y];
                    }

                }

            }

        }

        cout << "Your largest number is: " << largest               << "\n"
             << "Your smallest number is: " << smallest             << "\n"
             << "You have a total of " << v.size() << " entries"    << endl;

    }

}


void RangeNumbers()
{
    int smallest = 0;
    int largest = 0;
    int current;
    int counter = 0;
    string _inp;

    do
    {
        cout << "Please Enter a number between 0 and 100." << endl;

        getline(cin, _inp);
        current = Parser::StringToInt(_inp);

        if ( counter == 0)
        {
            largest = current;
            smallest = current;
        }

        else if ( current > largest)
        {
            largest = current;
        }

        else if ( current < smallest)
        {
            smallest = current;
        }

        cout << "Your largest entered number is: " << largest << "\n"
             << "Your smallest entered number is: " << smallest << endl;

        counter += 1;

    }while (current != 0);

}


int main() {
    /// program 1: display factors of an entered number.
    PromptFactor();

    /// program 2: display largest and smallest number of an entered number.
    RangeNumbers();

    /// program 2b: display largest and smallest number of an entered number AND save the numbers/entries.
//    EnterNumber();

    return 0;
}