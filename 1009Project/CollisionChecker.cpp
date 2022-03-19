#include "CollisionChecker.h"
#include <iostream>

CollisionChecker::CollisionChecker(TileManager* tileManager) {
	this->tileManager = tileManager;
}

void CollisionChecker::checkTile(Player* player) {
	int leftCol = player->getX() / 48;
	int rightCol = (player->getX() + 48) / 48;
	int topRow = player->getY() / 48;
	int bottomRow = (player->getY() + 48) / 48;

	if (tileManager->tiles[bottomRow][leftCol]->collision == true || tileManager->tiles[bottomRow][rightCol]->collision == true) {
		player->setCollisionOnFeet(1);
	}
	else {
		player->setCollisionOnFeet(0);
	}

	if (player->getJumping() == true) {

	}
	else if (player->getFalling() == true) {
		if (player->getDirection() == "left") {

		}
		else if (player->getDirection() == "right"){
		}
	}
	else {

	}
}