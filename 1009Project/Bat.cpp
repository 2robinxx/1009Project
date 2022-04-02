#include "Bat.h"

//Constructors / Destructors
Bat::Bat(float width, float height) {
	this->width = width;
	this->height = height;
	x = 0;
	y = 0;
	speed = 4;
	verticalSpeed = 2;
	initSprite();
	initHitbox();
}

Bat::Bat(float width, float height, float x, float y) {
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;
	speed = 4;
	verticalSpeed = 2;
	initSprite();
	initHitbox();
}

Bat::~Bat() {
	cout << "Bat destroyed." << endl;
}

//Functions
//Set the movement pattern for bats
void Bat::setMovement() {
	if (x <= 0) {
		direction = "right";
	}
	else if (x >= (WORLD_WIDTH - 48)) {
		direction = "left";
	}

	if (y <= 0) {
		verticalDirection = "down";
	}
	else if (y >= (WORLD_HEIGHT - 48)) {
		verticalDirection = "up";
	}

	if (direction == "left") {
		x -= speed;
		setSprite("left");
		if (x < 0) {
			throw "Bat exceeded map limit.";
		}
	}
	else if (direction == "right") {
		x += speed;
		setSprite("right");
		if (x > WORLD_WIDTH) {
			throw "Bat exceeded map limit.";
		}
	}

	if (verticalDirection == "down") {
		y += verticalSpeed;
		if (y > WORLD_HEIGHT) {
			throw "Bat exceeded map limit.";
		}
	}
	else if (verticalDirection == "up") {
		y -= verticalSpeed;
		if (y < 0) {
			throw "Bat exceeded map limit.";
		}
	}
}

//Initialize the sprites for bat
void Bat::initSprite() {
	idleSprite.loadFromFile("Sprites/mob/bat_left_1.png");
	leftSprite1.loadFromFile("Sprites/mob/bat_left_1.png");
	leftSprite2.loadFromFile("Sprites/mob/bat_left_2.png");
	rightSprite1.loadFromFile("Sprites/mob/bat_right_1.png");
	rightSprite2.loadFromFile("Sprites/mob/bat_right_2.png");
}

// Interfaces
void Bat::setDamage(int damage) {
	this->damage = damage;
}

int Bat::getDamage() {
	return damage;
}