#include "Object.h"
#include <iostream>


void Object::initObject(const sf::RenderWindow& window)
{
	this->sprite.setRadius(20);
	sf::Color color;
	switch (this->type)
	{
		case DEFAULT:
			color = sf::Color::Blue;
			break;
		case DAMAGING:
			color = sf::Color::Red;
			break;
		case HEALING:
			color = sf::Color::Green;
			break;

	}
	
	this->sprite.setFillColor(color);
	this->sprite.setOutlineColor(sf::Color::Black);
	this->sprite.setOutlineThickness(5);
	//sf::Texture objImg;
	//objImg.loadFromFile("Sprites/object/boots.png");
	//this->sprite.setTexture(&objImg);
	//this->sprite.setTextureRect(sf::IntRect(10, 10, 100, 100));


	this->sprite.setPosition(
		sf::Vector2f(
			static_cast<float>((rand() % window.getSize().x) - this->sprite.getGlobalBounds().width),
			static_cast<float>((rand() % window.getSize().y) - this->sprite.getGlobalBounds().height)
		));

}


Object::Object(const sf::RenderWindow& window , int type)
	:type(type)
{
	
	this->initObject(window);
}

Object::~Object()
{
	
}

const sf::CircleShape Object::getObject() const
{
	return this->sprite;
}

const int& Object::getType() const
{
	return this->type;
}

void Object::update()
{
}

void Object::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}



