#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Sound.h"

using namespace std;

//Object for player 1 and 2.
class Player : public Entity {
private:
	//Variables
	int jumpTo;
	int slideLeftTimer = 0, slideRightTimer = 0;
	bool isFalling, isJumping, isColliding, isCollidingFeet, isCollidingHead, isSliding, isImmune;
	int health = 3;
	time_t immunityTimer;
	sf::Keyboard::Key leftKeyPressed, rightKeyPressed, jumpKeyPressed;

	//Objects
	Sound sound;

public:
	//Constructor/Destructor
	Player(int);
	~Player();

	//Functions
	void initSprite(int);
	void setMovement();
	void doSlide();
	void checkImmune();
	inline void playJumpSound();
	void gainHealth();
	void gainHealth(int);
	void deductHealth();
	void deductHealth(int);

	//Operator overload
	bool operator>(Entity&);
	bool operator>=(Entity&);
	bool operator<(Entity&);
	bool operator<=(Entity&);
	bool operator>(float);
	bool operator>=(float);
	bool operator<(float);
	bool operator<=(float);

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
	void setImmune();
	bool getImmune();
	int getHealth();
	void setSpeed(int);
	void setDamage(int);
};
