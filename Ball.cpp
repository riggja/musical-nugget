#include <SFML/Graphics.hpp>
#include "../Ball/Ball.h"
#include <string>
#include <iostream>

Ball::Ball (sf::Vector2f initPos, sf::Vector2f vel, string image) {
  // Set the initial position of the ball
  ballSprite.setPosition(initPos);

  // Set the initial velocity of the ball
  this->vel = vel;

  // Set the texture for the sprite //
  // Create the texture
  sf::Texture tex;
  // Try to apply the specified image to the texture
  if (!tex.loadFromFile(string(image))) {
      std::cout << "Unable to load specified texture \"" << image << "\"." << endl;
  }
  // Apply the texture to the sprite.
  ballSprite.setTexture(tex);
}
