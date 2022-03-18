#include "Player.h"
#include <iostream>

// Constructors / Destructors
Player::Player() {

}

Player::Player(int player) {
	if (player == 1) {
		initSprite(1);
		x = 103.f;
		y = 103.f;
		leftKeyPressed = sf::Keyboard::Key::A;
		rightKeyPressed = sf::Keyboard::Key::D;
		jumpKeyPressed = sf::Keyboard::Key::W;
		direction = "right";
		initHitbox();
	}
	else if (player == 2) {
		initSprite(2);
		x = 206.f;
		y = 206.f;
		leftKeyPressed = sf::Keyboard::Key::J;
		rightKeyPressed = sf::Keyboard::Key::L;
		jumpKeyPressed = sf::Keyboard::Key::I;
		direction = "left";
		initHitbox();
	}

	speed = 4;
	jumpSpeed = 8;
	fallSpeed = 8;
	spriteNum = 1;
	collisionOnFeet = false;
}


void Player::initHitbox() {
	hitbox = sf::RectangleShape(sf::Vector2f(100.f, 100.f));
	hitbox.setScale(0.5f, 0.5f);
	hitbox.setPosition(x, y);
	hitbox.setTexture(&idleSprite);
}

void Player::initSprite(int player) {
	if (player == 1) {
		idleSprite.loadFromFile("Sprites/player/dino_idle.png");
		leftSprite1.loadFromFile("Sprites/player/dino_left_1.png");
		leftSprite2.loadFromFile("Sprites/player/dino_left_2.png");
		rightSprite1.loadFromFile("Sprites/player/dino_right_1.png");
		rightSprite2.loadFromFile("Sprites/player/dino_right_2.png");
	}
	else if (player == 2) {
		idleSprite.loadFromFile("Sprites/player/dino2_idle.png");
		leftSprite1.loadFromFile("Sprites/player/dino2_left_1.png");
		leftSprite2.loadFromFile("Sprites/player/dino2_left_2.png");
		rightSprite1.loadFromFile("Sprites/player/dino2_right_1.png");
		rightSprite2.loadFromFile("Sprites/player/dino2_right_2.png");
	}
}

// Setters / Getters
sf::RectangleShape Player::getPlayer() {
	return hitbox;
}

void Player::setSprite(string direction) {
	spriteCounter++;
	if (spriteCounter > 15) {
		if (spriteNum == 1) {
			spriteNum = 2;
		}
		else if (spriteNum == 2){
			spriteNum = 1;
		}
		spriteCounter = 0;
	}
	if (direction == "left") {
		if (spriteNum == 1) {
			hitbox.setTexture(&leftSprite1);
		}
		else if (spriteNum == 2) {
			hitbox.setTexture(&leftSprite2);
		}
	}
	if (direction == "right") {
		if (spriteNum == 1) {
			hitbox.setTexture(&rightSprite1);
		}
		else if (spriteNum == 2) {
			hitbox.setTexture(&rightSprite2);
		}
	}
}

void Player::setPosition() {
	hitbox.setPosition(x, y);
}

void Player::setX(float x) {
	this->x = x;
}

void Player::setY(float y) {
	this->y = y;
}

float Player::getX() {
	return x;
}

float Player::getY() {
	return y;
}

float Player::getSpeed() {
	return speed;
}

void Player::setCollisionOnFeet(bool collisonOnFeet) {
	this->collisionOnFeet = collisionOnFeet;
}

bool Player::getCollisionOnFeet() {
	return collisionOnFeet;
}

void Player::setFalling(bool isFalling) {
	this->isFalling = isFalling;
}

bool Player::getFalling() {
	return isFalling;
}

void Player::setJumping(bool isJumping) {
	this->isJumping = isJumping;
}

bool Player::getJumping() {
	return isJumping;
}

void Player::setColliding(bool isColliding) {
	this->isColliding = isColliding;
}

bool Player::getColliding() {
	return isColliding;
}

void Player::setDirection(string direction) {
	this->direction = direction;
}

string Player::getDirection() {
	return direction;
}

void Player::setMovement() {
	if (isFalling == true || isJumping == false) {
		
		if (collisionOnFeet == false) {
			y += fallSpeed;
			isFalling = true;
		}
		else {
			isFalling = false;
		}

	}

	if (sf::Keyboard::isKeyPressed(leftKeyPressed)) {
		x = x - speed;
		setSprite("left");
		direction = "left";
	}
	if (sf::Keyboard::isKeyPressed(rightKeyPressed)) {
		x = x + speed;
		setSprite("right");
		direction = "right";
	}
}