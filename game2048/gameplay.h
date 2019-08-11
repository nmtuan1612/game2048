#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <SFML/Graphics.hpp>

struct GamePlay {
    int board[16] = { 0 };
    int boardCheck[16] = { 0 };
    int score = 0;
    int canAdd = 0;
    bool gameOver = false;
    sf::RenderWindow& window;

    GamePlay(sf::RenderWindow& _window): window(_window) {
    }

    void newGame();
    void addPiece();
    void drawImages ();     // In ra anh tuong ung voi so
    void updateGame (int direction);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    bool checkGameOver();
	void drawScore();
};

#endif // GAMEPLAY_H
