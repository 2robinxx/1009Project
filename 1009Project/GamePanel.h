#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "TileManager.h"
#include "CollisionChecker.h"
#include "Bat.h"
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

//Object to call all the other functions of the game.
class GamePanel {
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Objects
	Player player1;
	Player player2;
	Bat bat;

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

	//Interfaces
	const bool getWindowIsOpen();
};
