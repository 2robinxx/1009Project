#include "Sound.h"

using namespace std;

void Sound::setBuffer(string s) {


	if (!buffer.loadFromFile(s)) {

		//Print Error
	}

	sound.setBuffer(buffer);

}

void Sound::setLoop() {

	sound.setLoop(1);

}

void Sound::playSound() {

	sound.play();

}






