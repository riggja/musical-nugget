#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <sstream>
#include <math.h>
#include "menu.h"
#include "Ball.h"
#include "Paddle.h"
#include "Scoreboard.h"

using namespace std;

// Gets the distance between two sprites
float getSpriteDistance(sf::Sprite &sprt1, sf::Sprite &sprt2);

// Handles input
void checkInput(sf::RenderWindow &window, Paddle &paddle1, Paddle &paddle2, Ball &ball);

// Selects and plays one of two background songs
void chooseSong(bool);

// The global music player
sf::Music music;

// Plays one of four lightsaber sound effects
void playLsSound(unsigned int);

// The lightsaber sound buffer
sf::SoundBuffer lsSoundBuffer;
sf::Sound lsSound;

// Plays one of two "Nooo" sounds
void playNoSound(bool);

// The lightsaber sounud buffer
sf::SoundBuffer noSoundBuffer;
sf::Sound noSound;

int main()
{
    lsSound.setBuffer(lsSoundBuffer);
    noSound.setBuffer(noSoundBuffer);

    // Random number to decide song/sound
    srand(time(NULL));

    // GameState is 0 if menu and 1 if game is playing
    int gameState = 0;

    // Configuring display window
    int resX = 1280, resY = 720;
    int newH = (1920*resY)/resX;
    int displace = (newH - 1080)/(-2);
    sf::RenderWindow window(sf::VideoMode(resX, resY), "Star Wars Pong");
    window.setFramerateLimit(60);

    Menu menu(window.getSize().x, window.getSize().y);
    
    // Loads Loading Screen Image
    sf::Texture loadingTexture;
    if (!loadingTexture.loadFromFile("resources/images/menu/loading.png")) {
      cout << "cannot load loading image" << endl;
    }
    sf::Sprite background;
    background.setTexture(loadingTexture);
    background.setScale(.9,1);
    window.draw(background);
    window.display();

    // Loads Logo
    sf::Texture logo;
    if (!logo.loadFromFile("resources/images/menu/logo.png")) {
      cout << "cannot load menu" << endl;
    }
    sf::Sprite starWars;
    starWars.setTexture(logo);
    starWars.setScale(.2,.2);
    
    // Loads Death Star Animations
    sf::Texture * deadStarTextures = new sf::Texture[11];
    for (int i = 0; i <= 10; i++) {
        ostringstream convert;
        convert << setw(2) << setfill('0') << i;
        if (!deadStarTextures[i].loadFromFile("resources/images/death_star/death"+convert.str()+".png")) {
            cout << "cannot load background: " << i << endl;
        }
    }
    
    // Loads Background Gif
    sf::Texture * textures = new sf::Texture[675];
    for (int i = 0; i < 675; i++) {
        ostringstream convert;
        convert << setw(5) << setfill('0') << i + 1;
        if (!textures[i].loadFromFile("resources/images/background/flying/background"+convert.str()+".jpg")) {
            cout << "cannot load background: " << i + 1 << endl;
        }
    }
    background.setTexture(textures[0]);
    background.setScale(1,820/720);

    // Loads Music Files
    music.openFromFile("resources/audio/StarWarsSong.ogg");
    if (!music.openFromFile("resources/audio/StarWarsSong.ogg"))
    {
        cout << "cannot load song" << endl;
    }
    music.setVolume(50);         // Reduce the volume
    music.play();

    // Loads Lightsaber Textures
    Paddle paddle1(sf::Vector2f(10,0), "resources/images/lightsaber/lightsaber_blue.png");
    Paddle paddle2(sf::Vector2f(window.getSize().x-paddle2.getGlobalBounds().width-30,0), "resources/images/lightsaber/lightsaber_red.png");
    
    // Instantiates Ball Object
    Ball * ball = new Ball(sf::Vector2f(50,500), 5, 0, "resources/images/death_star/death_star.png");

    // Initialize Scoreboard
    Scoreboard score(window);

    short backgroundCounter = 0;
    short deadStarCounter = 0;

    while (window.isOpen())
    {
        // Scrolls through background images
        if(backgroundCounter >= 675) backgroundCounter = 0;
        background.setTexture(textures[backgroundCounter]);
        backgroundCounter++;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            window.close();

            // Press X to go to Menu
            if (event.key.code == sf::Keyboard::X) {
              gameState = 0;
            }
            
            // Menu Screen
            if (gameState == 0) {
                // Displays Logo
                starWars.setPosition(resX/2 - 130,0);
                switch(event.type) {
                    case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;

                        case sf::Keyboard::Return:
                        switch (menu.GetPressedItem()) {
                            case 0:
                            // Plays Game
                                gameState = 1;
                                music.stop();
                                chooseSong(rand() % 2);
                                break;
                            case 1:
                            // Exits Game
                            window.close();

                            break;
                        }
                    }
                }
            }
        }

        window.clear();

        if (gameState == 1) {

            checkInput(window, paddle1, paddle2, *ball);
            
            // if ball collides with paddle, increases ball and paddle speed
            if (ball->getGlobalBounds().intersects(paddle1.getGlobalBounds())) {
                ball->setVelAngle(getSpriteDistance(paddle1, *ball)*ball->maxAngle);
                paddle2.setMaxSpeed(ball->increaseSpeed());
                // Plays sound effect
                playLsSound(rand() % 5);

            } else if (ball->getGlobalBounds().intersects(paddle2.getGlobalBounds())) {
                ball->setVelAngle(getSpriteDistance(paddle2, *ball)*ball->maxAngle);
                ball->reverseDir();
                paddle1.setMaxSpeed(ball->increaseSpeed());
                //plays sound effect
                playLsSound(rand() % 5);
            }
            
            char ballResult = ball->cont(window);
            // If ball is out of bounds, play Death Star destruction sequence and generate new Ball
            if (ballResult) {
                if (!deadStarCounter) {
                    // Play the explosion sound effect; we'll just borrow the lightsaber buffer, since it won't play at the same time.
                    lsSoundBuffer.loadFromFile("resources/audio/explosion.wav");
                    lsSound.play();
                }
                if (deadStarCounter <= 10) {
                    ball->setTexture(deadStarTextures[deadStarCounter++]);
                } else {
                    delete ball;

                    sf::Vector2f initVel;

                    // awards score to scoring player
                    score.score(ballResult);
                    
                    if (ballResult == 1) {
                        // Player 1 Scores
                        initVel = sf::Vector2f(-3,-3);
                        playNoSound(0);
                    } else {
                        // Player 2 Scores
                        initVel = sf::Vector2f(3,3);
                        playNoSound(1);
                    }

                    // return to menu upon one player winning
                    if (score.hasWon(11)) {
                      gameState = 0;
                    }

                    ball = new Ball(sf::Vector2f(500,500), 5, M_PI, "resources/images/death_star/death_star.png");
                    deadStarCounter = 0;
                }
            }
            
            // Draw Game Elements
            window.draw(background);
            window.draw(paddle1);
            window.draw(paddle2);
            window.draw(*ball);
            score.draw(window);
        }

        if (gameState == 0) {
            // Draw Menu Elements
            window.draw(background);
            window.draw(starWars);
            menu.draw(window);
        }
        window.display();
    }
    
    // Frees Heap
    delete [] textures;
    delete [] deadStarTextures;

    return 0;
}



