#include <SFML/Graphics.hpp>
#include "Player.h"
#include "GamePanel.h"

int main()
{
    GamePanel gamePanel;

    //Inititalize random seed
    srand(static_cast<unsigned>(time(0)));

    while (gamePanel.getWindowIsOpen())
    {
        gamePanel.update();

        gamePanel.render();
    }

    return 0;
}
