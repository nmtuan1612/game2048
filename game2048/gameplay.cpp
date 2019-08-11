#include "gameplay.h"
#include <iostream>
using namespace std;

void GamePlay::newGame()
{
    for (int i = 0; i < 16; i++) {
        board[i] = 0;
    }
    score = 0;
    int add1, add2;
    add1 = rand() % 16;
    add2 = rand() % 16;
    board[add1] = 2;
    board[add2] = 2;
}

void GamePlay::addPiece()
{
    int occupied = 1, add;
    while (occupied)
    {
        add = rand() % 16; //cout << add << "\n";
        if (board[add] == 0)
            occupied = 0;
    }
    board[add] = 2;
}


void GamePlay::updateGame (int direction){
    int canAdd = 0;
    if (direction == 8){
        cout << "Move up" << endl;
        moveUp();
    }
    else if (direction == 2){
        cout << "move down" << endl;
        moveDown();
    }
    else if (direction == 4){
        cout << "move left" << "\n";
        moveLeft();
    }
    else if (direction == 6){
        cout << "move right" << endl;;
        moveRight();
    }
    cout << score << endl;
}

void GamePlay::moveUp() {
    for (int k = 0; k < 4; k++)           // chạy 4 lần
    {
        for (int i = 4; i < 16; i++)       //vì hàng đầu k di chuyển nên chỉ xét 12 ô dưới
        {
            if (board[i - 4] == 0)            // nếu ô trên bằng 0 và ô dưới khác 0 thì đẩy ô dưới lên
            {
                if (board[i] != 0)
                {
                    canAdd = 1;
                    boardCheck[i - 4] = boardCheck[i];
                    boardCheck[i] = 0;
                }
                board[i - 4] = board[i];
                board[i] = 0;
            }
            if (board[i - 4] == board[i] && board[i] != 0 && boardCheck[i - 4] == 0 && boardCheck[i] == 0)
            {
                board[i - 4] += board[i - 4];         // cộng 2 ô bằng nhau lại
                board[i] = 0;
                boardCheck[i - 4] = 1;
                canAdd = 1;
                score += board[i - 4];
            }
        }
    }
    for (int i = 0; i < 16; i++) {
        boardCheck[i] = 0;
    }
    if (canAdd == 1) {                  // nếu di chuyển thì thêm một ô bất kì vào bảng
        addPiece();
        canAdd = 0;
    }
}

void GamePlay::moveDown() {
    for (int k = 0; k < 4; k++)    //chạy 4 lần
    {
        for (int i = 11; i >= 0; i--)   //vì hàng cuối k di chuyển nên chỉ xét 12 ô đầu
        {
            if (board[i + 4] == 0)     // nếu ô dưới bằng 0 và ô trên khác 0 thì đẩy ô trên xuống
            {
                if (board[i] != 0)
                {
                    canAdd = 1;
                    boardCheck[i + 4] = boardCheck[i];
                    boardCheck[i] = 0;
                }
                board[i + 4] = board[i];
                board[i] = 0;
            }
            if (board[i + 4] == board[i] && board[i] != 0 && boardCheck[i] == 0 && boardCheck[i + 4] == 0)
            {
                board[i + 4] += board[i + 4];                // nếu 2 ô bằng nhau thì cộng lại
                board[i] = 0;
                boardCheck[i + 4] = 1;
                canAdd = 1;
                score += board[i + 4];
            }
        }
    }
    for (int i = 0; i < 16; i++) {
        boardCheck[i] = 0;
    }
    if (canAdd == 1) {                  // nếu di chuyển thì thêm một ô bất kì vào bảng
        addPiece();
        canAdd = 0;
    }
}

void GamePlay::moveLeft() {
    for (int k = 0; k < 4; k++)        //chạy 4 lần
    {
        for (int i = 0; i < 16; i++)
        {
            if (i != 0 && i != 4 && i != 8 && i != 12)             //vì hàng bên trái k di chuyển nên chỉ xét 12 ô bên phải
            {
                if (board[i - 1] == 0)                // nếu ô trái bằng 0 và ô phải khác 0 thì đẩy ô phải sang
                {
                    if (board[i] != 0)
                    {
                        canAdd = 1;
                        boardCheck[i - 1] = boardCheck[i];
                        boardCheck[i] = 0;
                    }
                    board[i - 1] = board[i];
                    board[i] = 0;
                }
                if (board[i - 1] == board[i] && board[i] != 0 && boardCheck[i - 1] == 0 && boardCheck[i] == 0)
                {
                    board[i - 1] += board[i - 1];              // nếu 2 ô bằng nhau thì cộng lại
                    board[i] = 0;
                    boardCheck[i - 1] = 1;
                    canAdd = 1;
                    score += board[i - 1];
                }
            }
        }
    }
    for (int i = 0; i < 16; i++) {
        boardCheck[i] = 0;
    }
    if (canAdd == 1) {                  // nếu di chuyển thì thêm một ô bất kì vào bảng
        addPiece();
        canAdd = 0;
    }
}

