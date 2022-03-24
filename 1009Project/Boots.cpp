#include "Boots.h"
#include <iostream>


void Boots::initObject(const sf::RenderWindow& window)
{
	this->sprite.setRadius(20);
	//sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
	
	this->sprite.setFillColor(sf::Color::Blue);
	//sf::Texture objImg;
	//objImg.loadFromFile("Sprites/object/boots.png");
	//this->sprite.setTexture(&objImg);


	this->sprite.setPosition(sf::Vector2f(static_cast<float>(rand()%window.getSize().x - this->sprite.getGlobalBounds().width), 
		static_cast<float>(rand() % window.getSize().y - this->sprite.getGlobalBounds().height)));

	cout << "Boots rendered" << endl;
}


Boots::Boots(const sf::RenderWindow& window)
{
	this->initObject(window);
}

Boots::~Boots()
{
	
}

void Boots::update()
{
}

void Boots::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}



