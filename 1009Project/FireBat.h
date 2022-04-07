#pragma once
#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Player.h"

using namespace std;

class FireBall;

//Object of a special type of bat that shoots fireballs
class FireBat : public Bat {
private:
	//Variables
	int fireSpeed;
	time_t idleTimer, restTimer;
	bool isIdle, isRest;

	//Object pointers
	Player* player;
	FireBall* fireball;

public:
	//Constructor/Destructor
	FireBat(float, float, Player*);
	FireBat(float, float, float, float, Player*);
	~FireBat();

	//Functions
	void setMovement();
	inline void setAttack();
	void initSprite();

	//Interfaces
	FireBall* getFireball();
	void setDamage(int);
	int getDamage();
};

//Object of fireball projectiles that FireBat fires
class FireBall : public Entity {
public:
	//Constructor/Destructor
	FireBall(float, float, string);
	~FireBall();

	//Functions
	inline void setMovement();
	void initSprite();
	friend void checkFireCollision(Player&, FireBall&);
};
#pragma once
