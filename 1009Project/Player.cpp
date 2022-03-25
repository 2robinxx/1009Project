#include "Player.h"

// Constructors / Destructors
Player::Player(int player) {
	if (player == 1) {
		initSprite(1);
		x = 60.f;
		y = 600.f;
		leftKeyPressed = sf::Keyboard::Key::A;
		rightKeyPressed = sf::Keyboard::Key::D;
		jumpKeyPressed = sf::Keyboard::Key::W;
		direction = "right";
	}
	else if (player == 2) {
		initSprite(2);
		x = 500.f;
		y = 600.f;
		leftKeyPressed = sf::Keyboard::Key::J;
		rightKeyPressed = sf::Keyboard::Key::L;
		jumpKeyPressed = sf::Keyboard::Key::I;
		direction = "left";
	}

	width = 58.f;
	height = 48.f;
	speed = 4;
	verticalSpeed = 8;
	jumpTo = 0;
	isCollidingFeet = false;
	initHitbox();
}

Player::~Player() {
	cout << "Player destroyed" << endl;
}

// Functions
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

//Control player's movements
void Player::setMovement() {

	if (isFalling == true || isJumping == false) {
		if (isCollidingFeet == false) {
			y += verticalSpeed;
			isFalling = true;
		}
		else if (isCollidingFeet == true) {
			isFalling = false;
		}
	}

	if (isJumping == true) {
		if (y > jumpTo) {
			y -= verticalSpeed;
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
		slideLeftTimer = 0;
		slideRightTimer = 0;
	}
	if (sf::Keyboard::isKeyPressed(rightKeyPressed) && !sf::Keyboard::isKeyPressed(leftKeyPressed)) {
		direction = "right";
		setSprite("right");
		if (isColliding == false) {
			x = x + speed;
		}
		slideLeftTimer = 0;
		slideRightTimer = 0;
	}
	if (sf::Keyboard::isKeyPressed(jumpKeyPressed)) {
		if (isJumping == false && isFalling == false) {
			jumpTo = y - (48 * 4);
			isJumping = true;
		}
	}
	if (isSliding == true) {
		doSlide();
	}
}

void Player::doSlide() {
	if (sf::Keyboard::isKeyPressed(leftKeyPressed) && !sf::Keyboard::isKeyPressed(rightKeyPressed)) {
		slideLeftTimer = 40;
		slideRightTimer = 0;
	}
	else {
		if (slideLeftTimer > 0) {
			x -= 2;
			slideLeftTimer -= 1;
		}
	}
	if (sf::Keyboard::isKeyPressed(rightKeyPressed) && !sf::Keyboard::isKeyPressed(leftKeyPressed)) {
		slideRightTimer = 40;
		slideLeftTimer = 0;
	}
	else {
		if (slideRightTimer > 0) {
			x += 2;
			slideRightTimer -= 1;
		}
	}
}

// Interfaces
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

void Player::setSliding(bool isSliding) {
	this->isSliding = isSliding;
}

bool Player::getSliding() {
	return isSliding;
}

void Player::setDirection(string direction) {
	this->direction = direction;
}

string Player::getDirection() {
	return direction;
}

void Player::setSpeed(int s) {
	this->speed += s;
}

