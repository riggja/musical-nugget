// Class created by Cameron

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Ball : public sf::Sprite {
    private:
        // The texture for the sprite (this must be stored here; the sprite only stores a reference to a texture, so destroying this will cause the sprite to lose its texture.)
        sf::Texture tex;

        // The velocity at which the ball is traveling; the X and Y values are not typically set directly, but rather calculated from a supplied angle and stored speed.
        sf::Vector2f vel;

        // The speed of the ball in any direction. If vel's X or Y value is 0, this will be equal to the other value.
        float speed;

    public:
        // This determines the maximum angle at which the ball can be sent.
        const float maxAngle;

        // Constructor taking an intial position, speed, and angle, as well as a path to an image.
        Ball (sf::Vector2f initPos, float initSpeed, float initAngle, std::string image);

        // Returns char simply because it takes the least memory. Called every frame to calculate collision and apply movement.
        char cont(sf::RenderWindow &window);

        // Accessor and Mutator functions for vel
        sf::Vector2f getVel();
        void setVel(sf::Vector2f vel);

        // Set vel given an angle in radians.
        void setVelAngle(float);

        // Reverse the X direction.
        void reverseDir();

        // Accessor for speed
        float getSpeed();

        // Increases the speed by 0.1 and returns it.
        float increaseSpeed();
};
