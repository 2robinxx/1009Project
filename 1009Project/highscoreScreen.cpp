#include "highscoreScreen.h"
using namespace std;


highscoreScreen::highscoreScreen()
{
    

    upPress = sf::Keyboard::Key::Up;
    downPress = sf::Keyboard::Key::Down;
    enterPress = sf::Keyboard::Key::Enter;


}
void highscoreScreen::drawTitle(sf::RenderTarget& target)
{
    this->font.loadFromFile("Fonts/game_sans_serif_7.ttf");
    this->Title.setString("Top 10 Timing");
    this->Title.setFont(this->font);
    this->Title.setFillColor(sf::Color::White);
    this->Title.setCharacterSize(70.f);
    this->Title.setPosition(sf::Vector2f(140.f, 40.f));
    target.draw(Title);
}






