#pragma once

#include <SFML\Audio.hpp>

using namespace std;

class Sound {

	sf::Sound sound;
	sf::SoundBuffer buffer;

public:

	void setBuffer(string);
	void playSound();
	void setLoop();

};
