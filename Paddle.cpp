#include "Paddle.h"


Paddle::Paddle (sf::Vector2f initPos, std::string image) {
    isAI = true;

    maxSpeed = 5;

    speed = 0;
    // Set the initial position of the paddle
    setPosition(initPos);

    // Try to apply the specified image to the texture
    if (!tex.loadFromFile(image)) {
        std::cout << "Unable to load specified texture \"" << image << "\"." << std::endl;
    }
    // Apply the texture to the sprite.
    setTexture(tex);

    scale (.12, .12);
}

void Paddle::cont(sf::RenderWindow &window, char dir) {
    sf::Vector2f pos = getPosition();

    if (dir < 0) {
        if (speed > -maxSpeed) {
            speed--;
        }
        if (pos.y <= 0) {
            speed = 0;
            setPosition(pos.x, 0);
        }
    } else if (!dir) {
        if (speed > 0) {
            speed--;
        } else if (speed < 0) {
            speed++;
        }
    } else {
        int maxHeight = window.getSize().y - getGlobalBounds().height;
        if (speed < maxSpeed) {
            speed++;
        }
        if (pos.y >= maxHeight) {
            speed = 0;
            setPosition(pos.x, maxHeight);
        }
    }
    move (0, (isAI ? speed/1.5 : speed)); // If it's an AI, slightly reduce the speed
}

int Paddle::getMaxSpeed() {
    return maxSpeed;
}

void Paddle::setMaxSpeed(int ms) {
    maxSpeed = ms;
}

bool Paddle::getIsAI() {
    return isAI;
}

void Paddle::setIsAI(bool isAI) {
    this->isAI = isAI;
}
