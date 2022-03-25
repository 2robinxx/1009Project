#include <SFML/Graphics.hpp>
#include "Player.h"
#include "GamePanel.h"

int main()
{
    GamePanel gamePanel;




    while (gamePanel.getWindowIsOpen())
    {
        //playSound

        gamePanel.update();

        gamePanel.render();
    }

    return 0;
}
