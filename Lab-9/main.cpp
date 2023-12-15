#include <string>
#include "FileHandler.h"

using namespace std;

int main()
{
    /*
     *  A Disclosure:
     *      I wanted to keep my 'Handler' Class consistant when returning values to be used at the top of our programs stack.
     *
     *      It would be nice to let "developers" using this class to have a method which automatically parses the input file
     *      and returns a nicely formatted object to use elsewhere. This object could then be used to call our functions
     *      or do other things within the program.
     *
     *      In python, this would be fairly easy by returning a dictionary object. We of course don't have this
     *      in C++ so I thought a struct would be the next best thing.
     *
     *      Since C++ only allows you to return one object at a time, I can not simply return a struct for one line in the input file.
     *      After playing around with this for a few hours, I determined that returning a vector of a type struct would be an alternative
     *      solution for this.
     *
     *      Once returned, we can then just iterate through the vector, unpack the struct objects, and pass struct members as arguments to the appropriate methods.
     */


    // Create an instance of FileHandler
    FileHandler NewHandler;

    // Create our buffer objects using the Handler.
    ifstream inFile = NewHandler.streamIn("infile.txt");
    ofstream outFile = NewHandler.streamOut("outfile.txt");

    // Return a vector of nicely formatted struct objects.
    vector<FileHandler::dataObject> parser = NewHandler.parseInput(inFile);

    // Iterate through this vector, unpack each struct and determine what function to call.
    for (int i=0; i < parser.size(); ++i)
    {
        FileHandler::dataObject parseLine;
        parseLine = parser.at(i);

        switch(parseLine.function)
        {
            case 'R':
                NewHandler.writeRectangle(outFile, parseLine.argument1, parseLine.argument2, parseLine.brush); break;
            case 'S':
                NewHandler.writeSquare(outFile, parseLine.argument1, parseLine.brush); break;
            case 'T':
                NewHandler.writeTriangle(outFile, parseLine.argument1, parseLine.brush); break;
            case 'D':
                NewHandler.writeDiamond(outFile, parseLine.argument1, parseLine.brush); break;
        }
    }

    // Flush all buffers to file without closing. Not closing allows us to keep using the buffer objects if we need to use them elsewhere.
    NewHandler.commit(outFile);
}