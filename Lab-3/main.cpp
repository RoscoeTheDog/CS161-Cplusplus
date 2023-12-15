/*
 *      Aspen Mallery
 *      10/20/2019
 *      Lab 3
 *      Jim Bailey CS161C+ 12-2pm Mon/Wed
 */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
 *      Comment to the Instructor:
 *
 *          Most of the first declared class was used to gain a better understanding of how constructors and methods work in C++
 *          Many of it's comments are for future-use and reference for the working student (Me) to understand.
 *
 */

class NewProperty
{
private:

    /*
     *      You can declare a variable with braces on it to assign it value of 0. This avoids having to assign a value with a constructor.
     *      However, this is not recommended as a good practice as briefly mentioned by instructor and discussed on the Reddit forums.
     *      NOTE: THIS IS A C++ 11 OR HIGHER FEATURE.
     */

    // most of these are unused for now.
    string property_name{};
    int sale_price = 0;
    float rep_static_earnings{};
    float rep_rate{};
    float rep_gross_earnings{};
    int appraised_value{};
    int estate_costs{};
    int gross_profit{};
    int net_profit{};
    string rep_name;

public:

    /// This is our example default public Constructor. *Notice how it has the same name as the Class*
    NewProperty()
    {
        // Do stuff at startup. Ensure to initialize variables.
        sale_price = 0;
    }

    /*
     *     Declaring 'explicit' tells the G++ compiler that the constructor *only* wants an integer type; It is immutable.
     *     This is used to avoids coding unexpected behavior from implicit type conversions (say, passing a Float truncated down to an Integer).
     */

    explicit NewProperty(int initial_price) : // If we specify a newly declared parameter to a constructor, we can then pass an argument when instantiation a class.
            sale_price(initial_price) // We can use that variable to assign another value to a different class member.
    {

        /*
         *      Since we have two constructors, this one will be *overloaded* whenever we pass an argument to the instantiate the class.
         *      This way, we can perform some logic ahead of time to automatically determine the rate that the Sales Representative is to receive.
         */

        if ( sale_price > 30000)
        {
            rep_static_earnings = 25000;
            rep_rate = 0.15;
        }

        else if ( 100000 < sale_price || sale_price < 300000)
        {
            rep_static_earnings = 5000;
            rep_rate = 0.10;
        }

        else
        {
            rep_rate = 0.05;
        }
    }

    /*
     *      The next declared method is considered an "Inline Implementation".
     *      Which is basically just a method with a given Definition during the time of it's Deceleration.
     */

    void CalculateEarnings() // Until we can determine how to pass around an instance of a class type, we need to include a method that performs the Sales calculations upon a call.
    {
        if ( sale_price > 30000)
        {
            rep_static_earnings = 25000;
            rep_rate = 0.15;
        }

        else if ( 100000 < sale_price || sale_price < 300000)
        {
            rep_static_earnings = 5000;
            rep_rate = 0.10;
        }

        else
        {
            rep_rate = 0.05;
        }
    }

    /*
     *      We can also perform a forward decleration of a method within a class scope, then define it later outside of it's scope.
     *
     *      In C++ this is apparently a good standard convention to apply:
     *      1) Declare within a Class's scope in a cpp file. This acts as a "Header".
     *      2) Add definitions to the Class methods in another .h file.
     *      3) Include the .h file in the header to important the definitions.
     */

    double GetRepresentativeEarnings(string name);

    void SetPropertyName(string name);

    void SetPropertyValue(int value);

    void SetRepresentativeName(string name);

};

/// We can use the scope operator (::) to access a public class member and add a definition to the decleration.
void NewProperty::SetPropertyValue(int value)
{
    sale_price = value;
}

void NewProperty::SetRepresentativeName(string name)
{
    rep_name = name;
}

double NewProperty::GetRepresentativeEarnings(string name)
{
    // TODO: Save the earnings to a file, array or table of some kind.
    double earnings;

    earnings = (static_cast<float>(sale_price) * rep_rate) + rep_static_earnings;

    return earnings;
}

void NewProperty::SetPropertyName(string name)
{
    property_name = (name);
}

/*
 *      This next class should technically be in another cpp file.
 *
 *      For now, I will include it within one file since I am still learning how to configure CMake and building using a different IDE than Code::Blocks.
 *      It also must remain friendly for professor to build & compile on his machine(s)!
*/

// Parser: Handles data type conversions easier (could remain just a function, but in theory would expand to be much bigger).
class Parser
{
private:
    // Reserved.

public:
    // static string-to-int parse method.
    static int ParseString(const string& simpleString);
};

