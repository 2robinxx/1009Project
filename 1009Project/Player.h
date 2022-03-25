#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Sound.h"

using namespace std;

//Object for player 1 and 2.
class Player : public Entity {
private:
	int jumpTo;
	int slideLeftTimer = 0, slideRightTimer = 0;
	bool isFalling, isJumping, isColliding, isCollidingFeet, isCollidingHead, isSliding;
	int health = 3;

	sf::Keyboard::Key leftKeyPressed, rightKeyPressed, jumpKeyPressed;

public:
	//Constructor/Destructor
	Sound sound;
	Player(int);
	~Player();

	//Functions
	void initSprite(int);
	void setMovement();
	void doSlide();

	void setSpeed(int);
	void setDamage(int);
	void gainHealth(int);


	//Interfaces
	void setCollidingFeet(bool);
	bool getCollidingFeet();
	void setCollidingHead(bool);
	bool getCollidingHead();
	void setFalling(bool);
	bool getFalling();
	void setJumping(bool);
	bool getJumping();
	void setColliding(bool);
	bool getColliding();
	void setSliding(bool);
	bool getSliding();
	void setDirection(string);
	string getDirection();
	int getHealth();

	void playJumpSound();
};
