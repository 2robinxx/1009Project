#include "highscore.h"

using namespace std;

void highscore::addFile()
{

    fstream inputFile("Highscore.txt");

    if (!inputFile) {
        inputFile.open("Highscore.txt", fstream::in | fstream::out | fstream::trunc);

        for (int i = 1; i < 10; i++) {
            inputFile << "0" << endl;
        }
        inputFile.close();
    }

    for (int i = 0; i < 9; i++) {
        inputFile >> setprecision(3) >>highScores[i];
    }
    inputFile.close();


}

void highscore::addScore(double time)
{
    highScores[9] = round(time);
    int n = sizeof(highScores) / sizeof(highScores[11]);
    sort(highScores, highScores + 10);
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
      cout << i << ") " << highScores[i] << endl;
    }
    
}

void highscore::draw(sf::RenderTarget& target, int height, int width)
{
    int x = 100;
    int j = 1;
    if (!font.loadFromFile("Fonts/game_sans_serif_7.ttf"))
    {

        // error handling if file not loaded
    }
    for (int i = 0; i <10; i++) {
        //cout << "I am inside the loop";
        score[i].setFont(font);
        if (highScores[i] != 0) {
            int hs = round(highScores[i]);
            string test = to_string(j)+") " + to_string(hs)+" Seconds";
            score[i].setFillColor(sf::Color::White);
            score[i].setString(test);
            score[i].setCharacterSize(50);
            score[i].setPosition(sf::Vector2f((width / 5.f), height / (11) + x));
            x += 60;
            j++;
            target.draw(score[i]);
        }
    }
}
