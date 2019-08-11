#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <SFML/Graphics.hpp>

struct GameOver
{
    sf::Font font;
    sf::Text text;
    sf::RenderWindow& window;

    GameOver(sf::RenderWindow& _window);

    void drawGameOver();
};

#endif // GAMEOVER_H
