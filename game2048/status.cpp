#include "status.h"
#include <iostream>
using namespace std;
void Status::displayStatus()
{
    // clear the window with black colora
    window.clear(sf::Color::Black);

    // draw everything here...
    // window.draw(...);
    window.draw(gamemenu.Menu);
    play.drawImages();
    play.drawScore();
    if (play.checkGameOver() != play.gameOver) {
        gameover.drawGameOver();
    }
    // end the current frame
    window.display();
}

void Status::updateStatus() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        play.updateGame(8);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        play.updateGame(2);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        play.updateGame(4);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        play.updateGame(6);
    }
    int X = sf::Mouse::getPosition(window).x;
    int Y = sf::Mouse::getPosition(window).y;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && X > 265 && Y > 458 && X < 426 && Y < 515) {
        play.newGame();
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && X > 380 && Y > 280 && X < 380 + 124 && Y < 280+46) {
        cout << X  << ' ' << Y << endl;
        play.newGame();
    }
}
