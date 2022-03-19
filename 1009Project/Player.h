#pragma once
#include <SFML/Graphics.hpp>

#ifndef PLAYER
#define PLAYER

using namespace std;

class Player {
private:
	sf::Texture idleSprite, leftSprite1, leftSprite2, rightSprite1, rightSprite2;
	sf::RectangleShape hitbox;

	float x, y;
	int spriteCounter, spriteNum, speed, fallSpeed, jumpSpeed;
	bool isFalling, isJumping, isColliding;
	int isCollidingFeet;
	string direction;

	sf::Keyboard::Key leftKeyPressed, rightKeyPressed, jumpKeyPressed;
public:
	Player();
	Player(int);

	void initSprite(int);
	void initHitbox();

	sf::RectangleShape getPlayer();
	void setPosition();
	void setSprite(string);
	void setX(float);
	float getX();
	void setY(float);
	float getY();
	float getSpeed();
	void setCollisionOnFeet(int);
	int getCollisionOnFeet();
	void setFalling(bool);
	bool getFalling();
	void setJumping(bool);
	bool getJumping();
	void setColliding(bool);
	bool getColliding();
	void setDirection(string);
	string getDirection();
	void setMovement();
};

#endif
