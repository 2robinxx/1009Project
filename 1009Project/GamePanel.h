#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "TileManager.h"
#include "CollisionChecker.h"
#include "Bat.h"
#include "Sound.h"
#include "Health.h"
#include "Object.h"
#include "FireBat.h"
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
	sf::View mainMapView;
	sf::View UI;
	Sound sound;
	Health health;
	


	//Objects
	Player player1;
	Player player2;
	Bat bat;
	FireBat firebat1, firebat2;

	vector<Object> obj;
	float spawnTimerMax;
	int spawnTimer;
	int maxObjects;
	double playtime = 0;

	sf::Font font;
	sf::Text guiSpeedText;



	//Functions
	void initVariables();
	void initWindow();

	void initFont();
	void initText();


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

	void spawnObj();
	void objCollision();

	//checking death and goal
	int checkGoal();
	int checkDeath();

	//Interfaces
	const bool getWindowIsOpen();

	void playBackgroundMusic();
	void drawHearts();

	void drawSpeedGUI(sf::RenderTarget* target);
	void updateSpeedGUI();

};
