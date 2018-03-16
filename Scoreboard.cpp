#include "Scoreboard.h"
using namespace std;

void Scoreboard::score(int player) {
  ostringstream convert;
  if (player == 1) {
    playerOneScore++;
    convert << playerOneScore;
    scoreOne.setString(convert.str());
  } else {
    playerTwoScore++;
    convert << playerTwoScore;
    scoreTwo.setString(convert.str());
  }
}

char Scoreboard::hasWon(int maxScore) {
  if (playerOneScore >= maxScore) {
    return 1;
  } else if (playerTwoScore >= maxScore) {
    return -1;
  } else {
    return 0;
  }
}

Scoreboard::Scoreboard(sf::RenderWindow &window) : playerOneScore(0), playerTwoScore(0) {
  scoreFont.loadFromFile("resources/fonts/jedi.ttf");
  scoreOne.setString("0");
  scoreTwo.setString("0");
}

void Scoreboard::draw(sf::RenderWindow &window) {
    scoreOne.setFont(scoreFont);
    scoreOne.setFillColor(sf::Color::Blue);
    scoreOne.setPosition(100, window.getSize().y-50);
    scoreTwo.setFont(scoreFont);
    scoreTwo.setFillColor(sf::Color::Red);
    scoreTwo.setPosition(window.getSize().x-100, window.getSize().y-50);
    window.draw(scoreOne);
    window.draw(scoreTwo);
}

void Scoreboard::reset() {
    playerOneScore = 0;
    scoreOne.setString("0");
    playerTwoScore = 0;
    scoreTwo.setString("0");
}
