#include "GamePanel.h"


//Constructor/Destructor
GamePanel::GamePanel() : player1(1), player2(2), bat(48.f, 48.f), firebat1(48.f, 48.f, &player1), firebat2(48.f, 48.f, (WORLD_WIDTH - 48), 0, &player2), tileManager("Sprites/maps/map01.txt"), collisionChecker(&tileManager) {
	
	initVariables();
	initWindow();
	initFont();
	initText();

	//Play background music
	playBackgroundMusic();
}

GamePanel::~GamePanel() {
	delete window;
	cout << "GamePanel destroyed. Game closed" << endl;
}

//Functions
//Initialize variables for the game
void GamePanel::initVariables() {
	window = nullptr;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxObjects = 3;
	this->screen = "menu";
}

//Initialize game window
void GamePanel::initWindow() {

	//Set application height and width
	videoMode.height = 960;
	videoMode.width = 768;

	//Setting the camera view for the game
	mainMapView.setSize(768.f, 960.f);

	window = new sf::RenderWindow(videoMode, "Dino Jump", sf::Style::Close | sf::Style::Titlebar);
	window->setFramerateLimit(60);

}

//Initialize font
void GamePanel::initFont()
{
	if(!this->font.loadFromFile("Fonts/game_sans_serif_7.ttf"))
	{
		cout<<"ERROR LOADING FONT"<<endl;
	}
}

//Initialize texts
void GamePanel::initText()
{
	this->guiSpeedText.setFont(this->font);
	this->guiSpeedText.setFillColor(sf::Color::White);
	this->guiSpeedText.setCharacterSize(30.f);
	this->guiSpeedText.setStyle(sf::Text::Bold);
	this->guiSpeedText.setPosition(sf::Vector2f(40,50));
}

//Set the ability to operate the game menus and the application.
void GamePanel::pollEvents() {
	while (window->pollEvent(this->ev))
	{
		switch (ev.type)
		{
			case sf::Event::KeyPressed:
				if (screen == "menu" && (ev.key.code == sf::Keyboard::Up || ev.key.code == sf::Keyboard::Down || ev.key.code == sf::Keyboard::Enter)) {

					menu.toggleMenu();
					break;
				}
				if (screen == "end" && (ev.key.code == sf::Keyboard::Up || ev.key.code == sf::Keyboard::Down || ev.key.code == sf::Keyboard::Enter)) {

					endscreen.toggleMenu();
					break;
				}
				if (screen == "mapSelection" && (ev.key.code == sf::Keyboard::Up || ev.key.code == sf::Keyboard::Down || ev.key.code == sf::Keyboard::Enter)) {

					mapSelection.toggleMenu();
					break;
				}

				break;
			case sf::Event::Closed:
				window->close();
				break;
			default:
				break;
		}
	}
}

