#pragma once
#include "SFML/Graphics.hpp"

#define itemSelection 2

class MapSelection
{

private:

	sf::Font font;
	sf::Text option[itemSelection];
	sf::Text pageTitle;
	sf::Keyboard::Key upPress, downPress, enterPress;

public:

	MapSelection();

	int enterPressKey;
	int selectedItemIndex;

	void draw(sf::RenderTarget& target, int height, int width);
	void drawTitle(sf::RenderTarget& target);
	void MoveUp();
	void MoveDown();
	int toggleMenu();

};