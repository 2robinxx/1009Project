#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include <fstream>
#include <algorithm>
#include <iomanip>

class highscore
{
private:

		sf::Font font;
		sf::Text score[10];
public:
	double highScores[10];
	void addFile();
	void addScore(double);
	void readScore();
	void writeScore();
	void draw(sf::RenderTarget& target, int height, int width);
};