void checkInput(sf::RenderWindow &window, Paddle &paddle1, Paddle &paddle2, Ball &ball) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        paddle1.setIsAI(false);
        paddle1.cont(window, -1);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        paddle1.setIsAI(false);
        paddle1.cont(window, 1);
    } else {
        if(paddle1.getIsAI()) {
            float dir = getSpriteDistance(paddle1, ball);
            if(dir > 0) {
                paddle1.cont(window, -1);
            } else if (!dir) {
                paddle1.cont(window, 0);
            } else {
                paddle1.cont(window, 1);
            }
        } else {
            paddle1.cont(window, 0);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        // up key is pressed: move our character
        paddle2.setIsAI(false);
        paddle2.cont(window, -1);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        // down key is pressed: move our character
        paddle2.setIsAI(false);
        paddle2.cont(window, 1);
    } else {
        if(paddle2.getIsAI()) {
            float dir = getSpriteDistance(paddle2, ball);
            if(dir > 0) {
                paddle2.cont(window, -1);
            } else if (!dir) {
                paddle2.cont(window, 0);
            } else {
                paddle2.cont(window, 1);
            }
        } else {
            paddle2.cont(window, 0);
        }

    }
}



float getSpriteDistance(sf::Sprite &sprt1, sf::Sprite &sprt2) {
    // Gets the size of the paddles
    float center1 = sprt1.getPosition().y + ((sprt1.getGlobalBounds().height)/2);
    float center2 = sprt2.getPosition().y + ((sprt2.getGlobalBounds().height)/2);
    float distance = ((center1 - center2)/((sprt1.getGlobalBounds().height)/2));
}



void chooseSong(bool sel){

    if(sel){
        // Plays duel of fates if true
        if (!music.openFromFile("resources/audio/Fate.ogg"))
        {
            cout << "cannot load song" << endl;
        }

        music.setVolume(50);         // Reduce the volume

        music.play();

    }else{
        // Plays imperial march if false
        if (!music.openFromFile("resources/audio/March.ogg"))
        {
            cout << "cannot load song" << endl;
        }

        music.setVolume(50);         // Reduce the volume

        music.play();
    }

}

void playLsSound (unsigned int sel) {
    // Randomly choose a different sound effect for the lightsabers
    switch (sel) {
        case 0:
            lsSoundBuffer.loadFromFile("resources/audio/saber0.wav");
            lsSound.play();

            break;

        case 1:
            lsSoundBuffer.loadFromFile("resources/audio/saber1.wav");
            lsSound.play();

            break;

        case 2:
            lsSoundBuffer.loadFromFile("resources/audio/saber2.wav");
            lsSound.play();

            break;

        default:
            lsSoundBuffer.loadFromFile("resources/audio/saber3.wav");
            lsSound.play();

            break;
    }
}

void playNoSound (bool sel) {
    // Plays the screams of defeat of Luke and Vader
    if (sel) {
        noSoundBuffer.loadFromFile("resources/audio/no_luke.wav");
        noSound.play();
    } else {
        noSoundBuffer.loadFromFile("resources/audio/no_vader.wav");
        noSound.play();
    }
}
