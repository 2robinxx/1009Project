#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "TileManager.h"

#ifndef COLLISION
#define COLLISION

using namespace std;

class CollisionChecker{
public:
	TileManager* tileManager;

	CollisionChecker(TileManager*);

	void checkTile(Player);
};

#endif
