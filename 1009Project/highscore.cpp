#include "highscore.h"

using namespace std;






void highscore::addFile()
{

    fstream inputFile("Highscore.txt");

    if (!inputFile) {
        inputFile.open("Highscore.txt", fstream::in | fstream::out | fstream::trunc);

        for (short int i = 0; i < 11; i++) {
            inputFile << "0" << endl;
        }
        inputFile.close();
    }

    else {
        for (short int i = 0; i < 10; i++) {
            inputFile >> highScores[i];
        }
    inputFile.close();
    }
   
}
    
    


void highscore::addScore(double time)
{
    highScores[10] = time;
    sort(highScores , highScores+11);
}

void highscore::readScore()
{
    ofstream outputFile("Highscore.txt", ios::trunc);
    for (short int i = 1; i <= 10; i++) {
        outputFile  << highScores[i] << endl;
        cout << i << ") "<<highScores[i] << endl;
    }
    outputFile.close();
}
