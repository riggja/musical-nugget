#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Ball : public sf::Sprite {
    private:
        sf::Texture tex;
        sf::Vector2f vel;

        float speed;

    public:
        const float maxAngle;
        
        // Sets the default settings for the ball 
        Ball (sf::Vector2f initPos, float initSpeed, float initAngle, std::string image);
        
        // Sets movement speed and positioning of the ball
        char cont(sf::RenderWindow &window);
        
        // Speed of the object movement
        sf::Vector2f getVel();
        void setVel(sf::Vector2f vel);
        
        // Angle of ball bounce
        void setVelAngle(float);
        
        // Turns ball around if it hits a paddle
        void reverseDir();
        
        // Gets the speed of the ball
        float getSpeed();

        // Increases the speed by 0.1 and returns it.
        float increaseSpeed();
};
