#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

using namespace std;

//Object to be inherited by Player and Mobs.
class Bat : public Entity{
protected:
	int damage;
	string verticalDirection;
public:
	//Constructor/Destructor
	Bat(float, float);
	Bat(float, float, float, float);
	~Bat();

	//Functions
	void setMovement();
	void initSprite();

	//Interfaces
	void setDamage(int);
	int getDamage();
};
