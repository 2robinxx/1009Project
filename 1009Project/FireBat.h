#pragma once
#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Player.h"

using namespace std;

class FireBall;

//Object to be inherited by Player and Mobs.
class FireBat : public Bat {
private:
	Player* player;
	FireBall* fireball;
	int fireSpeed;
	time_t idleTimer, restTimer;
	bool isIdle, isRest;

public:
	//Constructor/Destructor
	FireBat(float, float, Player*);
	FireBat(float, float, float, float, Player*);
	~FireBat();

	//Functions
	void setMovement();
	void setAttack();
	void initSprite();

	//Interfaces
	FireBall* getFireball();
	void setDamage(int);
	int getDamage();
};

class FireBall : public Entity {
public:
	//Constructor/Destructor
	FireBall(float, float, string);
	~FireBall();

	//Functions
	void setMovement();
	void initSprite();
};
#pragma once
