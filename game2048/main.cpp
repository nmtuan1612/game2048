#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

#include "status.h"
using namespace std;

int main()
{
    // create the window
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tuan_2048");

    Status status(window);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
               //status.processEvent(event);
               status.updateStatus();
               int X = sf::Mouse::getPosition(window).x;
               int Y = sf::Mouse::getPosition(window).y;
               if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && X > 265 && Y > 458 && X < 426 && Y < 515) {
                    cout << X  << ' ' << Y << endl;
                    status.play.newGame();
                    break;
               }
               else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && X > 380 && Y > 280 && X < 380 + 124 && Y < 280+46) {
                    cout << X  << ' ' << Y << endl;
                    status.play.newGame();
                    break;
               }
               //status.play.drawScore();
        }
        status.displayStatus();
    }

    return 0;
}

