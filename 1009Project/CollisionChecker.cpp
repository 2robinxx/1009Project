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
		player->setCollidingFeet(true);
	}
	else {
		player->setCollidingFeet(false);
	}

	if (player->getJumping() == true) {
		if (tileManager->tiles[topRow][leftCol]->collision == true || tileManager->tiles[topRow][rightCol]->collision == true) {
			player->setCollidingHead(true);
		}
		else {
			player->setCollidingHead(false);
		}
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