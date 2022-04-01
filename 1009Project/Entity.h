#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef GRID_HEIGHT
	#define GRID_HEIGHT 50
#endif

#ifndef GRID_WIDTH
	#define GRID_WIDTH 16
#endif

#ifndef WORLD_HEIGHT
	#define WORLD_HEIGHT 2400
#endif

#ifndef WORLD_WIDTH
	#define WORLD_WIDTH 768
#endif

using namespace std;

//Object to be inherited by Player and Mobs.
class Entity {
protected:
	//Variables
	sf::Texture idleSprite, leftSprite1, leftSprite2, rightSprite1, rightSprite2;
	sf::RectangleShape sprite;
	float x, y, width, height;
	int spriteCounter, spriteNum, speed, verticalSpeed;
	string direction;

public:
	//Constructor/Destructor
	Entity();
	~Entity();

	//Functions
	void initHitbox();
	void setSprite(string);

	//Interfaces
	sf::RectangleShape getSprite();
	void setPosition();
	void setX(float);
	float getX();
	void setY(float);
	float getY();
	float getSpeed();
};
