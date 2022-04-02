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

	//Tile number in the 16x50 grid for all of player's directions
	int leftCol = (player->getX() + 8) / 48;
	int rightCol = (player->getX() + 48 - 8) / 48;
	int topRow = (player->getY() + 16) / 48;
	int bottomRow = (player->getY() + 48) / 48;

	if (leftCol < 0 || rightCol >= 16 || topRow < 0 || bottomRow >= 50) {
		throw "Vector out of range";
	}

	//Check if tile is colliding the player's feet to prevent falling
	if (tileManager->tiles[bottomRow][leftCol]->getCollision() == true || tileManager->tiles[bottomRow][rightCol]->getCollision() == true) {
		player->setCollidingFeet(true);
	}
	else {
		player->setCollidingFeet(false);
	}
	//Check if tile is slidable
	if (tileManager->tiles[bottomRow][leftCol]->getSliding() == true || tileManager->tiles[bottomRow][rightCol]->getSliding() == true) {
		player->setSliding(true);
	}
	else {
		player->setSliding(false);
	}

	//Check if tile is colliding with player when jumping
	if (player->getJumping() == true) {
		topRow = (player->getY() - player->getVerticalSpeed() + 16) / 48;
		bottomRow = (player->getY() + 48 - player->getVerticalSpeed()) / 48;

		if (tileManager->tiles[topRow][leftCol]->getCollision() == true || tileManager->tiles[topRow][rightCol]->getCollision() == true) {
			player->setCollidingHead(true);
		}
		else {
			player->setCollidingHead(false);
		}

		if (player->getDirection() == "left") {
			leftCol = (player->getX() - player->getSpeed() + 8) / 48;

			if (tileManager->tiles[topRow][leftCol]->getCollision() == true || tileManager->tiles[bottomRow][leftCol]->getCollision() == true) {
				player->setColliding(true);
			}
			else {
				player->setColliding(false);
			}
		}

		if (player->getDirection() == "right") {
			rightCol = (player->getX() + 48 + player->getSpeed() - 8) / 48;

			if (tileManager->tiles[topRow][rightCol]->getCollision() == true || tileManager->tiles[bottomRow][rightCol]->getCollision() == true) {
				player->setColliding(true);
			}
			else {
				player->setColliding(false);
			}
		}
	}
	//Check if tile is colliding with player when falling
	else if (player->getFalling() == true) {
		leftCol = (player->getX() - player->getSpeed() + 8) / 48;
		rightCol = (player->getX() + 48 + player->getSpeed() - 8) / 48;
		topRow = (player->getY() + 16) / 48;
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
	//Check if tile is colliding with player when walking left and right
	else {
		leftCol = (player->getX() - player->getSpeed() + 8) / 48;
		rightCol = (player->getX() + 48 + player->getSpeed() - 8) / 48;
		topRow = (player->getY() + 16) / 48;
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

//Check if player collides with a mob
void CollisionChecker::checkMobCollision(Player& player, Entity& mob) {
	player.checkImmune();
	if (player.getSprite().getGlobalBounds().intersects(mob.getSprite().getGlobalBounds()) && !player.getImmune()) {
		player.setImmune();
		player.deductHealth();
	}
}

//Check if player collides with a fireball
void CollisionChecker::checkFireCollision(Player* player, FireBall* fire) {
	player->checkImmune();
	if (player->getSprite().getGlobalBounds().intersects(fire->getSprite().getGlobalBounds()) && !player->getImmune()) {
		player->setImmune();
		player->deductHealth();
	}
}