#include "Entity.h"

//Constructors / Destructors
Entity::Entity() {
	speed = 4;
	verticalSpeed = 8;
	x = 0;
	y = 0;
	width = 48.f;
	height = 48.f;
	spriteNum = 1;
	spriteCounter = 0;
	direction = "left";
}

Entity::~Entity() {
	cout << "Entity destroyed." << endl;
}

//Functions
//Initialize the hitbox for entities
void Entity::initHitbox() {
	sprite = sf::RectangleShape(sf::Vector2f(width, height));
	sprite.setPosition(x, y);
	sprite.setTexture(&idleSprite);
}

//Set the sprite animation for entity
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

//Interfaces
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