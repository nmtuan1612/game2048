#include "gameover.h"
#include <iostream>
using namespace std;

GameOver::GameOver(sf::RenderWindow& _window) : window(_window) {
    if (!font.loadFromFile("font/FFF_Tusj.ttf"))
    {
        cout << "Error loading FFF_Tusj.ttf" << endl;
    }
    text.setFont(font);
    text.setString("Game Over !");
    text.setCharacterSize(50); // in pixels, not points!
    // set the color
    text.setFillColor(sf::Color(92, 92, 92));
    // set the text style
    text.setStyle(sf::Text::Bold );
    text.setPosition(sf::Vector2f(300, 190));
}

void GameOver::drawGameOver() {
    window.draw(text);
    sf::Texture texture;
    if (!texture.loadFromFile("2048_images/try_again.png"))
    {
        cout << "Error loading 2048_images/try_again.png" << endl;
    }
    sf::Sprite imageTry;
    imageTry.setTexture(texture);
    imageTry.setPosition(sf::Vector2f(380, 280));
    window.draw(imageTry);
}