//Constantly loops to update the game
void GamePanel::update() {
	pollEvents();

	if (screen == "menu") {
		// Play option
		if (menu.selectedItemIndex == 0 && menu.enterPressKey == 1) {
			screen = "play";
			hs.map = 0;
			menu.enterPressKey = 0;
		}
		//Quit option
		else if (menu.selectedItemIndex == 2 && menu.enterPressKey == 1) {

			//Close window
			window->close();
		}
		//Map selection option
		else if (menu.selectedItemIndex == 1 && menu.enterPressKey == 1) {

			screen = "mapSelection";
			menu.enterPressKey = 0;
		}
	}
	if (screen == "mapSelection") {
		// Underground Map
		if (mapSelection.selectedItemIndex == 0 && mapSelection.enterPressKey == 1) {
			
			chooseMap();
			hs.map = 0;
			screen = "play";
			mapSelection.enterPressKey = 0;
		}
		// Ice Map
		else if (mapSelection.selectedItemIndex == 1 && mapSelection.enterPressKey == 1) {
			
			chooseMap();
			hs.map = 1;
			screen = "play";
			mapSelection.enterPressKey = 0;
		}
	}
	if (screen == "end") {
		
		this->playtime += 0;
		

		// Play option
		if (endscreen.selectedItemIndex == 0 && endscreen.enterPressKey == 1) {
			restartGame();
			screen = "menu";
			endscreen.enterPressKey = 0;
		}
		//Quit option
		else if (endscreen.selectedItemIndex == 1 && endscreen.enterPressKey == 1) {

			//Close window
			window->close();
		}
		else if (endscreen.selectedItemIndex == 2 && endscreen.enterPressKey == 1) {

			//Close window
			screen = "highscore";
			endscreen.enterPressKey = 0;
		}
	}
	else if (screen == "play") {

		try {
			collisionChecker.checkTileCollision(&player1);
			collisionChecker.checkTileCollision(&player2);
		}
		catch (const char * msg) {
			cout << msg << endl;
		}

		collisionChecker.checkMobCollision(player1, bat);
		collisionChecker.checkMobCollision(player2, bat);

		if (firebat1.getFireball() != NULL) {
			checkFireCollision(player1, *firebat1.getFireball());
			checkFireCollision(player2, *firebat1.getFireball());
		}
		if (firebat2.getFireball() != NULL) {
			checkFireCollision(player1, *firebat2.getFireball());
			checkFireCollision(player2, *firebat2.getFireball());
		}

		try {
			player1.setMovement();
			player1.setPosition();

			player2.setMovement();
			player2.setPosition();
		}
		catch (const char* msg) {
			cout << msg << endl;
			player1.setPosition(300.f, 400.f);
			player2.setPosition(400.f, 400.f);
		}

		try {
			bat.setMovement();
			bat.setPosition();
		}
		catch (const char* msg) {
			cout << msg << endl;
			bat.setPosition(0, 0);
		}

		try {
			firebat1.setMovement();
			firebat1.setPosition();
		}
		catch (const char* msg) {
			cout << msg << endl;
			firebat1.setPosition(0, 0);
		}

		try {
			firebat2.setMovement();
			firebat2.setPosition();
		}
		catch (const char* msg) {
			cout << msg << endl;
			firebat2.setPosition(WORLD_WIDTH - 48, 0);
		}

		this->spawnObj();
		this->objCollision();
		this->updateSpeedGUI();

		//Setting up how long the user plays
		this->playtime += (double)1 / 60;

		//Checking if player reached the top or died
		checkGoal();
		checkDeath();

		if (checkGoal() == 1 || checkGoal() == 2 || checkDeath() == 1 || checkDeath() == 2) {
			//comment out the line to remove the end screen
			
			this->screen = "end";
		}

		//Setting camera movement to follow player that is highest in the screen
		if (player1 > player2) {

			mainMapView.setCenter(window->getSize().x / 2.f, player2.getY());
		}
		else {

			mainMapView.setCenter(window->getSize().x / 2.f, player1.getY());
		}
	}
}

//Constantly loops to render the sprites
void GamePanel::render() {

	if (this->screen == "menu") {
		sf::Color color(0, 153, 51);//bg color
		window->clear(color);
		menu.drawTitle(*window);
		menu.draw(*window, window->getSize().x, window->getSize().y);
		window->display();
	}
	if (this->screen == "end") {

		sf::Color color(0, 153, 51);//bg color
		window->clear(color);
		endscreen.draw(*window, window->getSize().x, window->getSize().y);
		if (score == 0) {
			cout << "This game was played for: " << playtime << endl;
			hs.addFile();
			hs.addScore(round(playtime));
			hs.readScore();
			hs.writeScore();
			score = 1;
		}
		
		window->display();
	}
	if (this->screen == "highscore") {

		sf::Color color(0, 153, 51);//bg color
		window->clear(color);
		if (test == 0) {
			
			hs.writeScore();
			test = 1;
		}
		scoreScreen.drawTitle(*window);
		hs.draw(*window, window->getSize().x, window->getSize().y);
		window->display();
	}
	if (this->screen == "mapSelection") {

		//draw map selection screen
		sf::Color color(0, 153, 51);//bg color
		window->clear(color);
		mapSelection.drawTitle(*window);
		if (test = 0) {
			hs.readScore();
			test = 1;
		}
		mapSelection.draw(*window, window->getSize().x, window->getSize().y);
		window->display();
	}
	else if (screen == "play") {

		window->clear();

		//Drawing on main Map View
		window->setView(mainMapView);

		renderMap();
		window->draw(player1.getSprite());
		window->draw(player2.getSprite());
		window->draw(bat.getSprite());
		window->draw(firebat1.getSprite());
		window->draw(firebat2.getSprite());

		if (firebat1.getFireball() != NULL) {
			window->draw(firebat1.getFireball()->getSprite());
		}
		if (firebat2.getFireball() != NULL) {
			window->draw(firebat2.getFireball()->getSprite());
		}

		for (auto i : this->obj)
		{
			i.render(*window);
		}

		//Drawing on UI view
		window->setView(UI);
		
		this->drawSpeedGUI(window);
		drawHearts();

		window->display();

		window->setView(window->getDefaultView());
	}
}

