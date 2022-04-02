#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

enum objectType {DEFAULT = 0, DAMAGING, HEALING, NOFT};

class Object
{
private:
	sf::RectangleShape sprite;
	sf::Texture imgSprite;
	int type;

	
public:
	Object(const sf::RenderWindow& window, int type);
	virtual ~Object();

	//Accessor
	const sf::RectangleShape getObject() const;
	const int& getType() const;


	//Function
	void update();
	void render(sf::RenderTarget& target);

	void initObject(const sf::RenderWindow& window);

};
