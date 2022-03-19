#include "CollisionChecker.h"

//Constructor/Destructor
CollisionChecker::CollisionChecker(TileManager* tileManager) {
	this->tileManager = tileManager;
}

CollisionChecker::~CollisionChecker() {
	cout << "CollisionChecker destroyed." << endl;
}

//Functions
//Check whether the player collide with a tile.
void CollisionChecker::checkTileCollision(Player* player) {
	int leftCol = player->getX() / 48;
	int rightCol = (player->getX() + 48) / 48;
	int topRow = player->getY() / 48;
	int bottomRow = (player->getY() + 48) / 48;

	if (tileManager->tiles[bottomRow][leftCol]->getCollision() == true || tileManager->tiles[bottomRow][rightCol]->getCollision() == true) {
		player->setCollidingFeet(true);
	}
	else {
		player->setCollidingFeet(false);
	}

	if (player->getJumping() == true) {
		topRow = (player->getY() - player->getSpeed()) / 48;
		bottomRow = (player->getY() + 48 - player->getSpeed()) / 48;

		if (tileManager->tiles[topRow][leftCol]->getCollision() == true || tileManager->tiles[topRow][rightCol]->getCollision() == true) {
			player->setCollidingHead(true);
		}
		else {
			player->setCollidingHead(false);
		}

		if (player->getDirection() == "left") {
			leftCol = (player->getX() - player->getSpeed()) / 48;

			if (tileManager->tiles[topRow][leftCol]->getCollision() == true || tileManager->tiles[bottomRow][leftCol]->getCollision() == true) {
				player->setColliding(true);
			}
			else {
				player->setColliding(false);
			}
		}

		if (player->getDirection() == "right") {
			rightCol = (player->getX() + 48 + player->getSpeed()) / 48;

			if (tileManager->tiles[topRow][rightCol]->getCollision() == true || tileManager->tiles[bottomRow][rightCol]->getCollision() == true) {
				player->setColliding(true);
			}
			else {
				player->setColliding(false);
			}
		}
	}
	else if (player->getFalling() == true) {
		leftCol = (player->getX() - player->getSpeed()) / 48;
		rightCol = (player->getX() + 48 + player->getSpeed()) / 48;
		topRow = player->getY() / 48;
		bottomRow = (player->getY() + 48) / 48;

		if (player->getDirection() == "left") {
			if (tileManager->tiles[topRow][leftCol]->getCollision() == true || tileManager->tiles[bottomRow][leftCol]->getCollision() == true) {
				player->setColliding(true);
			}
			else {
				player->setColliding(false);
			}
		}

		if (player->getDirection() == "right") {
			if (tileManager->tiles[topRow][rightCol]->getCollision() == true || tileManager->tiles[bottomRow][rightCol]->getCollision() == true) {
				player->setColliding(true);
			}
			else {
				player->setColliding(false);
			}
		}
	}
	else {
		leftCol = (player->getX() - player->getSpeed()) / 48;
		rightCol = (player->getX() + 48 + player->getSpeed()) / 48;
		topRow = player->getY() / 48;
		bottomRow = (player->getY() + 48) / 48 - 1;

		if (player->getDirection() == "left") {
			if (tileManager->tiles[topRow][leftCol]->getCollision() == true || tileManager->tiles[bottomRow][leftCol]->getCollision() == true) {
				player->setColliding(true);
			}
			else {
				player->setColliding(false);
			}
		}

		if (player->getDirection() == "right") {
			if (tileManager->tiles[topRow][rightCol]->getCollision() == true || tileManager->tiles[bottomRow][rightCol]->getCollision() == true) {
				player->setColliding(true);
			}
			else {
				player->setColliding(false);
			}
		}
	}
}