void GamePlay::moveRight() {
    for (int k = 0; k < 4; k++)    //chạy 4 lần
    {
        for (int i = 15; i >= 0; i--)
        {
            if (i != 3 && i != 7 && i != 11 && i != 15)        //vì hàng bên phải k di chuyển nên chỉ xét 12 ô bên trái
            {
                if (board[i + 1] == 0)                 // nếu ô phải bằng 0 và ô trái khác 0 thì đẩy ô trái sang
                {
                    if (board[i] != 0)
                    {
                        canAdd = 1;
                        boardCheck[i + 1] = boardCheck[i];
                        boardCheck[i] = 0;
                    }
                    board[i + 1] = board[i];
                    board[i] = 0;
                }
                if (board[i + 1] == board[i] && board[i] != 0 && boardCheck[i] == 0 && boardCheck[i + 1] == 0)
                {
                    board[i + 1] += board[i + 1];           // nếu 2 ô bằng nhau thì cộng lại
                    board[i] = 0;
                    boardCheck[i + 1] = 1;
                    canAdd = 1;
                    score += board[i + 1];
                }
            }
        }
    }
    for (int i = 0; i < 16; i++) {
        boardCheck[i] = 0;
    }
    if (canAdd == 1) {                  // nếu di chuyển thì thêm một ô bất kì vào bảng
        addPiece();
        canAdd = 0;
    }
}

bool GamePlay::checkGameOver()
{
    int count = 0;
    int count1 = 0;
    for (int i = 0; i < 16; i++) {
        if (board[i] != 0) count++;

    }
    if (count == 16)
    {
        for (int j = 0; j < 16; j++)
        {
            if (j == 0 && board[j] != board[j + 1] && board[j] != board[j + 4]) count1++;
            if (j == 1 && board[j] != board[j + 1] && board[j] != board[j - 1] && board[j] != board[j + 4]) count1++;
            if (j == 2 && board[j] != board[j + 1] && board[j] != board[j - 1] && board[j] != board[j + 4]) count1++;
            if (j == 3 && board[j] != board[j - 1] && board[j] != board[j + 4]) count1++;
            if (j == 4 && board[j] != board[j + 1] && board[j] != board[j + 4] && board[j] != board[j - 4]) count1++;
            if (j == 5 && board[j] != board[j + 1] && board[j] != board[j - 1] && board[j] != board[j + 4] && board[j] != board[j - 4]) count1++;
            if (j == 6 && board[j] != board[j + 1] && board[j] != board[j - 1] && board[j] != board[j + 4] && board[j] != board[j - 4]) count1++;
            if (j == 7 && board[j] != board[j - 1] && board[j] != board[j + 4] && board[j] != board[j - 4]) count1++;
            if (j == 8 && board[j] != board[j + 1] && board[j] != board[j + 4] && board[j] != board[j - 4]) count1++;
            if (j == 9 && board[j] != board[j + 1] && board[j] != board[j - 1] && board[j] != board[j + 4] && board[j] != board[j - 4]) count1++;
            if (j == 10 && board[j] != board[j + 1] && board[j] != board[j - 1] && board[j] != board[j + 4] && board[j] != board[j - 4]) count1++;
            if (j == 11 && board[j] != board[j - 1] && board[j] != board[j + 4] && board[j] != board[j - 4]) count1++;
            if (j == 12 && board[j] != board[j + 1] && board[j] != board[j - 4]) count1++;
            if (j == 13 && board[j] != board[j + 1] && board[j] != board[j - 1] && board[j] != board[j - 4]) count1++;
            if (j == 14 && board[j] != board[j + 1] && board[j] != board[j - 1] && board[j] != board[j - 4]) count1++;
            if (j == 15 && board[j] != board[j - 1] && board[j] != board[j - 4]) count1++;
        }
        if (count1 == 16)
        {
            std::cout << "Game over !" << endl;;
            return true;
        }
    }
    return false;
}