//Restart the game by re-initializing all objects.
void GamePanel::restartGame() {
	player1 = Player(1);
	player2 = Player(2);
	bat = Bat(48.f, 48.f);
	firebat1 = FireBat(48.f, 48.f, &player1);
	firebat2 = FireBat(48.f, 48.f, (WORLD_WIDTH - 48), 0, &player2);
	player1.setSprite("right");
	player2.setSprite("left");
}

//Draw tiles onto the game
void GamePanel::renderMap() {
	for (int i = 0; i < GRID_HEIGHT; i++) {
		for (int j = 0; j < GRID_WIDTH; j++) {
			window->draw(tileManager.tiles[i][j]->getSprite());
		}
	}
}

//Choose which map to draw onto the game
void GamePanel::chooseMap() {
	if (mapSelection.selectedItemIndex == 1 && mapSelection.enterPressKey == 1)
	{
		tileManager.chooseMap("Sprites/maps/map02.txt");
	}
	else
	{
		tileManager.chooseMap("Sprites/maps/map01.txt");
	}
}

//Spawn objects
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

//Check object collision
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

//Play background music for the game
inline void GamePanel::playBackgroundMusic() {
	sound.setBuffer("Sprites/sound/background.wav");
	sound.setLoop();
	sound.playSound();
}

//Draw player hearts onto the screen
void GamePanel::drawHearts() {
	int subsetHeartP1 = 60;
	for (int i = 0; i < player1.getHealth(); i++) {
		window->draw(health.loadTexture(subsetHeartP1, 100));
		subsetHeartP1 += 70;
	}

	int subsetHeartP2 = 750;
	for (int i = 0; i < player2.getHealth(); i++) {
		window->draw(health.loadTexture(subsetHeartP2, 100));
		subsetHeartP2 += 70;
	}
}

//Draw player speed onto the screen
inline void GamePanel::drawSpeedGUI(sf::RenderTarget* target)
{
	
	sf::FloatRect bgRect = guiSpeedText.getGlobalBounds();
	sf::RectangleShape background(sf::Vector2f(bgRect.width + 20, bgRect.height + 60));
	sf::Color color(4, 20, 46, 150);
	background.setFillColor(color);
	background.setOutlineColor(sf::Color::Black);
	background.setOutlineThickness(5);

	target->draw(background, guiSpeedText.getTransform());
	target->draw(this->guiSpeedText);
}

//Update player speed UI
void GamePanel::updateSpeedGUI()
{
	
	int p1speed = player1.getSpeed();
	int p2speed = player2.getSpeed();

	stringstream ss;
	ss << " P1 Speed: " << p1speed << "\t\t-----STATUS----\t\t" << "P2 Speed: " << p2speed;
	this->guiSpeedText.setString(ss.str());

	
}

//Check if player reached the goal
inline int GamePanel::checkGoal() {

	if (player1 <= 48 * 1) {
		cout << "Player 1 wins" << endl;
		endscreen.playerwon = 1;
		return 1;

	}
	if (player2 <= 48 * 1) {
		cout << "Player 2 wins" << endl;
		endscreen.playerwon = 2;
		return 2;
	}
	return 3;
}

//Check if player died
inline int GamePanel::checkDeath() {

	if (player1 >= this->player2.getY() + (48 * 10) || player1.getHealth() == 0) {
		cout << "Player 1 died" << endl;
		endscreen.playerwon = 2;
		return 1;
	}
	if (player2 >= this->player1.getY() + (48 * 10) || player2.getHealth() == 0) {
		cout << "Player 2 died" << endl;
		endscreen.playerwon = 1;
		return 2;
	}
	return 3;
}

//Interfaces
const bool GamePanel::getWindowIsOpen() {
	
	return window->isOpen();
}
