#pragma once
#include "SFML/Graphics.hpp"

#define itemSelection 3

class Menu
{

private:
	//int selectedItemIndex;
	sf::Font font;
	sf::Text option[itemSelection];

	sf::Keyboard::Key upPress, downPress, enterPress;


public:

	Menu();
	int enterPressKey;

	int selectedItemIndex;
	void draw(sf::RenderTarget& target, int height, int width);
	void MoveUp();

	void MoveDown();

	int toggleMenu();

};