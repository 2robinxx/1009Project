#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "TileManager.h"
#include "CollisionChecker.h"
#include "Bat.h"
#include "Sound.h"
#include "Health.h"
#include "Object.h"
#include "Menu.h"
#include "EndScreen.h"
#include "MapSelection.h"
#include "FireBat.h"
#include "highscore.h"
#include "highscoreScreen.h"

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
	//Variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::View mainMapView;
	sf::View UI;
	sf::Font font;
	sf::Text guiSpeedText;

	vector<Object> obj;
	float spawnTimerMax;
	int spawnTimer;
	int maxObjects;
	
	int score = 0;
	int test = 0;
	string screen;

	//Objects
	Player player1;
	Player player2;
	Bat bat;
	FireBat firebat1, firebat2;
	Sound sound;
	Health health;
	Menu menu;
	EndScreen endscreen;
	MapSelection mapSelection;
	highscore hs;
	highscoreScreen scoreScreen;

	//Functions
	void initVariables();
	void initWindow();
	void initFont();
	void initText();

public:
	//Objects
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
	void chooseMap();
	void spawnObj();
	void objCollision();
	inline void playBackgroundMusic();
	void drawHearts();
	inline void drawSpeedGUI(sf::RenderTarget* target);
	void updateSpeedGUI();
	inline int checkGoal();
	inline int checkDeath();
	double playtime = 0;

	//Interfaces
	const bool getWindowIsOpen();
};
