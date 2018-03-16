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

        Paddle (sf::Vector2f initPos, std::string image);

        void cont(sf::RenderWindow &window, char dir);

        int getMaxSpeed();
        void setMaxSpeed(int);

        bool getIsAI();
        void setIsAI(bool);
};
