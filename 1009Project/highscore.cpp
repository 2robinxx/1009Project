#include "highscore.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

fstream inputFile("Highscore.txt");

void highscore::addFile()
{
    if (!inputFile) {
        inputFile.open("Highscore.txt", fstream::in | fstream::out | fstream::trunc);

        for (int i = 1; i < 11; i++) {
            inputFile << "0" << endl;
        }
        inputFile.close();
        
    }
    else {
        inputFile.open("Highscore.txt", fstream::in | fstream::out | fstream::trunc);
        for (int i = 0; i < 10; i++) {
            inputFile >> highScores[i];
        }
        inputFile.close();
    }
    
    
}

void highscore::addScore(double time)
{
    highScores[9] = time;
    sort(highScores, highScores + 11);
}

void highscore::readScore()
{
    ofstream outputFile("Highscore.txt", ios::trunc);
    for (short int i = 10; i > 0; i--) {
        outputFile << this->highScores[i] << endl;
        cout << this->highScores[i] << endl;
    }
    outputFile.close();
}
