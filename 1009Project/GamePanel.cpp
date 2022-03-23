#include "GamePanel.h"

//Constructor/Destructor
GamePanel::GamePanel() : player1(1), player2(2), bat(48.f, 48.f), tileManager("Sprites/maps/map01.txt"), collisionChecker(&tileManager){
	initVariables();
	initWindow();
}

GamePanel::~GamePanel() {
	delete window;
	cout << "GamePanel destroyed. Game closed" << endl;
}

//Functions
void GamePanel::initVariables() {
	window = nullptr;
}

void GamePanel::initWindow() {
	videoMode.height = 960;
	videoMode.width = 768;

	window = new sf::RenderWindow(videoMode, "Dino Jump", sf::Style::Close | sf::Style::Titlebar);

	window->setFramerateLimit(60);
}

void GamePanel::pollEvents() {
	while (window->pollEvent(this->ev))
	{
		if (ev.type == sf::Event::Closed) {
			window->close();
		}
	}
}

void GamePanel::update() {
	pollEvents();
	collisionChecker.checkTileCollision(&player1);
	collisionChecker.checkTileCollision(&player2);

	player1.setMovement();
	player2.setMovement();

	player1.setPosition();
	player2.setPosition();

	bat.setMovement();
	bat.setPosition();
}

void GamePanel::render() {
	window->clear();
	renderMap();
	window->draw(player1.getSprite());
	window->draw(player2.getSprite());
	window->draw(bat.getSprite());
	window->display();
}

void GamePanel::renderMap() {
	for (int i = 0; i < GRID_HEIGHT; i++) {

		for (int j = 0; j < GRID_WIDTH; j++) {
			window->draw(tileManager.tiles[i][j]->getSprite());
		}

	}
}

//Interfaces
const bool GamePanel::getWindowIsOpen() {
	return window->isOpen();
}