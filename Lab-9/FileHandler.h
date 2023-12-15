//
// Created by Aspen on 12/1/2019.
//

#ifndef LAB_9_FILEHANDLER_H
#define LAB_9_FILEHANDLER_H
#include <fstream>
#include <ios>
#include <vector>

using namespace std;

class FileHandler
{
public:

    FileHandler();

    struct dataObject{
        char function;
        char brush;
        int argument1;
        int argument2;
    };

    void writeRectangle(ofstream &file, int height, int width, char brush);

    void writeTriangle(ofstream &file, int scale, char brush);

    void writeSquare(ofstream &file, int scale, char brush);

    void writeDiamond(ofstream &file, int scale, char brush);

    ofstream streamOut(string path);

    vector<dataObject> parseInput(ifstream &stream);

    ifstream streamIn(string path);

    static void commit(ofstream &file);
};


#endif //LAB_9_FILEHANDLER_H