void GamePlay::drawImages ()
{
    sf::Texture image2, image4, image8, image16, image32, image64, image128, image256, image512, image1024, image2048, image4096;
    image2.loadFromFile("2048_images/2.bmp");
    image4.loadFromFile("2048_images/4.bmp");
    image8.loadFromFile("2048_images/8.bmp");
    image16.loadFromFile("2048_images/16.bmp");
    image32.loadFromFile("2048_images/32.bmp");
    image64.loadFromFile("2048_images/64.bmp");
    image128.loadFromFile("2048_images/128.bmp");
    image256.loadFromFile("2048_images/256.bmp");
    image512.loadFromFile("2048_images/512.bmp");
    image1024.loadFromFile("2048_images/1024.bmp");
    image2048.loadFromFile("2048_images/2048.bmp");
    image4096.loadFromFile("2048_images/4096.bmp");
    sf::Sprite Image2(image2), Image4(image4), Image8(image8), Image16(image16), Image32(image32), Image64(image64),
        Image128(image128), Image256(image256), Image512(image512), Image1024(image1024), Image2048(image2048), Image4096(image4096);
    for (int i = 0; i < 16; i++)
    {
        if (board[i] == 2) {
            Image2.setPosition(sf::Vector2f(5 + 105 * (i % 4), 5 + 105 * (i / 4)));
            window.draw(Image2);
        }
        if (board[i] == 4) {
            Image4.setPosition(sf::Vector2f(5 + 105 * (i % 4), 5 + 105 * (i / 4)));
            window.draw(Image4);
        }
        if (board[i] == 8) {
            Image8.setPosition(sf::Vector2f(5 + 105 * (i % 4), 5 + 105 * (i / 4)));
            window.draw(Image8);
        }
        if (board[i] == 16) {
            Image16.setPosition(sf::Vector2f(5 + 105 * (i % 4), 5 + 105 * (i / 4)));
            window.draw(Image16);
        }
        if (board[i] == 32) {
            Image32.setPosition(sf::Vector2f(5 + 105 * (i % 4), 5 + 105 * (i / 4)));
            window.draw(Image32);
        }
        if (board[i] == 64) {
            Image64.setPosition(sf::Vector2f(5 + 105 * (i % 4), 5 + 105 * (i / 4)));
            window.draw(Image64);
        }
        if (board[i] == 128) {
            Image128.setPosition(sf::Vector2f(5 + 105 * (i % 4), 5 + 105 * (i / 4)));
            window.draw(Image128);
        }
        if (board[i] == 256) {
            Image256.setPosition(sf::Vector2f(5 + 105 * (i % 4), 5 + 105 * (i / 4)));
            window.draw(Image256);
        }
        if (board[i] == 512) {
            Image512.setPosition(sf::Vector2f(5 + 105 * (i % 4), 5 + 105 * (i / 4)));
            window.draw(Image512);
        }
        if (board[i] == 1024) {
            Image1024.setPosition(sf::Vector2f(5 + 105 * (i % 4), 5 + 105 * (i / 4)));
            window.draw(Image1024);
        }
        if (board[i] == 2048) {
            Image2048.setPosition(sf::Vector2f(5 + 105 * (i % 4), 5 + 105 * (i / 4)));
            window.draw(Image2048);
        }
        if (board[i] == 4096) {
            Image4096.setPosition(sf::Vector2f(5 + 105 * (i % 4), 5 + 105 * (i / 4)));
            window.draw(Image4096);
        }
    }
}

void GamePlay::drawScore()
{
    sf::Font font;
    sf::Text text;
    int Score = score;
    int dx = 48;

    if (!font.loadFromFile("font/mvboli.ttf"))
    {
        cout << "Error loading mvboli.ttf" << endl;
    }
    text.setFont(font);
    text.setCharacterSize(30); // in pixels, not points!
    text.setFillColor(sf::Color::Black);    // set the color
    text.setStyle(sf::Text::Bold );         // set the text style

    vector <int> so;
    if (Score == 0) so.push_back(0);
    while (Score != 0){
        so.insert(so.begin(), Score % 10);
        Score /= 10;
    }
    for (int i : so){
        auto c = to_string(i);
        text.setPosition(sf::Vector2f(dx, 485));
        text.setString(c);
        window.draw(text);
        dx += 20;
    }
}
