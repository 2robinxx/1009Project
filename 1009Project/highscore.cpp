#include "highscore.h"

using namespace std;

void highscore::addFile()
{
    if (map == 0) {
        fstream inputFile("Highscore.txt");

        if (!inputFile) {
            inputFile.open("Highscore.txt", fstream::in | fstream::out | fstream::trunc);

            for (int i = 1; i < 10; i++) {
                inputFile << "0" << endl;
            }
            inputFile.close();
        }

        for (int i = 0; i < 9; i++) {
            inputFile >> setprecision(3) >> highScores[i];
        }
        inputFile.close();
    
    }
    else if (map == 1) {
        fstream inputFile("Highscore_ice.txt");

        if (!inputFile) {
            inputFile.open("Highscore_ice.txt", fstream::in | fstream::out | fstream::trunc);

            for (int i = 1; i < 10; i++) {
                inputFile << "0" << endl;
            }
            inputFile.close();
        }

        for (int i = 0; i < 9; i++) {
            inputFile >> setprecision(3) >> highScores_ice[i];
        }
        inputFile.close();
    }
}

void highscore::addScore(double time)
{
    if (map == 0) {
        highScores[9] = round(time);
        int n = sizeof(highScores) / sizeof(highScores[11]);
        sort(highScores, highScores + 10);
    }
    else if (map == 1) {
        highScores_ice[9] = round(time);
        int n = sizeof(highScores_ice) / sizeof(highScores_ice[11]);
        sort(highScores_ice, highScores_ice + 10);
    }
}


void highscore::readScore()
{
    if (map == 0) {
        ofstream outputFile("Highscore.txt", ios::trunc);
        for (int i = 0; i <= 10; i++) {
            if (highScores[i] != 0) {
                outputFile << highScores[i] << endl;
            }
        }
        outputFile.close();
    }
    else if(map==1) {
        ofstream outputFile("Highscore_ice.txt", ios::trunc);
        for (int i = 0; i <= 9; i++) {
            if (highScores_ice[i] != 0) {
                outputFile << highScores_ice[i] << endl;
            }
        }
        outputFile.close();
    }
    
}
void highscore::writeScore() {
    if (map == 0) {
        int i = 0;
        for (int i = 0; i < 10; i++) {
            cout << i << ") " << highScores[i] << endl;
        }
    }
    else if (map == 1) {
        int i = 0;
        for (int i = 0; i < 10; i++) {
            cout << i << ") " << highScores_ice[i] << endl;
        }
    }
    
    
}

void highscore::draw(sf::RenderTarget& target, int height, int width)
{
    if (map == 0) {
        int x = 100;
        int j = 1;
        if (!font.loadFromFile("Fonts/game_sans_serif_7.ttf"))
        {

            // error handling if file not loaded
        }
        for (int i = 0; i < 10; i++) {
            //cout << "I am inside the loop";
            score[i].setFont(font);
            if (highScores[i] != 0) {
                int hs = round(highScores[i]);
                string test = to_string(j) + ") " + to_string(hs) + " Seconds";
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
    else if (map == 1) {
        int x = 100;
        int j = 1;
        if (!font.loadFromFile("Fonts/game_sans_serif_7.ttf"))
        {

            // error handling if file not loaded
        }
        for (int i = 0; i < 10; i++) {
            //cout << "I am inside the loop";
            score[i].setFont(font);
            if (highScores_ice[i] != 0) {
                int hs = round(highScores_ice[i]);
                string test = to_string(j) + ") " + to_string(hs) + " Seconds";
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
        
    
    
   

   
}
