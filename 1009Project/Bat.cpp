#include "Bat.h"

// Constructors / Destructors
Bat::Bat(float width, float height) {
	this->width = width;
	this->height = height;
	x = 0;
	y = 0;
	speed = 4;
	verticalSpeed = 2;
	direction = "right";
	spriteNum = 1;
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
	direction = "right";
	spriteNum = 1;
	initSprite();
	initHitbox();
}

Bat::~Bat() {
	cout << "Bat destroyed." << endl;
}

// Functions
void Bat::setMovement() {
	if (x <= 0) {
		direction = "right";
	}
	else if (x >= WORLD_WIDTH) {
		direction = "left";
	}

	if (y <= 0) {
		verticalDirection = "down";
	}
	else if (y >= WORLD_HEIGHT) {
		verticalDirection = "up";
	}

	if (direction == "left") {
		x -= speed;
		setSprite("left");
	}
	else if (direction == "right") {
		x += speed;
		setSprite("right");
	}

	if (verticalDirection == "down") {
		y += verticalSpeed;
	}
	else if (verticalDirection == "up") {
		y -= verticalSpeed;
	}
}

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