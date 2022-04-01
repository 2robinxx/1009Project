#include "FireBat.h"

//Constructors / Destructors
FireBat::FireBat(float width, float height, Player* player) : Bat(width, height){
	fireSpeed = 2;
	this->player = player;
	fireball = NULL;
	idleTimer = 0;
	initSprite();
	initHitbox();
}

FireBat::FireBat(float width, float height, float x, float y, Player* player) : Bat(width, height, x, y) {
	fireSpeed = 2;
	this->player = player;
	fireball = NULL;
	idleTimer = 0;
	initSprite();
	initHitbox();
}

FireBat::~FireBat() {
	cout << "FireBat destroyed." << endl;
}

FireBall::FireBall(float x, float y, string direction) {
	width = 24.f;
	height = 24.f;
	this->x = x;
	this->y = y;
	this->direction = direction;
	initSprite();
	initHitbox();
}

FireBall::~FireBall() {
	cout << "FireBall destroyed." << endl;
}

//Functions
//Set the movement pattern for FireBats. Overwrites parent Bat's setMovement()
void FireBat::setMovement() {

	if (time(NULL) > idleTimer) {
		isIdle = false;
		isRest = false;
	}

	if (fireball != NULL) {
		fireball->setMovement();
		fireball->setPosition();
		if (fireball->getX() > WORLD_WIDTH || fireball->getX() < 0) {
			delete fireball;
			fireball = NULL;
		}
	}
	else {
		setAttack();
	}

	if (x > player->getX()) {
		direction = "left";
	}
	else if (x < player->getX()) {
		direction = "right";
	}

	if (y > player->getY()) {
		verticalDirection = "up";
	}
	else if (y < player->getY()) {
		verticalDirection = "down";
	}
	else if (y == player->getY() && !isIdle) {
		isIdle = true;
		idleTimer = time(NULL) + 3;
	}

	if (direction == "left" && !isIdle) {
		setSprite("left");
	}
	else if (direction == "right" && !isIdle) {
		setSprite("right");
	}

	if (verticalDirection == "down" && !isIdle) {
		y += verticalSpeed;
	}
	else if (verticalDirection == "up" && !isIdle) {
		y -= verticalSpeed;
	}
}

//Set the attack pattern for FireBats
void FireBat::setAttack() {
	if (isIdle && !isRest) {
		isRest = true;
		cout << x << " " << y << " ";
		fireball = new FireBall(x, y + 12, direction);
	}
}

//Initialize the sprites for FireBat. Overwrites parent Bat's initSprite()
void FireBat::initSprite() {
	idleSprite.loadFromFile("Sprites/mob/firebat_left_1.png");
	leftSprite1.loadFromFile("Sprites/mob/firebat_left_1.png");
	leftSprite2.loadFromFile("Sprites/mob/firebat_left_2.png");
	rightSprite1.loadFromFile("Sprites/mob/firebat_right_1.png");
	rightSprite2.loadFromFile("Sprites/mob/firebat_right_2.png");
}

//Set the movement pattern for fireballs
void FireBall::setMovement() {
	if (direction == "left") {
		x = x - speed;
	}
	else if (direction == "right") {
		x = x + speed;
	}
}

//Initialize the sprites for fireballs
void FireBall::initSprite() {
	idleSprite.loadFromFile("Sprites/mob/fireball.png");
	leftSprite1.loadFromFile("Sprites/mob/fireball.png");
	leftSprite2.loadFromFile("Sprites/mob/fireball.png");
	rightSprite1.loadFromFile("Sprites/mob/fireball.png");
	rightSprite2.loadFromFile("Sprites/mob/fireball.png");
}

//Interfaces
FireBall* FireBat::getFireball() {
	return fireball;
}

void FireBat::setDamage(int damage) {
	this->damage = damage;
}

int FireBat::getDamage() {
	return damage;
}