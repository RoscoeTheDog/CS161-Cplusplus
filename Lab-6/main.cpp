#include <iostream>

using namespace std;

// Function returns the area of a circle.
double circle(double radius)
{
    double area;

    area = radius * 3.1416; // pi is a constant.

    return area;
}

// Function returns the area of a square.
double square(double side)
{
    double area;

    area = side * side;

    return area;
}

// Function returns the area of a rectangle.
double rectangle(double width, double height)
{
    double area;

    area = width * height;

    return area;

}

// Function returns the area of a triangle.
double triangle(double base, double height)
{
    double area;

    area = .5 * base * height;  // 1/2 is constant.

    return area;

}

int main() {
    int sel = 0;
    bool INVALID = true;

    // Prompt user.
    cout << "Please choose a following function: " << "\n"
         << "1. Area Circle" << "\n"
         << "2. Area Square" << "\n"
         << "3. Area Rectangle" << "\n"
         << "4. Area Triangle" << endl;

    // Type check.
    while(INVALID)
    {
        cin >> sel;

        // Value check.
        if (sel <= 0 || sel > 4)
        {
            cout << "Please enter your answer as a number (1-4)" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
            INVALID = false;
    }

    if (sel == 1)
    {
        double radius;

        cout << "Please enter the radius: " << endl;

        // Type check.
        while(!(cin >> radius))
        {
            cout << "Please enter as a floating point value only" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        double area = circle(radius);

        cout << "Result: " << area << endl;
    }

    if (sel == 2)
    {
        double side;

        cout << "Please enter one of the sides: " << endl;

        // Type check.
        while(!(cin >> side))
        {
            cout << "Please enter as a floating point value only" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        double area = square(side);

        cout << "Result: " << area << endl;
    }

    if (sel == 3)
    {
        double width;
        double height;

        cout << "Please enter the length: " << endl;

        // Type check.
        while(!(cin >> width))
        {
            cout << "Please enter as a floating point value only" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Please enter the height: " << endl;

        // Type check.
        while(!(cin >> height))
        {
            cout << "Please enter as a floating point value only" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        double area = rectangle(width, height);

        cout << "Result: " << area << endl;
    }

    if (sel == 4)
    {
        double base;
        double height;

        cout << "Please enter the base: " << endl;

        // Type check.
        while(!(cin >> base))
        {
            cout << "Please enter as a floating point value only" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Please enter the height: " << endl;

        // Type check.
        while(!(cin >> height))
        {
            cout << "Please enter as a floating point value only" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        double area = triangle(base, height);

        cout << "Result: " << area << endl;
    }

    return 0;
}