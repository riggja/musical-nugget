// Class created by Cameron

#include "Paddle.h"


Paddle::Paddle (sf::Vector2f initPos, std::string image) {
    // Intialize as an AI; this will be overrided if a player inputs a direction.
    isAI = true;
    
    // Initialize maxSpeed to 5; this will increase with the speed of the ball.
    maxSpeed = 5;
    
    // Start out sationary.
    speed = 0;
    
    // Set the initial position of the paddle.
    setPosition(initPos);

    // Try to apply the specified image to the texture.
    if (!tex.loadFromFile(image)) {
        std::cout << "Unable to load specified texture \"" << image << "\"." << std::endl;
    }
    // Apply the texture to the sprite.
    setTexture(tex);
    
    // Scale the sprite appropriately; the default size is far too big.
    scale (.12, .12);
}

void Paddle::cont(sf::RenderWindow &window, char dir) {
    // Get the sprite's global position.
    sf::Vector2f pos = getPosition();
    
    Move upward
    if (dir < 0) {
        // Accelerate
        if (speed > -maxSpeed) {
            speed--;
        }
        // Don't move outside boundary.
        if (pos.y <= 0) {
            speed = 0;
            setPosition(pos.x, 0);
        }
    // Don't move
    } else if (!dir) {
        // Decelerate until 0
        if (speed > 0) {
            speed--;
        } else if (speed < 0) {
            speed++;
        }
    // Move downward
    } else {
        // Get the height of the screen - the height of the paddle, ensuring that the paddle stops as soon as it hits the edge.
        int maxHeight = window.getSize().y - getGlobalBounds().height;
        // Accelerate
        if (speed < maxSpeed) {
            speed++;
        }
        // Don't move outside boundary.
        if (pos.y >= maxHeight) {
            speed = 0;
            setPosition(pos.x, maxHeight);
        }
    }
    move (0, (isAI ? speed/1.3 : speed)); // If it's an AI, slightly reduce the speed. This makes it easier to win against AI
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
