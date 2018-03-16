#include <SFML/Graphics.hpp>
#include <string>

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

class Scoreboard {
private:
  int playerOneScore;
  int playerTwoScore;
  sf::Font scoreFont;
  sf::Text scoreOne, scoreTwo;
public:
  Scoreboard(sf::RenderWindow &window);
  void score(int player);
  char hasWon(int maxScore);
  void draw(sf::RenderWindow &window);
};

#endif // SCOREBOARD_H
