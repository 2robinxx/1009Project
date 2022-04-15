#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu()
{
    selectedItemIndex = 0;

    upPress = sf::Keyboard::Key::Up;
    downPress = sf::Keyboard::Key::Down;
    enterPress = sf::Keyboard::Key::Enter;

 
}
void Menu::drawTitle(sf::RenderTarget& target)
{
    this->font.loadFromFile("Fonts/game_sans_serif_7.ttf");
    this->gameTitle.setString("Dino Jump");
    this->gameTitle.setFont(this->font);
    this->gameTitle.setFillColor(sf::Color::White);
    this->gameTitle.setCharacterSize(100.f);
    this->gameTitle.setPosition(sf::Vector2f(120.f,60.f));

    this->gameIconImg.loadFromFile("Sprites/player/dino_idle.png");
    this->gameIconSprite.setTexture(gameIconImg);
    this->gameIconSprite.setScale(sf::Vector2f(7, 7));
    this->gameIconSprite.setPosition(sf::Vector2f(250.f, 250));

    this->gameIconImg2.loadFromFile("Sprites/player/dino2_idle.png");
    this->gameIconSprite2.setTexture(gameIconImg2);
    this->gameIconSprite2.setScale(sf::Vector2f(7, 7));
    this->gameIconSprite2.setPosition(sf::Vector2f(400.f, 250));
   
    target.draw(gameTitle);
    target.draw(gameIconSprite);
    target.draw(gameIconSprite2);

}
void Menu::draw(sf::RenderTarget& target, int height, int width)
{

    if (!font.loadFromFile("Fonts/game_sans_serif_7.ttf"))
    {

        // error handling if file not loaded
    }


    //Menu 1
    option[0].setFont(font);

    if (selectedItemIndex == 0)
    {
        option[0].setFillColor(sf::Color::Red);
    }
    else
    {
        option[0].setFillColor(sf::Color::White);
    }

    option[0].setString("Play");
    option[0].setCharacterSize(50);
    //option[0].setPosition(sf::Vector2f(width / 2, height / (itemSelection + 1) * 1));
    option[0].setPosition(sf::Vector2f((width / 3.f), height / (itemSelection + 1)+300));

    //Menu 2
    option[1].setFont(font);
    if (selectedItemIndex == 1)
    {
        option[1].setFillColor(sf::Color::Red);
    }
    else
    {
        option[1].setFillColor(sf::Color::White);
    }

    option[1].setString("Select Map");
    option[1].setCharacterSize(50);
    option[1].setPosition(sf::Vector2f((width / 3.f)-70, height / (itemSelection + 1) + 400));



    //Menu 3
    option[2].setFont(font);
    if (selectedItemIndex == 2)
    {
        option[2].setFillColor(sf::Color::Red);
    }
    else
    {
        option[2].setFillColor(sf::Color::White);
    }

    option[2].setString("Quit");
    option[2].setCharacterSize(50);
    option[2].setPosition(sf::Vector2f((width / 3.f), height / (itemSelection + 1) + 500));

   



    for (int i = 0; i < itemSelection; i++)
    {

        target.draw(option[i]);
    }
}

void Menu::MoveUp()
{

    if (selectedItemIndex - 1 >= 0)
    {
        selectedItemIndex--;
    }
}

void Menu::MoveDown()
{

    if (selectedItemIndex + 1 < itemSelection)
    {
        selectedItemIndex++;
    }
}


int Menu::toggleMenu()
{
    enterPressKey = 0;
    if (sf::Keyboard::isKeyPressed(upPress))
    {
        MoveUp();
    }

    if (sf::Keyboard::isKeyPressed(downPress))
    {
        MoveDown();
    }

    if (sf::Keyboard::isKeyPressed(enterPress))
    {
        enterPressKey = 1;
        return selectedItemIndex;
    }

}




