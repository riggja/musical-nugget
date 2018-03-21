// Class created by Cameron

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Paddle : public sf::Sprite {
    private:
        // The texture for the sprite (this must be stored here; the sprite only stores a reference to a texture, so destroying this will cause the sprite to lose its texture.)
        sf::Texture tex;
        
        // The speed at which we're actually moving
        int speed;
        
        // The speed toward which we're acelerating
        int maxSpeed;
        
        // Is this paddle computer-controlled?
        bool isAI;
    public:
        // A constructor taking an intial position and a path to an image.
        Paddle (sf::Vector2f initPos, std::string image);
        
        // Returns char simply because it takes the least memory. Called every frame to calculate collision and apply movement.
        void cont(sf::RenderWindow &window, char dir);
        
        // Mutator and Accessor for maxSpeed
        int getMaxSpeed();
        void setMaxSpeed(int);
        
        // Mutator and Accessor for isAI
        bool getIsAI();
        void setIsAI(bool);
};
