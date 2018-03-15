#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Paddle : public sf::Sprite {
  private:
    sf::Texture tex;
    int speed;
  public:
    const int maxSpeed;

    Paddle (sf::Vector2f initPos, std::string image);

    void cont(sf::RenderWindow &window, char dir);
};
