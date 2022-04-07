#pragma once
#include "SFML/Graphics.hpp"
#include "highscore.h"

class highscoreScreen
{
private:
	sf::Font font;
	sf::Text Title;
	sf::Text score[9];
	sf::Keyboard::Key upPress, downPress, enterPress;
	highscore hs;
	

public:
	highscoreScreen();
	void readScore();
	void checkFile();
	
	void drawTitle(sf::RenderTarget& target);
	double highScores[9];
};

