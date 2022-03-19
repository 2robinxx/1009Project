#include "Tile.h"

//Constructors/Destructors
Tile::Tile() {

}

Tile::Tile(string path, bool collision, bool sliding) {
	setUpSprite(path);
	this->collision = collision;
	this->sliding = sliding;
}

Tile::Tile(string path, float x, float y, bool collision, bool sliding) {
	setUpSprite(path);
	position = sf::Vector2f(x, y);
	sprite.setPosition(position);
	this->collision = collision;
	this->sliding = sliding;
}

Tile::~Tile() {
	cout << "Tile destroyed." << endl;
}

//Interfaces
bool Tile::setUpSprite(string path) {
	texture.loadFromFile(path);
	texture.setSmooth(true);
	sprite = sf::RectangleShape(sf::Vector2f(48.f, 48.f));
	sprite.setTexture(&texture);
	return true;
}

bool Tile::getCollision() {
	return collision;
}

bool Tile::getSliding() {
	return sliding;
}

void Tile::setPosition(float x, float y) {
	position = sf::Vector2f(x, y);
	sprite.setPosition(position);
}

sf::RectangleShape Tile::getSprite() {
	return sprite;
}