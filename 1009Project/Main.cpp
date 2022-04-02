#include <SFML/Graphics.hpp>
#include "GamePanel.h"
#include "highscore.h"


int main()
{
    GamePanel gamePanel;
    highscore hs;
    //create a highscore file
    
    //Initialize random seed
    srand(static_cast<unsigned>(time(0)));
    
    while (gamePanel.getWindowIsOpen())
    {
        gamePanel.update();
        gamePanel.render();
    }

    return 0;
}
