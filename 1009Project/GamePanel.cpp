#include "GamePanel.h"


//Constructor/Destructor
GamePanel::GamePanel() : player1(1), player2(2), bat(48.f, 48.f), tileManager("Sprites/maps/map01.txt"), collisionChecker(&tileManager){
	initVariables();
	initWindow();

	//Play background music
	playBackgroundMusic();

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

	//Setting the view for the game
	mainMapView.setSize(768.f, 700.f);

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


	
	//Setting camera movement to follow player that is highest in the screen
	if (player1.getY() > player2.getY()) {

		mainMapView.setCenter(window->getSize().x / 2.f, player2.getY());

	}
	else {
		mainMapView.setCenter(window->getSize().x / 2.f, player1.getY());

	}


}

void GamePanel::render() {
	window->clear();

	//Drawing on main Map View
	window->setView(mainMapView);

	renderMap();
	window->draw(player1.getSprite());
	window->draw(player2.getSprite());
	window->draw(bat.getSprite());

	//Drawing on UI view
	window->setView(UI);
	drawHearts();

	window->display();

	window->setView(window->getDefaultView());

	
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


void GamePanel::playBackgroundMusic() {
	sound.setBuffer("Sprites/sound/background.wav");
	sound.setLoop();
	sound.playSound();
}

void GamePanel::drawHearts() {
	int subsetHeartP1 = 100;
	for (int i = 0; i < player1.getHealth(); i++) {
		window->draw(health.loadTexture(subsetHeartP1, 100));
		subsetHeartP1 += 20;
	}

	int subsetHeartP2 = 850;
	for (int i = 0; i < player2.getHealth(); i++) {
		window->draw(health.loadTexture(subsetHeartP2, 100));
		subsetHeartP2 += 20;
	}


}
