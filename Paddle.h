#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Paddle : public sf::Sprite {
    private:
        sf::Texture tex;
        int speed;
        int maxSpeed;
        bool isAI;
    public:
        // Constructor to set the position of the paddle and tha image sprite
        Paddle (sf::Vector2f initPos, std::string image);
        
        // Looks at the window and sets the direction and spped of the paddle
        void cont(sf::RenderWindow &window, char dir);
        
        // Gets/sets movement speed of the paddle
        int getMaxSpeed();
        void setMaxSpeed(int);
        
        // Checks to see if the AI is playing or a player is taking control
        bool getIsAI();
        void setIsAI(bool);
};
