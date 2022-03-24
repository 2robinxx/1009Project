#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "TileManager.h"
#include "CollisionChecker.h"
#include "Bat.h"
#include "Boots.h"
#include <iostream>
#include <vector>

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

//Object to call all the other functions of the game.
class GamePanel {
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::View view;

	//Objects
	Player player1;
	Player player2;
	Bat bat;


	//container for boots
	std::vector<Boots> boots;
	float spawnTimerMax;
	float spawnTimer;
	int maxBoots;

	//Functions
	void initVariables();
	void initWindow();
public:
	TileManager tileManager;
	CollisionChecker collisionChecker;

	//Constructor/Destructor
	GamePanel();
	~GamePanel();

	//Functions
	void pollEvents();
	void update();
	void render();
	void renderMap();

	void spawnBoots();
	void objectCollision();

	//Interfaces
	const bool getWindowIsOpen();
};
