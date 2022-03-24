#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Boots
{
private:
	sf::CircleShape sprite;

	
public:
	Boots(const sf::RenderWindow& window);
	virtual ~Boots();

	const sf::CircleShape getBoots() const;


	//Function
	void update();
	void render(sf::RenderTarget& target);

	void initObject(const sf::RenderWindow& window);

};
