#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "menu.h"
#include "Ball.h"
// #include "background.cpp"
using namespace std;

bool debug = false;

int main()
{
    // gameState is 0 if menu, 1 if game is playing, 2 if configuring options
    int gameState = 0;

    //testing sound
    sf::Music music;
    music.openFromFile("resources/audio/StarWarsSong.ogg");
    if (!music.openFromFile("resources/audio/StarWarsSong.ogg"))
    {
        cout << "cannot load song" << endl;
    }

    music.setVolume(50);         // reduce the volume
    music.setLoop(true);        // set loop

    music.play();

    // Background t(2); // testing from background.h -> will later implement

    // configuring display window
    int resX = 1280, resY = 720;
    int newH = (1920*resY)/resX;
    int displace = (newH - 1080)/(-2);
    sf::RenderWindow window(sf::VideoMode(resX, resY), "Star Wars Pong");
    window.setFramerateLimit(60);
    // window.setView(sf::View(sf::FloatRect(0, displace, 1920, newH)));

    Menu menu(window.getSize().x, window.getSize().y);

    // background file loading
    sf::Texture backgroundTexture1;
    sf::Texture * textures = new sf::Texture[675];
    string address, num;
    for (int i = 0; i < 675; i++) {
        ostringstream convert;
        convert << setw(5) << setfill('0') << i + 1;
        if (!textures[i].loadFromFile("resources/images/Background/flying/background"+convert.str()+".jpg")) {
            cout << "cannot load background: " << i + 1 << endl;
        }
    }

    sf::Sprite background;
    background.setTexture(textures[0]);
    background.setScale(1,820/720);


    // game item files loading
    sf::Texture paddleTexture;
    if (!paddleTexture.loadFromFile(string("resources/images/BlueLightsaber2.png"))) {
        cout << "mistake" << endl;
    }

    sf::Sprite paddle;
    paddle.setTexture(paddleTexture);

    Ball ball(sf::Vector2f(50,50), sf::Vector2f(3,3), "resources/images/death_star.png");

    sf::Clock Clock;
    int direction = 1;
    short backgroundCounter = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (gameState == 0) {
                switch(event.type) {
                    case sf::Event::KeyReleased:
                        switch (event.key.code) {
                            case sf::Keyboard::Up:
                                std::cout << "Up button has been pressed " << menu.GetPressedItem() << std::endl;
                                menu.MoveUp();
                                break;

                            case sf::Keyboard::Down:
                                menu.MoveDown();
                                std::cout << "Down button has been pressed: " << menu.GetPressedItem() << std::endl;
                                break;

                            case sf::Keyboard::Return:
                                switch (menu.GetPressedItem()) {
                                    case 0:
                                        gameState = 1;
                                        std::cout << "Play button has been pressed" << std::endl;
                                        break;
                                    case 1:
                                        gameState = 2;
                                        std::cout << "Option button has been pressed" << std::endl;
                                        break;
                                    case 2:
                                        window.close();
                                        break;
                                }
                        }
                }
            }
        }

        window.clear();

        if (gameState == 1) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                // up key is pressed: move our character
                paddle.move(0, -1);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                // down key is pressed: move our character
                paddle.move(0, 1);
            }

            if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds())) {
                // window.clear();
                if (debug) {
                    cout << "COLLISION" << endl;
                }
            } else {
                // window.display();
                if (debug) {
                    cout << "Not Collision" << endl;
                }
            }

            if(backgroundCounter >= 675) backgroundCounter = 0;
            background.setTexture(textures[backgroundCounter]);
            backgroundCounter++;

            ball.cont(window);

            window.draw(background);
            window.draw(paddle);
            window.draw(ball);
        }

        if (gameState == 0) {
            menu.draw(window);
        }
        window.display();
    }

    return 0;
}
