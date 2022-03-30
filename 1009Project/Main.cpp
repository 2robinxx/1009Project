#include <SFML/Graphics.hpp>
#include "Player.h"
#include "GamePanel.h"


int main()
{
    GamePanel gamePanel;
    


    //Initialize random seed
    srand(static_cast<unsigned>(time(0)));

    while (gamePanel.getWindowIsOpen())
    {
        //playSound
        
        gamePanel.update();
        
        gamePanel.render();
        
        
    }

    return 0;
}
