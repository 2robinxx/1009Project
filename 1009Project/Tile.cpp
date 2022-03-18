#include "Tile.h"

Tile::Tile() {

}

Tile::Tile(string path, bool collision, bool sliding) {
	setUpSprite(path);
	this->collision = collision;
	this->sliding = sliding;
}

Tile::Tile(string path, float x, float y, bool collision, bool sliding) {
	setUpSprite(path);
	pos = sf::Vector2f(x, y);
	sprite.setPosition(pos);
	this->collision = collision;
	this->sliding = sliding;
}

bool Tile::setUpSprite(string path) {
	texture.loadFromFile(path);
	texture.setSmooth(true);
	sprite = sf::RectangleShape(sf::Vector2f(48.f, 48.f));
	sprite.setTexture(&texture);
	return true;
}

void Tile::setPos(float x, float y) {
	pos = sf::Vector2f(x, y);
	sprite.setPosition(pos);
}