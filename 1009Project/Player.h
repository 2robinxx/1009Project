#pragma once
#include <SFML/Graphics.hpp>

#ifndef PLAYER
#define PLAYER

using namespace std;

class Player {
private:
	sf::Texture idleSprite, leftSprite1, leftSprite2, rightSprite1, rightSprite2;
	sf::RectangleShape hitbox;

	float x, y, speed, fallSpeed, jumpSpeed;
	int spriteCounter, spriteNum;
	bool collisionOnFeet, isFalling, isJumping;
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
	void setCollisionOnFeet(bool);
	bool getCollisionOnFeet();
	void setFalling(bool);
	bool getFalling();
	void setJumping(bool);
	bool getJumping();
};

#endif
