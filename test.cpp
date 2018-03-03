#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    
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
            window.clear();
            cout << "COLLISION" << endl;
        } else {
            window.display();
            cout << "Not Collision" << endl;
        }

        window.clear();
        window.draw(paddle);
        window.draw(ball);
        window.display();
    }

    return 0;
}