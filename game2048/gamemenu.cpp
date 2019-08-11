#include "gamemenu.h"
#include <iostream>
using namespace std;

GameMenu::GameMenu() {
    if (!texture.loadFromFile("2048_images/menu1.png"))
    {
        cout << "Error loading menu1.png" << endl;
    }
    Menu.setTexture(texture);
}
