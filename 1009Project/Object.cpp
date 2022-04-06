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
			texture->loadFromFile("Sprites/object/potion.png");
			break;

	}

	int windowX = window.getSize().x;
	int windowY= window.getSize().y;
	int spriteW = this->sprite.getGlobalBounds().width;
	int spriteH = this->sprite.getGlobalBounds().height;

	
	this->sprite.setTexture(texture);
	this->sprite.setPosition(
		sf::Vector2f(
			static_cast<float>((rand() % (windowX- 2*spriteW))),
			static_cast<float>((rand() % (windowY- 2*spriteH)))
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




