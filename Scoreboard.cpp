#include "Scoreboard.h"

void Scoreboard::score(int player) {
  if (player == -1) {
    playerOneScore++;
  } else {
    playerTwoScore++;
  }
}

char Scoreboard::hasWon(int maxScore) {
  if (playerOneScore >= maxScore) {
    return -1;
  } else if (playerTwoScore >= maxScore) {
    return 1;
  } else {
    return 0;
  }
}

Scoreboard::Scoreboard(sf::RenderWindow &window) : playerOneScore(0), playerTwoScore(0) {
  this->scoreFont.loadFromFile("resources/fonts/jedi.ttf");
  sf::Text scoreOne, scoreTwo;

  this->scoreOne.setFont(scoreFont);
  this->scoreOne.setFillColor(sf::Color::Blue);
  this->scoreOne.setString("1");
  this->scoreOne.setPosition(100, window.getSize().y-50);

  this->scoreTwo.setFont(scoreFont);
  this->scoreTwo.setFillColor(sf::Color::Red);
  this->scoreTwo.setString("1");
  this->scoreTwo.setPosition(window.getSize().x-100, window.getSize().y-50);
}

void Scoreboard::draw(sf::RenderWindow &window) {
    window.draw(scoreOne);
    window.draw(scoreTwo);
}
