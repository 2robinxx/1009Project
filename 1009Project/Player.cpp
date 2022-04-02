#include "Player.h"

//Constructors / Destructors
Player::Player(int player) {
	if (player == 1) {
		initSprite(1);
		x = 300.f;
		y = 400.f;
		leftKeyPressed = sf::Keyboard::Key::A;
		rightKeyPressed = sf::Keyboard::Key::D;
		jumpKeyPressed = sf::Keyboard::Key::W;
		direction = "right";
	}
	else if (player == 2) {
		initSprite(2);
		x = 400.f;
		y = 400.f;
		leftKeyPressed = sf::Keyboard::Key::J;
		rightKeyPressed = sf::Keyboard::Key::L;
		jumpKeyPressed = sf::Keyboard::Key::I;
		direction = "left";
	}

	width = 48.f;
	height = 48.f;
	speed = 4;
	verticalSpeed = 8;
	jumpTo = 0;

	isImmune = false;
	isCollidingFeet = false;
	immunityTimer = 0;
	isColliding = false;
	isCollidingHead = false;
	isFalling = false;
	isJumping = false;
	isSliding = false;

	initHitbox();
}

Player::~Player() {
	cout << "Player destroyed." << endl;
}


//Functions
//Initialize sprites for players
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

	//Falling function
	if (isFalling == true || isJumping == false) {
		if (isCollidingFeet == false) {
			y += verticalSpeed;
			isFalling = true;
			if (y > WORLD_HEIGHT) {
				throw "Player exceeded map limit.";
			}
		}
		else if (isCollidingFeet == true) {
			isFalling = false;
		}
	}

	//Jump function
	if (isJumping == true) {
		if (y > jumpTo) {
			y -= verticalSpeed;
			if (y < 0) {
				throw "Player exceeded map limit.";
			}
		}

		if (y <= jumpTo || isCollidingHead == true) {
			isJumping = false;
			isFalling = true;
		}
	}

	//Left,Right and Jumping function
	if (sf::Keyboard::isKeyPressed(leftKeyPressed) && !sf::Keyboard::isKeyPressed(rightKeyPressed)) {
		direction = "left";
		setSprite("left");
		if (isColliding == false) {
			x = x - speed;
			if (x < 0) {
				throw "Player exceeded map limit.";
			}
		}
		slideLeftTimer = 0;
		slideRightTimer = 0;
	}
	if (sf::Keyboard::isKeyPressed(rightKeyPressed) && !sf::Keyboard::isKeyPressed(leftKeyPressed)) {
		direction = "right";
		setSprite("right");
		if (isColliding == false) {
			x = x + speed;
			if (x > WORLD_WIDTH) {
				throw "Player exceeded map limit.";
			}
		}
		slideLeftTimer = 0;
		slideRightTimer = 0;
	}
	if (sf::Keyboard::isKeyPressed(jumpKeyPressed)) {
		if (isJumping == false && isFalling == false) {

			jumpTo = y - (48 * 4);
			isJumping = true;

			playJumpSound();
		}
	}

	//Sliding function
	if (isSliding == true) {
		doSlide();
	}
}

//Sliding function
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

//Function to check if immunity expired
void Player::checkImmune() {
	if (time(NULL) >= immunityTimer) {
		isImmune = false;
	}
}

//Play jumping sound
inline void Player::playJumpSound() {
	sound.setBuffer("Sprites/sound/coin.wav");
	sound.playSound();
}

//Increase player health
void Player::gainHealth()
{
	health += 1;
}

//Increase player health
void Player::gainHealth(int h)
{
	if (health > 3)
	{
		health = 3;
	}
	else
	{
		health += h;
	}
}

//Deduct player health
void Player::deductHealth() {
	health -= 1;
}

void Player::deductHealth(int h) {
	health = health - h;
}


//Operator overload. Compare player's height
bool Player::operator>(Entity& entity) {
	return this->getY() > entity.getY();
}

bool Player::operator>=(Entity& entity) {
	return this->getY() >= entity.getY();
}

bool Player::operator<(Entity& entity) {
	return this->getY() < entity.getY();
}

bool Player::operator<=(Entity& entity) {
	return this->getY() <= entity.getY();
}

bool Player::operator>(float y) {
	return this->getY() > y;
}

bool Player::operator>=(float y) {
	return this->getY() >= y;
}

bool Player::operator<(float y) {
	return this->getY() < y;
}

bool Player::operator<=(float y) {
	return this->getY() <= y;
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

void Player::setImmune() {
	isImmune = true;
	immunityTimer = time(NULL) + 1;
}

bool Player::getImmune() {
	return isImmune;
}

int Player::getHealth() {
	return health;
}

void Player::setSpeed(int s)
{
	this->speed += s;
}

void Player::setDamage(int d)
{
	this->health -= d;
}