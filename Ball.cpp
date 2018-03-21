// Class created by Cameron

#include "Ball.h"
#include <math.h>

Ball::Ball (sf::Vector2f initPos, float initSpeed, float initAngle, std::string image) : maxAngle(M_PI/4) {
    // Set the initial position of the ball.
    setPosition(initPos);
    
    // Set the initial speed of the ball.
    speed = initSpeed;

    // Set the initial angle of the ball.
    setVelAngle(initAngle);

    // Try to apply the specified image to the texture.
    if (!tex.loadFromFile(image)) {
        std::cout << "Unable to load specified texture \"" << image << "\"." << std::endl;
    }
    // Apply the texture to the sprite.
    setTexture(tex);
}

char Ball::cont(sf::RenderWindow &window) {
    // Get the sprite's global position.
    sf::Vector2f pos = getPosition();
    
    // Have we gone outside of the Y boundaries?
    if (pos.y <= 0 || pos.y+getGlobalBounds().height >= window.getSize().y) {
        // If so, reverse.
        vel.y *= -1;
    }
    // Have we gone outside of the X boundaries?
    if (pos.x <= 0) {   // Left side
        // Stop moving
        vel = sf::Vector2f(0,0);
        // Notify the caller that we hit the left boundary.
        return -1;
    } else if (pos.x+getGlobalBounds().width >= window.getSize().x) {   // Right side
        // Stop moving
        vel = sf::Vector2f(0,0);
        // Notify the caller that we hit the right boundary.
        return 1;
    } else {    // We haven't hit anything; move.
        move(vel);
    }
    
    // Notify the caller that we haven't hit anything.
    return 0;
}

sf::Vector2f Ball::getVel() {
    return vel;
}

void Ball::setVel(sf::Vector2f vel) {
    this->vel = vel;
}

void Ball::setVelAngle(float angle) {
    // Calculate the velocity if the speed remains but the angle changes; apply this new value to vel.
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
