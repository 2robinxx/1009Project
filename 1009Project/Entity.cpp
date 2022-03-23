#include "Entity.h"

// Constructors / Destructors

// Functions
void Entity::initHitbox() {
	sprite = sf::RectangleShape(sf::Vector2f(width, height));
	sprite.setPosition(x, y);
	sprite.setTexture(&idleSprite);
}

// Interfaces
void Entity::setSprite(string direction) {
	spriteCounter++;
	if (spriteCounter > 15) {
		if (spriteNum == 1) {
			spriteNum = 2;
		}
		else if (spriteNum == 2) {
			spriteNum = 1;
		}
		spriteCounter = 0;
	}
	if (direction == "left") {
		if (spriteNum == 1) {
			sprite.setTexture(&leftSprite1);
		}
		else if (spriteNum == 2) {
			sprite.setTexture(&leftSprite2);
		}
	}
	if (direction == "right") {
		if (spriteNum == 1) {
			sprite.setTexture(&rightSprite1);
		}
		else if (spriteNum == 2) {
			sprite.setTexture(&rightSprite2);
		}
	}
}

sf::RectangleShape Entity::getSprite() {
	return sprite;
}

void Entity::setPosition() {
	sprite.setPosition(x, y);
}

void Entity::setX(float x) {
	this->x = x;
}

void Entity::setY(float y) {
	this->y = y;
}

float Entity::getX() {
	return x;
}

float Entity::getY() {
	return y;
}

float Entity::getSpeed() {
	return speed;
}