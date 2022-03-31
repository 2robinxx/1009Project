#include "GamePanel.h"


//Constructor/Destructor
GamePanel::GamePanel() : player1(1), player2(2), bat(48.f, 48.f), tileManager("Sprites/maps/map01.txt"), collisionChecker(&tileManager){
	initVariables();
	initWindow();

	initFont();
	initText();

	//Play background music
	playBackgroundMusic();
	


}

GamePanel::~GamePanel() {
	delete window;
	
	cout << "This game was played for: " << playtime << endl;
	cout << "GamePanel destroyed. Game closed" << endl;
}

//Functions
void GamePanel::initVariables() {
	window = nullptr;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxObjects = 3;


}

void GamePanel::initWindow() {

	videoMode.height = 960;
	videoMode.width = 768;

	//Setting the view for the game
	mainMapView.setSize(768.f, 700.f);

	window = new sf::RenderWindow(videoMode, "Dino Jump", sf::Style::Close | sf::Style::Titlebar);

	window->setFramerateLimit(60);

}

void GamePanel::initFont()
{
	if(!this->font.loadFromFile("Fonts/game_sans_serif_7.ttf"))
	{
		cout<<"ERROR LOADING FONT"<<endl;
	}
}

void GamePanel::initText()
{
	this->guiSpeedText.setFont(this->font);
	this->guiSpeedText.setFillColor(sf::Color::White);
	this->guiSpeedText.setCharacterSize(30.f);

	
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
	collisionChecker.checkMobCollision(&player1, &bat);
	collisionChecker.checkMobCollision(&player2, &bat);

	player1.setMovement();
	player2.setMovement();

	player1.setPosition();
	player2.setPosition();

	bat.setMovement();
	bat.setPosition();

	this->spawnObj();
	this->objCollision();
	this->updateSpeedGUI();
	//setting up how long the user plays
	this->playtime += (double)1/60;
	//checking if player reached the top or died
	checkGoal();
	checkDeath();
	
	
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

	for (auto i : this->obj)
	{
		i.render(*window);
	}

	//Drawing on UI view
	window->setView(UI);
	drawHearts();

	this->drawSpeedGUI(window);

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

void GamePanel::spawnObj()
{
	//Timer
	if (this->spawnTimer < spawnTimerMax)
	{
		this->spawnTimer += 1.f;
	}
	else
	{
		if (this->obj.size() < this->maxObjects)
		{
			this->obj.push_back(Object(*this->window, rand()% objectType::NOFT));
			this->spawnTimer = 0.f;
		}
		
	}
}

void GamePanel::objCollision()
{
	//Check the Collsion
	for (size_t i= 0; i < this->obj.size(); i++)
	{
		if (this->player1.getSprite().getGlobalBounds().intersects(this->obj[i].getObject().getGlobalBounds()))
		{
			switch (this->obj[i].getType())
			{
				case objectType::DEFAULT:
					//iNCREASE SPEED
					this->player1.setSpeed(2);
					cout << "Player 1 speed is " << player1.getSpeed() << endl;
					break;
				case objectType::DAMAGING:
					//DAMAGE HEALTH
					this->player2.setDamage(1);
					cout << "Player 1 Damage Player 2 " <<  endl;
					break;
				case objectType::HEALING:
					//HEAL
					this->player1.gainHealth(1);
					cout << "Player 1 Health is " << player1.getHealth() << endl;
					break;
			}
		
			//REMOVE OBJECT
			this->obj.erase(this->obj.begin() + i);
		
			
		
		}
		else if (this->player2.getSprite().getGlobalBounds().intersects(this->obj[i].getObject().getGlobalBounds()))
		{
			switch (this->obj[i].getType())
			{
			case objectType::DEFAULT:
				//iNCREASE SPEED
				this->player2.setSpeed(2);
				cout << "Player 2 speed is " << player2.getSpeed() << endl;
				break;
			case objectType::DAMAGING:
				//DAMAGE HEALTH
				this->player1.setDamage(1);
				cout << "Player 2 Damage Player 1 " << endl;
				break;
			case objectType::HEALING:
				//HEAL
				this->player2.gainHealth(1);
				cout << "Player 2 Health is " << player2.getHealth() << endl;
				break;
			}

			//REMOVE OBJECT
			this->obj.erase(this->obj.begin() + i);
			
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


inline void GamePanel::drawSpeedGUI(sf::RenderTarget* target)
{
	target->draw(this->guiSpeedText);
}

void GamePanel::updateSpeedGUI()
{
	int p1speed;
	int p2speed;

	p1speed = player1.getSpeed();
	p2speed = player2.getSpeed();

	stringstream ss;
	ss << " Player 1 speed: " << p1speed << "\t\t\t\t\t\t\t\t" << "Player 2 speed:  " << p2speed;
	this->guiSpeedText.setString(ss.str());

}

inline int GamePanel::checkGoal() {
	
	if (player1.getY() <= 48 * 1) {
		cout << "Player 1 wins"<< endl;
		return 1;

	}
	if (player2.getY() <= 48 * 1) {
		cout << "Player 2 wins" << endl;
		return 2;
	}
	return 3;
}

inline int GamePanel::checkDeath() {

	if (player1.getY() >= this->player2.getY()+(48*18)||player1.getHealth()==0) {
		cout << "Player 1 died" << endl;
		return 1;

	}
	if (player2.getY() >= this->player1.getY() + (48 * 18) || player2.getHealth() == 0) {
		cout << "Player 2 died" << endl;
		return 2;
	}
	return 3;
}
