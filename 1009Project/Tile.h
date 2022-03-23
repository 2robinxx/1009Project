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
	Tile();
	Tile(string, bool, bool);
	Tile(string, float, float, bool, bool);
	~Tile();

	//Interfaces
	void setUpSprite(string);
	bool getCollision();
	bool getSliding();
	void setPosition(float, float);
	sf::RectangleShape getSprite();
};
