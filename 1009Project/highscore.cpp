#include "highscore.h"

using namespace std;

void highscore::addFile()
{

    fstream inputFile("Highscore.txt");

    if (!inputFile) {
        inputFile.open("Highscore.txt", fstream::in | fstream::out | fstream::trunc);

        for (int i = 1; i < 12; i++) {
            inputFile << "0" << endl;
        }
        inputFile.close();
    }

    for (int i = 0; i < 11; i++) {
        inputFile >> highScores[i];
    }
    inputFile.close();


}




void highscore::addScore(double time)
{
    highScores[10] = time;
    int n = sizeof(highScores) / sizeof(highScores[11]);
    sort(highScores, highScores + 11);
}


void highscore::readScore()
{
    ofstream outputFile("Highscore.txt", ios::trunc);
    for (int i = 0; i <=10; i++) {
        if (highScores[i] != 0) {
            outputFile << highScores[i] << endl;
        }
                
    }
    
    outputFile.close();
}
void highscore::writeScore() {
    int i = 0;
    for (int i = 0; i < 10; i++) {
        if (highScores[i] != 0) {
            cout << i << ") " << highScores[i] << endl;
        }
    }
}
