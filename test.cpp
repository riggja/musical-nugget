#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

bool debug = false;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
    sf::CircleShape shape(25.f);
    shape.setFillColor(sf::Color::Green);
    
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
    if (!paddleTexture.loadFromFile("CharacterSprite.jpg")) {
        cout << "mistake" << endl;
    }
    sf::Texture ballTexture;
    if (!ballTexture.loadFromFile("BallSprite.jpg")) {
        cout << "mistake" << endl;
    }
    
    sf::Sprite paddle;
    paddle.setTexture(paddleTexture);
    
    sf::Sprite ball;
    ball.setTexture(ballTexture);
    
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
            direction = 1;
        } else if (ballPos.x == 450) {
            direction = -1;
        }
        ball.move(direction,0);

        window.clear();
        window.draw(paddle);
        window.draw(ball);
        window.display();
    }

    return 0;
}