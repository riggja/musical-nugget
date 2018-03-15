#include "Ball.h"

Ball::Ball (sf::Vector2f initPos, sf::Vector2f initVel, std::string image) {
  // Set the initial position of the ball
  setPosition(initPos);

  // Set the initial velocity of the ball
  vel = initVel;

  // Try to apply the specified image to the texture
  if (!tex.loadFromFile(image)) {
      std::cout << "Unable to load specified texture \"" << image << "\"." << std::endl;
  }
  // Apply the texture to the sprite.
  setTexture(tex);
}

void Ball::cont(sf::RenderWindow &window) {
  sf::Vector2f pos = getPosition();
  if (pos.y <= 0 || pos.y+getGlobalBounds().height >= window.getSize().y) {
    vel.y *= -1;
  }
  if (pos.x <= 0) {
    vel.x *= -1;
      //return -1;
  } else if (pos.x+getGlobalBounds().width >= window.getSize().x) {
    vel.x *= -1;
      //return +1;
  }
  move(vel);
}
