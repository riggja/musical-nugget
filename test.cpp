#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
<<<<<<< HEAD
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
    sf::CircleShape shape(25.f);
    shape.setFillColor(sf::Color::Green);

=======
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
    
    int direction = 1;
>>>>>>> cf861511e454fd176d80ba2d1b0371064ede0ed0
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
        
        // if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds())) {
        //     window.clear();
        //     cout << "COLLISION" << endl;
        // } else {
        //     window.display();
        //     cout << "Not Collision" << endl;
        // }
        
        sf::Vector2f ballPos = ball.getPosition();
        cout << ballPos.x << endl;
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