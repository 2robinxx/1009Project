#include "EndScreen.h"
#include <iostream>
using namespace std;
EndScreen::EndScreen()
{
    
    selectedItemIndex = 0;

    upPress = sf::Keyboard::Key::Up;
    downPress = sf::Keyboard::Key::Down;
    enterPress = sf::Keyboard::Key::Enter;
}

void EndScreen::draw(sf::RenderTarget& target, int height, int width)
{

    if (!font.loadFromFile("Fonts/game_sans_serif_7.ttf"))
    {

        // error handling if file not loaded
    }

    if (playerwon == 1) {

        statement.setFont(font);
        statement.setFillColor(sf::Color::White);
        statement.setString("Player 1 win");
        statement.setCharacterSize(80);
        statement.setPosition(sf::Vector2f(140.f, 70.f));
       
    }
    else if (playerwon == 2) {

        statement.setFont(font);
        statement.setFillColor(sf::Color::White);
        statement.setString("Player 2 win");
        statement.setCharacterSize(80);
        statement.setPosition(sf::Vector2f(140.f, 70.f));
    
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

    option[0].setString("Play Again");
    //option[0].setPosition(sf::Vector2f(width / 2, height / (itemSelection + 1) * 1));
    option[0].setCharacterSize(50);
    option[0].setPosition(sf::Vector2f((width / 3.f)-70, height / (itemSelection + 1) + 300));



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

    option[1].setString("Quit");
    option[1].setCharacterSize(50);
    option[1].setPosition(sf::Vector2f((width / 3.f), height / (itemSelection + 1) + 400));

    

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

    option[2].setString("Highscores");
    option[2].setCharacterSize(50);
    option[2].setPosition(sf::Vector2f((width / 3.f)-70, height / (itemSelection + 1) + 500));

    target.draw(statement);

    for (int i = 0; i < itemSelection; i++)
    {
        target.draw(option[i]);
    }

    


}

void EndScreen::MoveUp()
{

    if (selectedItemIndex - 1 >= 0)
    {
        selectedItemIndex--;
    }
}

void EndScreen::MoveDown()
{
    if (selectedItemIndex + 1 < itemSelection)
    {
        selectedItemIndex++;
    }
}


int EndScreen::toggleMenu()
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