int Parser::ParseString(const string& simpleString)
{
    int value = 0;

    stringstream parser(simpleString);
    parser >> value;

    return value;
}

// UserPrompt: Handles UI operations.
class UserPrompt
{
private:
    string user_name;
    string property_name;
    string property_value{};
    string rep_name{};

public:
    NewProperty property1;  // We will only declare one type for now to keep project's scope within reason.

    void static clear_screen()
    {
        /*
         *      This function clears the console screen depending on what operating system the user is running
         *      using preprocessor directives. The code below does not include support for mobile or other platforms which are considered uncommon.
         *
         *      The following snippit was borrowed from an inquired thread on Reddit.com:
         *      (URL: https://www.reddit.com/r/cpp_questions/comments/dchmr6/how_to_return_an_object_or_pointer_to_object_from/)
         *
         *      For more information on how preprocessor directives work:
         *      (URL: http://www.cplusplus.com/doc/tutorial/preprocessor/)
         *
         *      For an extensive list of more operating system Macros:
         *      (URL: https://sourceforge.net/p/predef/wiki/OperatingSystems/)
         */

#if defined(_WIN32) || defined(__WIN64)  /// Technically, we could just say _WIN32, as it includes both 32/64 bit architectures.
        system("CLS");

#elif defined(__unix__) || defined(__unix)|| (defined(__APPLE__) && defined(__MACH__))
        system("clear");

#endif
    }

    void WelcomeScreen()
    {
        cout << "Starting the Mallery Financial Calculator Program V1.1"    << "\n"
             << "Please begin by entering a User Name: "                    << "\n";

        // Get user's name
        getline(cin, user_name);

        cout << "Welcome " << user_name                                     << "\n";

        // return to menu
        OptionsMenu();
    }

    void NewPropertyMenu()
    {
        cout << "Please enter the name of new property: "                   << "\n";

        // Get property name
        getline(cin, property_name);

        // Set property name
        property1.SetPropertyName(property_name);

        cout << "Please enter the total value of the property: "            << "\n";

        // Get Int value as String (this is better for handling of cin)
        getline(cin, property_value);

        // use Parser class to handle type conversions using self-declared class methods.
        property1.SetPropertyValue(Parser::ParseString(property_value));

        // TODO: Save properties to an array or txt file? if we have time...
        cout << property_name << " has been saved."                         << "\n"
             << "returning to the Main Menu."                               << endl;

        // return to menu
        OptionsMenu();

        // TODO: We can add extra features here if we find more time.
    }

    void PropertyInfoMenu()
    {
        cout << "Please enter the Real Estate Representative name: "                        << "\n";

        // Get Sales Person's name
        getline(cin, rep_name);

        // Set
        property1.SetRepresentativeName(rep_name);

        // Push the calculations
        property1.CalculateEarnings();

        cout << "Representative Name: " << rep_name                                         << "\n"
             << "Total Earnings: " << property1.GetRepresentativeEarnings(rep_name)  << endl;

        // return to menu
        OptionsMenu();
    }

    void OptionsMenu()
    {
        string sel;     // declare within local method's scope to ensure input is re-assigned.

        /*
         *          A Do/While seemed appropriate before I noticed you can set a default switch.
         *          Now it may be better to use a simple while-loop instead since the switch will continue by default recursively.
         */

        do
        {
            cout << "What would you like to do (select a number)?"            << "\n"
                 << "1) Enter a new property"                               << "\n"
                 << "2) Retrieve representetives commission"                << "\n"
                 << "3) Exit program"                                       << endl;

            // Get selection option
            getline(cin, sel);

            // 'Switch' to appropriate class method.
            switch(Parser::ParseString(sel))   //inline access to ParseString method; returns Int.
            {
                default:    // if not valid case, prompt user for invalid entry and restart menu.
                    cout << "That is not a valid entry. Please select a number from the list." << "\n";
                    OptionsMenu();
                    break;

                case 1:
                    NewPropertyMenu();
                    break;

                case 2:
                    PropertyInfoMenu();
                    break;

                case 3:
                    cout << "Exiting the Mallery Financial Calculator Program V1.1 "        << "\n"
                         << "More features coming soon! :) "                            << endl;
                    break;
            }

        } while (sel.length() > 1);     // if user enters a string that is more than two chars, continue.

    }

};


class Calculator {
private:
    int default_position;

