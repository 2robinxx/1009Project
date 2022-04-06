#include "MapSelection.h"
#include <iostream>

using namespace std;

MapSelection::MapSelection()
{
    selectedItemIndex = 0;

    upPress = sf::Keyboard::Key::Up;
    downPress = sf::Keyboard::Key::Down;
    enterPress = sf::Keyboard::Key::Enter;
}

void MapSelection::draw(sf::RenderTarget& target, int height, int width)
{

    if (!font.loadFromFile("Fonts/game_sans_serif_7.ttf"))
    {
        cout << "ERROR LOADING FONT!" << endl;
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
    option[0].setString("Underground");
    option[0].setPosition(sf::Vector2f(width / 2.f, height / (itemSelection + 1)));

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
    option[1].setString("Ice");
    option[1].setPosition(sf::Vector2f(width / 2.f, height / (itemSelection + 1) + 100));

    for (int i = 0; i < itemSelection; i++)
    {
        target.draw(option[i]);
    }
}

void MapSelection::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        selectedItemIndex--;
    }
}

void MapSelection::MoveDown()
{
    if (selectedItemIndex + 1 < itemSelection)
    {
        selectedItemIndex++;
    }
}


int MapSelection::toggleMenu()
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

    if (sf::Keyboard::isKeyPressed(upPress))
    {
        MoveUp();
    }

    if (sf::Keyboard::isKeyPressed(enterPress))
    {
        enterPressKey = 1;
        return selectedItemIndex;
    }
}




