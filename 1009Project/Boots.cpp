#include "Boots.h"
#include <iostream>


void Boots::initObject(const sf::RenderWindow& window)
{
	this->sprite.setRadius(20);
	//sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
	
	this->sprite.setFillColor(sf::Color::Blue);
	this->sprite.setOutlineColor(sf::Color::Black);
	this->sprite.setOutlineThickness(5);
	//sf::Texture objImg;
	//objImg.loadFromFile("Sprites/object/boots.png");
	//this->sprite.setTexture(&objImg);
	//this->sprite.setTextureRect(sf::IntRect(10, 10, 100, 100));


	this->sprite.setPosition(
		sf::Vector2f(
			static_cast<float>(rand() % (window.getSize().x - 100) ),
			static_cast<float>(rand() % (window.getSize().y - 100) )
		));

}


Boots::Boots(const sf::RenderWindow& window)
{
	this->initObject(window);
}

Boots::~Boots()
{
	
}

const sf::CircleShape Boots::getBoots() const
{
	return this->sprite;
}

void Boots::update()
{
}

void Boots::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}



