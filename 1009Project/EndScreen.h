#pragma once
#include "SFML/Graphics.hpp"
#define itemSelection 3

class EndScreen
{
private:
	
	sf::Font font;
	sf::Text option[itemSelection];
	sf::Text statement;

	sf::Keyboard::Key upPress, downPress, enterPress;


public:

	EndScreen();
	int enterPressKey;
	int playerwon;
	int selectedItemIndex;
	void draw(sf::RenderTarget& target, int height, int width);
	void MoveUp();

	void MoveDown();

	int toggleMenu();
};




