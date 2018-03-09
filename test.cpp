#define _GLIBCXX_USE_CXX11_ABI 0
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
// #include "background.cpp"
using namespace std;

bool debug = false;

int main()
{
    //testing sound
    sf::Music music;
    
    if (!music.openFromFile("resources/audio/StarWarsSong.ogg"))
    {
        cout << "cannot load song" << endl;
    }
    
    music.setVolume(50);         // reduce the volume
    music.setLoop(true);        // set loop
    
    music.play();
    
    // Background t(2); // testing from background.h -> will later implement
    
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
    
    int resX = 1280, resY = 820;
    int newH = (1920*resY)/resX;
    int displace = (newH - 1080)/(-2);
    sf::RenderWindow window(sf::VideoMode(resX, resY), "SFML works!");
    window.setFramerateLimit(30);
    window.setView(sf::View(sf::FloatRect(0, displace, 1920, newH)));
    
    // sf::RectangleShape paddle(sf::Vector2f(50, 120));
    // paddle.setFillColor(sf::Color::Green);
    // paddle.setOutlineThickness(10);
    // paddle.setOutlineColor(sf::Color(250, 150, 100));
    // sf::RectangleShape ball(sf::Vector2f(50, 50));
    // ball.setFillColor(sf::Color::Blue);
    
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
        }
        
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

        window.clear();
        window.draw(background);
        window.draw(paddle);
        window.draw(ball);
        window.display();
    }

    return 0;
}
