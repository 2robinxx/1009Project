#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "TileManager.h"
#include "CollisionChecker.h"

#ifndef GAMEPANEL
#define GAMEPANEL

using namespace std;

class GamePanel {
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	Player player1;
	Player player2;

	void initVariables();
	void initWindow();
public:
	TileManager tileManager;
	CollisionChecker collisionChecker;

	GamePanel();
	~GamePanel();

	const bool getWindowIsOpen();

	void pollEvents();
	void update();
	void render();
	void renderMap();

	void setPlayerMovement();
};

#endif
