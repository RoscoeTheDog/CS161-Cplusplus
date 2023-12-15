//
// Created by Aspen on 12/1/2019.
//

#include "FileHandler.h"
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

FileHandler::FileHandler() {

    // Declare streams.
    ofstream inFile;
    ofstream outFile;

    // Open File.
    inFile.open("infile.txt", ios::app | ios::in);

    // Validate if file can be read.
    if (!inFile.is_open())
        cout << "Error: could not read the input file." << endl;

    // Open File.
    outFile.open("outfile.txt", ios::app | ios::out);

    // Validate if file can be read.
    if (!outFile.is_open())
        cout << "Error: could not read the output file." << endl;

}

ifstream FileHandler::streamIn(string path){
    ifstream file;

    file.open(path, ios::app);

    if(!file.is_open())
        cout << "Error: File could not be read." << endl;

    return file;
}

ofstream FileHandler::streamOut(string path){
    ofstream file;

    file.open(path, ios::app);

    if(!file.is_open())
        cout << "Error: File could not be read." << endl;

    return file;
}


void FileHandler::commit(ofstream &file){
    file.flush();
}

vector<FileHandler::dataObject> FileHandler::parseInput(ifstream &stream){

    vector<vector<char>> readData;
    vector<char> readLine;


    // iterate through the file and get each character
    while (char c = stream.get())
    {
        // skip any spaces
        if (c == ' ')
            continue;
        // if a new carriage return is found, store line vector to list of vectors
        if (c == '\n')
        {
            readData.insert(readData.end(), readLine);
            readLine.clear();   // clear out any of the line vectors values for reiteration.
            continue;
        }

        // if not, add each character to line vector
        readLine.insert(readLine.end(), c);

        if (c == '\377')
            break;
    }

    // Create a vector of struct instances.
    vector<dataObject> parsedFile;

    // Iterate through all lines.
    for (int i=0; i<readData.size(); ++i)
    {
        // Create a new struct for each line.
        dataObject store{};

        // Return the vector from the list of vectors.
        vector<char> vLine = readData.at(i);

        // Iterate through the returned vector.
        for (int j=0; j < vLine.size(); ++j)
        {
            // Return the current working character from the vector list
            char workingChar = vLine.at(j);

            // Determine if the character is a digit.
            if (isdigit(workingChar))

                // Store our values into the current working struct based on their characters position in the vector.
                if (j == 2)
                    store.argument1 = workingChar;
                if (j == 3)
                    store.argument2 = workingChar;

            // If the char is not a digit, store the values chars into members of the struct.
            else
            {
                // If the character is a recognized function shortcut, store it in the struct member named 'function'
                if (workingChar == 'R' ||
                    workingChar == 'T' ||
                    workingChar == 'S' ||
                    workingChar == 'D')
                    store.function = workingChar;

                // If it is not recognized and it is not a integer, we know that this is going to be used to print the object's shape.
                else
                    store.brush = workingChar;

            }
        }

        // Finally, copy the struct to the vector of structs
        parsedFile.insert(parsedFile.end(), store);


        /*
         *  Note:
         *      Structs do not need to be cleared upon each iteration.
         *      It is copied to the vector array before instance's values are overwritten each iteration.
         */
    }

    return parsedFile;


//    for (int i=0; i<stream.get(); ++i)
//    {
//
//    }






//    char __character;
//    vector<char> readLine;
//
//    while (!stream.eof())
//    {
//        stream.get(__character);
//        readLine.insert(readLine.end(), __character);
//
//
//
//
//
//
//
//
//
//
////        if(shape=='R')
////        {
////            stream >> draw >> x >> y;
////            cout << shape << " " << draw << " " << x << " " << y << endl;
////            streamOut << shape << draw << x << y << endl;
////            drawRectangle(draw, x, y);
////
////        }
////        else if(shape=='T')
////        {
////            stream >> draw >> x;
////            cout << shape << " " << draw << " " << x << endl;
////            //writeTriangle(draw, x);
////        }
////        else if(shape=='S')
////        {
////            stream >> draw >> x;
////            cout << shape << " " << draw << " " << x << endl;
////            //writeSquare(draw, x);
////        }
////        else if(shape=='D')
////        {
////            stream >> draw >> x;
////            cout << shape << " " << draw << " " << x << endl;
////            //writeDiamond(draw, x);
////        }
////        else if(shape=='E')
////            break;
//    }

//    return readLine;

}

void FileHandler::writeRectangle(ofstream &file, int height, int width, char brush) {

    file << "Rectangle: " << endl;

    // Verticle Columns.
    for (int i=0; i<height; ++i)
    {
        // Horizontal Rows.
        for (int j=0; j<width; ++j)
            file << brush;

        file << "\n";
    }
}

void FileHandler::writeTriangle(ofstream &File, int size, char brush){
    File << "Triangle: " << endl;

    // This loop will handle our verticle columns.
    for (int k = 0; k < size; ++k)
    {
        // This loop will handle our horizontal rows. Keep appending the character to the stream until loop meets the condition (+1 the amount of rows, if rows start @ 0).
        for (int l = 0; l < k + 1; ++l)
        {
            File << brush;
        }

        // Add the return line statement to move to the next row.
        File << "\n";
    }

}

void FileHandler::writeSquare(ofstream &file, int scale, char brush)
{
    file << "Square: " << endl;

    for (int i = 0; i < scale; ++i)
    {
        for (int j = 0; j < scale; ++j)
            file << brush;

        file << "\n";
    }
}

void FileHandler::writeDiamond(ofstream &file, int scale, char brush) {

    // Shameless ripped from Stackoverflow then modified to look cleaner.
    // https://stackoverflow.com/questions/55504398/c-star-diamond-pattern-written-to-output-file-becomes-jumbled

    file << "Diamond: " << endl;

    for (int i = 0; i <= 2 * scale; i++)
    {
        for (int j = 0; j <= 2 * scale; j++)
        {
            if (i <= scale)
            {
                if (j < scale - i || j > scale + i)
                    file << ' ';

                else
                    file << brush;
            }
            else
            {
                if (j < i - scale || j > 3 * scale - i)
                    file << ' ';

                else
                    file << brush;
            }
        }
        file << endl;
    }
}