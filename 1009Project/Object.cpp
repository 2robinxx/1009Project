#include "Object.h"
#include <iostream>


void Object::initObject(const sf::RenderWindow& window)
{


	this->sprite = sf::RectangleShape(sf::Vector2f(50, 50));
	sf::Texture* texture = new sf::Texture();
	switch (this->type)
	{
		case DEFAULT:
			texture->loadFromFile("Sprites/object/boots.png");
			break;
		case DAMAGING:
			texture->loadFromFile("Sprites/object/sword_normal.png");
			break;
		case HEALING:
			texture->loadFromFile("Sprites/object/heart_full.png");
			break;

	}
	
	this->sprite.setTexture(texture);
	this->sprite.setPosition(
		sf::Vector2f(
			static_cast<float>((rand() % window.getSize().x) - this->sprite.getGlobalBounds().width),
			static_cast<float>((rand() % window.getSize().y) - this->sprite.getGlobalBounds().height)
		));

}

//Constructor
Object::Object(const sf::RenderWindow& window , int type)
	:type(type)
{
	
	this->initObject(window);


}

Object::~Object()
{
	
}

const sf::RectangleShape Object::getObject() const
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




