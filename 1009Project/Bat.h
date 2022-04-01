#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

using namespace std;

//Bat monster object.
class Bat : public Entity{
protected:
	//Variables
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
