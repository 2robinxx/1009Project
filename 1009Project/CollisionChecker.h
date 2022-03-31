#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "TileManager.h"
#include "FireBat.h"
#include <iostream>

using namespace std;

//Object to check collisions within the game.
class CollisionChecker{
public:
	TileManager* tileManager;

	//Constructor/Destructor
	CollisionChecker(TileManager*);
	~CollisionChecker();

	//Functions
	void checkTileCollision(Player*);
	void checkMobCollision(Player&, Entity&);
	void checkFireCollision(Player*, FireBall*);
};
