#ifndef STATUS_H
#define STATUS_H

#include <SFML/Graphics.hpp>
#include "gamemenu.h"
#include "gameplay.h"
#include "gameover.h"

struct Status {
    sf::RenderWindow& window;
    GameMenu gamemenu;
    GamePlay play;
    GameOver gameover;

    Status(sf::RenderWindow& _window) : window(_window), play(_window), gameover(_window) {}

    void displayStatus();

    void updateStatus();
};

#endif // STATUS_H