    // TODO: Find out how to perform inheretence on structures.
    struct Numbers
    {
        int x{};
        int y{};
        int answer{};
    };

public:

    Calculator()
    {
        default_position = 1;
    };

    explicit Calculator(int change_default_position)
    {
        default_position = change_default_position;
    }

    /// Function that seeds a random number generator and returns a number up to a certain amount of digit spaces. Default: 1 digit space.
    int GetRand(int position = 1) {

        // power of is an *iterator*
        int power_of;

        // check to see if no argument was passed manually
        if (position == 1)
        {
            position = default_position;
            power_of = 2;
        }
        else
        {
            power_of = position;
        }

        // take the position to the power of the original *static* integer position
        for (int i = 1; i<power_of; i++)
        {
            position *= 10;
        }

        // Seed the generator
        srand(static_cast<int>( time(nullptr)));

        // Call rand and modulus by the position (# xxxxx)
        return (rand() % position);
    }

    void SumOf(int x, int y)
    {
        string user_answer;
        int answer_parsed;
        int answer = x + y;
        int fmt_width = default_position + 2; // whatever the length of digits we calculate, space apart by 2 additional char spaces
        std::ios state(nullptr); // save fmt state

        cout << "What is the sum of " << x << " and " << y << "? " << "\n";

        // Get answer
        getline(cin, user_answer);

        // Parse answer to int
        answer_parsed = Parser::ParseString(user_answer);

        /// defined formatter settings
        cout << setfill(' ')
             << setw(fmt_width)
             << x               << "\n";

        /// reset formatting for + to be anchored at [0] position (for this next statement)
        cout << setw(0);
        cout << "+"             << "\n";

        /// do it again for spaces at correct index
        cout << setfill(' ')
             << setw(fmt_width)
             << y               << "\n";

        /// we don't know how many "_" to add, because that is determined by the length of the original numbers.
        string _equals;
        for (int i=0; i<fmt_width; i++)
        {
            _equals += "_";
        }

        cout.copyfmt(state);  /// resets formatting state.

        // print bar ________.
        cout << _equals << "\n";

        // print # of spaces for fmt length on newline.
        for (int i=0; i<(fmt_width - 1); i++)
        {
            cout << " ";
        };

        // print answer and safe-flush.
        cout << (x + y) << endl;

        if (answer_parsed == answer)
        {
            cout << "That is correct. You are a wonderful student! " << "\n";
        }

        else
        {
            cout << "Too bad Chad, try again next time! " << "\n";
        }

    }

    void DiffOf(int x, int y)
    {
        string user_answer;
        int answer_parsed;
        int answer = x - y;
        int fmt_width = default_position + 2; // whatever the length of digits we calculate, space apart by 2 additional char spaces
        std::ios state(nullptr); // save fmt state

        cout << "What is the difference of " << x << " and " << y << "? " << "\n";

        // Get answer
        getline(cin, user_answer);

        // Parse answer to int
        answer_parsed = Parser::ParseString(user_answer);

        /// defined formatter settings
        cout << setfill(' ')
             << setw(fmt_width)
             << x               << "\n";

        /// reset formatting for + to be anchored at [0] position (for this next statement)
        cout << setw(0);
        cout << "-"             << "\n";

        /// do it again for spaces at correct index
        cout << setfill(' ')
             << setw(fmt_width)
             << y               << "\n";

        /// we don't know how many "_" to add, because that is determined by the length of the original numbers.
        string _equals;
        for (int i=0; i<fmt_width; i++)
        {
            _equals += "_";
        }

        cout.copyfmt(state);  /// resets formatting state.

        // print bar ________.
        cout << _equals << "\n";

        // print # of spaces for fmt length on newline.
        for (int i=0; i<(fmt_width - 1); i++)
        {
            cout << " ";
        };

        // print answer and safe-flush.
        cout << (x - y) << endl;

        if (answer_parsed == answer)
        {
            cout << "That is correct. You are a wonderful student! " << "\n";
        }

        else
        {
            cout << "Too bad Chad, try again next time! " << "\n";
        }
    }

