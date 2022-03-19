#include "GamePanel.h"
#include <iostream>

GamePanel::GamePanel() : player1(1), player2(2), tileManager(), collisionChecker(&tileManager){
	initVariables();
	initWindow();
}

GamePanel::~GamePanel() {
	delete window;
}

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
	collisionChecker.checkTile(&player1);
	collisionChecker.checkTile(&player2);
	player1.setMovement();
	player2.setMovement();
	player1.setPosition();
	player2.setPosition();
}

void GamePanel::render() {
	window->clear();

	renderMap();

	window->draw(player1.getPlayer());
	window->draw(player2.getPlayer());

	window->display();
}

const bool GamePanel::getWindowIsOpen(){
	return window->isOpen();
}

void GamePanel::renderMap() {
	for (int i = 0; i < 50; i++) {

		for (int j = 0; j < 16; j++) {
			window->draw(tileManager.tiles[i][j]->sprite);
		}

	}
}