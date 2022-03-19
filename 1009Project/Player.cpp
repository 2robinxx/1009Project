#include "Player.h"

// Constructors / Destructors
Player::Player(int player) {
	if (player == 1) {
		initSprite(1);
		x = 300.f;
		y = 100.f;
		leftKeyPressed = sf::Keyboard::Key::A;
		rightKeyPressed = sf::Keyboard::Key::D;
		jumpKeyPressed = sf::Keyboard::Key::W;
		direction = "right";
		initHitbox();
	}
	else if (player == 2) {
		initSprite(2);
		x = 400.f;
		y = 100.f;
		leftKeyPressed = sf::Keyboard::Key::J;
		rightKeyPressed = sf::Keyboard::Key::L;
		jumpKeyPressed = sf::Keyboard::Key::I;
		direction = "left";
		initHitbox();
	}

	speed = 4;
	jumpSpeed = 8;
	fallSpeed = 8;
	jumpTo = 0;
	spriteNum = 1;
	isCollidingFeet = false;
}

Player::~Player() {
	cout << "Player destroyed" << endl;
}

//Functions
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

void Player::initHitbox() {
	sprite = sf::RectangleShape(sf::Vector2f(48.f, 48.f));
	sprite.setPosition(x, y);
	sprite.setTexture(&idleSprite);
}

//Control player's movements
void Player::setMovement() {

	if (isFalling == true || isJumping == false) {

		if (isCollidingFeet == false) {
			y += fallSpeed;
			isFalling = true;
		}
		else if (isCollidingFeet == true) {
			isFalling = false;
		}

	}

	if (isJumping == true) {
		if (y > jumpTo) {
			y -= jumpSpeed;
		}

		if (y <= jumpTo || isCollidingHead == true) {
			isJumping = false;
			isFalling = true;
		}
	}

	if (sf::Keyboard::isKeyPressed(leftKeyPressed) && !sf::Keyboard::isKeyPressed(rightKeyPressed)) {
		direction = "left";
		setSprite("left");
		if (isColliding == false) {
			x = x - speed;
		}
	}
	if (sf::Keyboard::isKeyPressed(rightKeyPressed) && !sf::Keyboard::isKeyPressed(leftKeyPressed)) {
		direction = "right";
		setSprite("right");
		if (isColliding == false) {
			x = x + speed;
		}
	}
	if (sf::Keyboard::isKeyPressed(jumpKeyPressed)) {
		if (isJumping == false && isFalling == false) {
			jumpTo = y - (48 * 4);
			isJumping = true;
		}
	}
}

// Interfaces
sf::RectangleShape Player::getSprite() {
	return sprite;
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

void Player::setPosition() {
	sprite.setPosition(x, y);
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

void Player::setCollidingFeet(bool isCollidingFeet) {
	this->isCollidingFeet = isCollidingFeet;
}

bool Player::getCollidingFeet() {
	return isCollidingFeet;
}

void Player::setCollidingHead(bool isCollidingHead) {
	this->isCollidingHead = isCollidingHead;
}

bool Player::getCollidingHead() {
	return isCollidingHead;
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