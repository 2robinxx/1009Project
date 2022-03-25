#include "Health.h"
#include "GamePanel.h"


sf::Sprite& Health::loadTexture(int x, int y) {

	if (!texture.loadFromFile("Sprites/object/heart_full.png")) {

		//Print error


	}

	heart.setTexture(texture);
	heart.setPosition(sf::Vector2f(x, y));

	return(heart);
}
