#define _GLIBCXX_USE_CXX11_ABI 0
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "menu.cpp"
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
    
    // background file loading
    sf::Texture backgroundTexture1;
    if (!backgroundTexture1.loadFromFile("resources/images/Background1.jpg")) {
        cout << "cannot load background" << endl;
    }
    sf::Texture backgroundTexture2;
    if (!backgroundTexture2.loadFromFile("resources/images/Background2.jpg")) {
        cout << "cannot load background" << endl;
    }
    sf::Sprite background;
    background.setTexture(backgroundTexture1);
    
    // configuring display window
    int resX = 1280, resY = 820;
    int newH = (1920*resY)/resX;
    int displace = (newH - 1080)/(-2);
    sf::RenderWindow window(sf::VideoMode(resX, resY), "SFML works!");
    window.setFramerateLimit(30);
    window.setView(sf::View(sf::FloatRect(0, displace, 1920, newH)));
    
    Menu menu(window.getSize().x, window.getSize().y);
    
    // game item files loading
    sf::Texture paddleTexture;
    if (!paddleTexture.loadFromFile(string("resources/images/Blue_Lightsaber2.png"))) {
        cout << "mistake" << endl;
    }
    sf::Texture ballTexture;
    if (!ballTexture.loadFromFile(string("resources/images/death_star.png"))) {
        cout << "mistake" << endl;
    }
    
    sf::Sprite paddle;
    paddle.setTexture(paddleTexture);
    
    sf::Sprite ball;
    ball.setTexture(ballTexture);
    
    sf::Clock Clock;
    int direction = 1;
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
            
            sf::Vector2f ballPos = ball.getPosition();
            // cout << ballPos.x << endl;
            if (ballPos.x == 0) {
                direction = 3;
            } else if (ballPos.x == 450) {
                direction = -3;
            }
            ball.move(direction,0);
            
            if (int(Clock.getElapsedTime().asSeconds()) % 2 == 0) {
                background.setTexture(backgroundTexture2);
            } else {
                background.setTexture(backgroundTexture1);
            } 
                
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
