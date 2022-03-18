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
	player1.setPosition();
	player2.setPosition();
	collisionChecker.checkTile(player1);
}

void GamePanel::render() {
	window->clear();

	setPlayerMovement();

	renderMap();

	window->draw(player1.getPlayer());
	window->draw(player2.getPlayer());

	window->display();
}

const bool GamePanel::getWindowIsOpen(){
	return window->isOpen();
}

void GamePanel::setPlayerMovement() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		player1.setX(player1.getX() - player1.getSpeed());
		player1.setSprite("left");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		player1.setX(player1.getX() + player1.getSpeed());
		player1.setSprite("right");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I)) {

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J)) {
		player2.setX(player2.getX() - player2.getSpeed());
		player2.setSprite("left");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L)) {
		player2.setX(player2.getX() + player2.getSpeed());
		player2.setSprite("right");
	}
}

void GamePanel::renderMap() {
	for (int i = 0; i < 50; i++) {

		for (int j = 0; j < 16; j++) {
			window->draw(tileManager.tiles[i][j]->sprite);
		}

	}
}