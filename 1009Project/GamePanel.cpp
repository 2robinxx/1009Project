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

	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxBoots = 3;
}

void GamePanel::initWindow() {
	videoMode.height = 960;
	videoMode.width = 768;
	
	//Setting the view for the game
	view.setSize(960.f, 768.f);

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

	this->spawnBoots();
	this->objectCollision();
	
	//Setting camera movement to follow player that is highest in the screen
	if (player1.getY() > player2.getY()) {

		view.setCenter(window->getSize().x / 2.f, player2.getY());

	}
	else {
		view.setCenter(window->getSize().x / 2.f, player1.getY());

	}
}

void GamePanel::render() {
	window->clear();
	
	window->setView(view);

	
	renderMap();
	window->draw(player1.getSprite());
	window->draw(player2.getSprite());
	window->draw(bat.getSprite());


	for (auto i : this->boots)
	{
		
		i.render(*window);
		
	}
	

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

void GamePanel::spawnBoots()
{
	//Timer
	if (this->spawnTimer < this->spawnTimerMax)
	{
		this->spawnTimer += 1.f;
	}
	else
	{
		if (this->boots.size() < this->maxBoots)
		{
			this->boots.push_back(Boots(*this->window));
			this->spawnTimer = 0.f;
		}
	}
}

void GamePanel::objectCollision()
{
	//Check collision
	for (size_t i = 0; i < this->boots.size(); i++)
	{
		if (this->player1.getSprite().getGlobalBounds().intersects(this->boots[i].getBoots().getGlobalBounds()))
		{
			this->boots.erase(this->boots.begin() + i);
			this->player1.setSpeed(2);
			cout << "Player1 Speed boost" << this->player1.getSpeed() << endl;
			
		}
		else if (this->player2.getSprite().getGlobalBounds().intersects(this->boots[i].getBoots().getGlobalBounds()))
		{
			this->boots.erase(this->boots.begin() + i);
			this->player2.setSpeed(2);
			cout << "Player2 Speed boost" << this->player2.getSpeed() << endl;

		}
		
	}

}

//Interfaces
const bool GamePanel::getWindowIsOpen() {
	return window->isOpen();
}
