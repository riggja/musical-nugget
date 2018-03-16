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

        Ball (sf::Vector2f initPos, float initSpeed, float initAngle, std::string image);
        char cont(sf::RenderWindow &window);

        sf::Vector2f getVel();
        void setVel(sf::Vector2f vel);

        void setVelAngle(float);

        void reverseDir();

        float getSpeed();

        // Increases the speed by 0.1 and returns it.
        float increaseSpeed();
};