    void ProductOf(int x, int y)
    {
        string user_answer;
        int answer_parsed;
        int answer = x * y;
        int fmt_width = default_position + 2; // whatever the length of digits we calculate, space apart by 2 additional char spaces
        std::ios state(nullptr); // save fmt state

        cout << "What is the product of " << x << " and " << y << "? " << "\n";

        // Get answer
        getline(cin, user_answer);

        // Parse answer to int
        answer_parsed = Parser::ParseString(user_answer);

        /// defined formatter settings
        cout << setfill(' ')
             << setw(fmt_width)
             << x               << "\n";

        /// reset formatting for + to be anchored at [0] position (for this next statement)
        cout << setw(0);
        cout << "*"             << "\n";

        /// do it again for spaces at correct index
        cout << setfill(' ')
             << setw(fmt_width)
             << y               << "\n";

        /// we don't know how many "_" to add, because that is determined by the length of the original numbers.
        string _equals;
        for (int i=0; i<fmt_width; i++)
        {
            _equals += "_";
        }

        cout.copyfmt(state);  /// resets formatting state.

        // print bar ________.
        cout << _equals << "\n";

        // print # of spaces for fmt length on newline.
        for (int i=0; i<(fmt_width - 1); i++)
        {
            cout << " ";
        };

        // print answer and safe-flush.
        cout << (x * y) << endl;

        if (answer_parsed == answer)
        {
            cout << "That is correct. You are a wonderful student! " << "\n";
        }

        else
        {
            cout << "Too bad Chad, try again next time! " << "\n";
        }
    }

    void QuotentOf(int x, int y)
    {
        string user_answer;
        int answer_parsed;
        int answer = x / y;
        int fmt_width = default_position + 2; // whatever the length of digits we calculate, space apart by 2 additional char spaces
        std::ios state(nullptr); // save fmt state

        cout << "What is the quotent of " << x << " and " << y << "? " << "\n";

        // Get answer
        getline(cin, user_answer);

        // Parse answer to int
        answer_parsed = Parser::ParseString(user_answer);

        /// defined formatter settings
        cout << setfill(' ')
             << setw(fmt_width)
             << x               << "\n";

        /// reset formatting for + to be anchored at [0] position (for this next statement)
        cout << setw(0);
        cout << "/"             << "\n";

        /// do it again for spaces at correct index
        cout << setfill(' ')
             << setw(fmt_width)
             << y               << "\n";

        /// we don't know how many "_" to add, because that is determined by the length of the original numbers.
        string _equals;
        for (int i=0; i<fmt_width; i++)
        {
            _equals += "_";
        }

        cout.copyfmt(state);  /// resets formatting state.

        // print bar ________.
        cout << _equals << "\n";

        // print # of spaces for fmt length on newline.
        for (int i=0; i<(fmt_width - 1); i++)
        {
            cout << " ";
        };

        // print answer and flush.
        cout << (x / y) << endl;

        if (answer_parsed == answer)
        {
            cout << "That is correct. You are a wonderful student! " << "\n";
        }

        else
        {
            cout << "Too bad Chad, try again next time! " << "\n";
        }
    }

    void PromptArithmetic()
    {
        string _op;
        Numbers _dataset;

        while (_dataset.x == _dataset.y)
        {
            _dataset.x = GetRand();
            _dataset.y = GetRand();
        }

        cout << "Would you like to perform addition(a), subtraction(s), multiplication(m) or division(d)? " << "\n";
        getline(cin, _op);

        switch ( _op[0])
        {
            case 'a':
                SumOf(_dataset.x, _dataset.y);
                break;

            case 's':
                DiffOf(_dataset.x, _dataset.y);
                break;

            case 'm':
                ProductOf(_dataset.x, _dataset.y);
                break;

            case 'd':
                QuotentOf(_dataset.x, _dataset.y);
                break;
        }
    }

};


int main()
{
    /*
     *      Initial idea was to create a class instance for each property that was input by user.
     *      A passed parameter to the constructor would then perform the calculations upon instantiation.
     *
     *      The problem: I do not yet know how to parse string input to assign an object type's name.
     *                   I ran into this problem a few times in Python as well. I believe it was generally not considered a good practice to do?
     */

    NewProperty SeasideCondo(600000); // <== something like this.

    // Start 1st program's UI.
    UserPrompt User1;
    User1.WelcomeScreen();

    // Start second program that performs Math problems.
    Calculator Calc;
    Calc.PromptArithmetic();

    /*
     *
     *      I ran out of time during my busy week to get this organized the way I'd like. It would be cleaner to read the Calculator class had I been
     *      able to seperate the print functions into the UserPrompt class.
     *
     *      Also maybe make one function instead of 4 seperate ones for + - * /, then add some conditionals which would change the operands. This may be somewhat tricky
     *      since I would not only have to change the string values but also the raw C++ calculations somehow. Not sure if that's very practical or not.
     *
     */

    return 0;
}