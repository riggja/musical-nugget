#include "Ball.h"
#include <math.h>

Ball::Ball (sf::Vector2f initPos, float initSpeed, float initAngle, std::string image) : maxAngle(M_PI/4) {
    // Set the initial position of the ball
    setPosition(initPos);

    speed = initSpeed;

    // Set the initial velocity of the ball
    setVelAngle(initAngle);

    // Try to apply the specified image to the texture
    if (!tex.loadFromFile(image)) {
        std::cout << "Unable to load specified texture \"" << image << "\"." << std::endl;
    }
    // Apply the texture to the sprite.
    setTexture(tex);
}

char Ball::cont(sf::RenderWindow &window) {
    sf::Vector2f pos = getPosition();
    if (pos.y <= 0 || pos.y+getGlobalBounds().height >= window.getSize().y) {
        vel.y *= -1;
    }
    if (pos.x <= 0) {
        vel.x *= -1;
        vel = sf::Vector2f(0,0);
        return -1;
    } else if (pos.x+getGlobalBounds().width >= window.getSize().x) {
        vel.x *= -1;
        vel = sf::Vector2f(0,0);
        return 1;
    }

    move(vel);
    return 0;
}

sf::Vector2f Ball::getVel() {
    return vel;
}

void Ball::setVel(sf::Vector2f vel) {
    this->vel = vel;
}

void Ball::setVelAngle(float angle) {
    vel = sf::Vector2f((speed*cos(angle)),(speed*-sin(angle)));
}

void Ball::reverseDir() {
    vel.x *= -1;
}

float Ball::getSpeed() {
    return speed;
}

float Ball::increaseSpeed() {
    return speed+=0.1;
}
