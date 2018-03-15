#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Ball : public sf::Sprite {
  private:
    sf::Texture tex;
    sf::Vector2f vel;
  public:
    Ball (sf::Vector2f initPos, sf::Vector2f initVel, std::string image);
    char cont(sf::RenderWindow &window);
};
