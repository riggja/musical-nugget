// Class created by Matthew

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

using namespace std;

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

class Scoreboard {
private:
  int playerOneScore;
  int playerTwoScore;
  sf::Font scoreFont;
  sf::Text scoreOne, scoreTwo;
public:
  Scoreboard(sf::RenderWindow &window); // Scoreboard constructor sets both sf::Text variables to 0
  void score(int player); // score is called when ball hits one edge of screen and updates points
  char hasWon(int maxScore); // hasWon checks to see if a player has won
  void draw(sf::RenderWindow &window); // Draw displays both scores
  void reset(); // Resets scores
};

#endif // SCOREBOARD_H
