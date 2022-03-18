#include "CollisionChecker.h"
#include <iostream>

CollisionChecker::CollisionChecker(TileManager* tileManager) {
	this->tileManager = tileManager;
}

void CollisionChecker::checkTile(Player player) {
	float leftCol = player.getX() / 48;
	float rightCol = (player.getX() + 48) / 48;
	float topRow = player.getY() / 48;
	float bottomRow = (player.getY() + 48) / 48;
	if (tileManager->tiles[bottomRow][leftCol]->collision == true || tileManager->tiles[bottomRow][rightCol]->collision == true) {
		player.setCollisionOnFeet(true);
	}
}