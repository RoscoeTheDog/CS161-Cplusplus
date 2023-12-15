#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <chrono>

using namespace std;

void clear_screen()
{
    /**
        This function clears the console screen depending on what operating system
        the user is running by using preprocessor directives. The code below does not
        include support for mobile or other platforms in which are considered uncommon.

        The following snippit was borrowed from an inquired thread on Reddit.com:
        (URL: https://www.reddit.com/r/cpp_questions/comments/dchmr6/how_to_return_an_object_or_pointer_to_object_from/)

        For more information on how preprocessor directives work:
        (URL: http://www.cplusplus.com/doc/tutorial/preprocessor/)

        For an extensive list of more operating system Macros:
        (URL: https://sourceforge.net/p/predef/wiki/OperatingSystems/)
    */


#if defined(_WIN32) || defined(__WIN64)  /// Technically, we could just say _WIN32, as it includes both 32/64 bit architectures.
    system("CLS");

#elif defined(__unix__) || defined(__unix)|| (defined(__APPLE__) && defined(__MACH__))
    system("clear");

#endif
}

int get_rand_num()
{
    /**
        Simple Function that generates a random number and returns it
    */

    srand(static_cast<int>( time(0)));
    int z = ( rand() & 99) + 1;

    return z;
}

struct Numbers
{
    int x = get_rand_num();
    int y = get_rand_num();
    int answer;

};

void prompt_sumof(int x, int y)
{
    int user_answer;
    int fmt_width = 3;
    std::ios state(nullptr);

    cout << "What is the sum of " << x << " and " << y << "? " << "\n";
    cin >> user_answer;
    clear_screen();

    /// defined formatter settings
    cout << setfill(' ')
         << setw(fmt_width)
         << x                   << "\n";

    cout << "+"
         << setw(fmt_width - 1)  /// (-1 to compensate for the operand char on same line)
         << y                   << "\n";

    string _equals;
    for (int i=0; i<fmt_width; i++)
    {
        _equals = _equals + "_";
    }

    cout.copyfmt(state);  /// resets formating to default state.

    cout << _equals             << "\n"
         << setfill(' ')
         << setw(fmt_width)
         << (x + y)             << "\n\n";

    if ( user_answer == (x + y))
    {
        cout << "That is correct. You are a wonderful student! " << "\n";
    }

    else
    {
        cout << "Too bad Chad, try again next time! " << "\n";
    }

}

void prompt_diffof(int x, int y)
{
    int user_answer;
    int fmt_width = 3;
    std::ios state(nullptr);

    cout << "What is the difference of " << x << " and " << y << "? " << "\n";
    cin >> user_answer;
    clear_screen();

    /// defined formatter settings
    cout << setfill(' ')
         << setw(fmt_width)
         << x                   << "\n";

    cout << "-"
         << setw(fmt_width - 1)  /// (-1 to compensate for the operand char on same line)
         << y                   << "\n";

    string _equals;
    for (int i=0; i<fmt_width; i++)
    {
        _equals = _equals + "_";
    }

    cout.copyfmt(state);  /// resets formating to default state.

    cout << _equals             << "\n"
         << setfill(' ')
         << setw(fmt_width)
         << (x + y)             << "\n\n";

    if ( user_answer == (x - y))
    {
        cout << "That is correct. You are a wonderful student! " << "\n";
    }

    else
    {
        cout << "Too bad Chad, try again next time! " << "\n";
    }

}

void prompt_productof(int x, int y)
{
    int user_answer;
    int fmt_width = 3;
    std::ios state(nullptr);

    cout << "What is the product of " << x << " and " << y << "? " << "\n";
    cin >> user_answer;
    clear_screen();

    /// defined formatter settings
    cout << setfill(' ')
         << setw(fmt_width)
         << x                   << "\n";

    cout << "*"
         << setw(fmt_width - 1)  /// (-1 to compensate for the operand char on same line)
         << y                   << "\n";

    string _equals;
    for (int i=0; i<fmt_width; i++)
    {
        _equals = _equals + "_";
    }

    cout.copyfmt(state);  /// resets formating to default state.

    cout << _equals             << "\n"
         << setfill(' ')
         << setw(fmt_width)
         << (x + y)             << "\n\n";

    if ( user_answer == (x * y))
    {
        cout << "That is correct. You are a wonderful student! " << "\n";
    }

    else
    {
        cout << "Too bad Chad, try again next time! " << "\n";
    }
}

void prompt_quotantof(int x, int y)
{
    int user_answer;
    int fmt_width = 3;
    std::ios state(nullptr);

    cout << "What is the quotant of " << x << " and " << y << "? " << "\n";
    cin >> user_answer;
    clear_screen();

    /// defined formatter settings
    cout << setfill(' ')
         << setw(fmt_width)
         << x                   << "\n";

    cout << "/"
         << setw(fmt_width - 1)  /// (-1 to compensate for the operand char on same line)
         << y                   << "\n";

    string _equals;
    for (int i=0; i<fmt_width; i++)
    {
        _equals = _equals + "_";
    }

    cout.copyfmt(state);  /// resets formating to default state.

    cout << _equals             << "\n"
         << setfill(' ')
         << setw(fmt_width)
         << (x / y)             << "\n\n";

    if ( user_answer == (x / y))
    {
        cout << "That is correct. You are a wonderful student! " << "\n";
    }

    else
    {
        cout << "Too bad Chad, try again next time! " << "\n";
    }
}

void prompt_arithmatic_practice()
{
    Numbers _dataset;  /// contains x, y variables
    char _op;   /// user input operand type

    /// generate until we get two seperate numbers
    while (_dataset.x == _dataset.y)
    {
        _dataset.x = get_rand_num();
        _dataset.y = get_rand_num();
    }

    cout << "Would you like to perform addition(a), subtraction(s), multiplication(m) or division(d)? " << "\n";
    cin >> _op;

    switch ( _op)   /// switches are cool!
    {
        case 'a':
            prompt_sumof(_dataset.x, _dataset.y);
            break;

        case 's':
            prompt_diffof(_dataset.x, _dataset.y);
            break;

        case 'm':
            prompt_productof(_dataset.x, _dataset.y);
            break;

        case 'd':
            prompt_quotantof(_dataset.x, _dataset.y);
            break;
    }
}

void check_num()
{
    int x = get_rand_num();
    int y = get_rand_num();
    int answer;
    int result;

    /// keep generating a random number until they are no longer the same.
    while( x == y)
    {
        x = get_rand_num();
        y = get_rand_num();
    }

    if ( x < y)
    {
        result = x;
    }

    else
    {
        result = y;
    }

    cout << "Which number is smaller? "      << "\n"
         << x << " or " << y                << endl;

    cin >> answer;

    if ( answer ==  result)
    {
        cout << "That is correct. You are a good student."      << "\n";
    }

    else
    {
        cout << "Sorry that is incorrect."                      << "\n";
    }
}

int main()
{
    prompt_arithmatic_practice();

    return 0;
}
