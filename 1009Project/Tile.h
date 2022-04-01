#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

//Object for each individual tiles in the game.
class Tile {
private:
	bool collision, sliding;
	sf::Vector2f position;
	sf::Texture texture;
	sf::RectangleShape sprite;

public:

	//Constructor/Destructor
	Tile(string, bool, bool);
	Tile(string, float, float, bool, bool);
	~Tile();

	//Functions
	void setUpSprite(string);
	void setPosition(float, float);

	//Interfaces
	bool getCollision();
	bool getSliding();
	sf::RectangleShape getSprite();
};
