#pragma once
#include <SFML/Graphics.hpp>

#ifndef TILE
#define TILE

using namespace std;

class Tile {
public:
	bool collision, sliding;

	sf::Vector2f pos;
	sf::Texture texture;
	sf::RectangleShape sprite;

	Tile();
	Tile(string, bool, bool);
	Tile(string, float, float, bool, bool);
	bool setUpSprite(string);
	void setPos(float, float);
};

#endif
