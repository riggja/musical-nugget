#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <sstream>
#include <math.h>
#include "menu.h"
#include "Ball.h"
#include "Paddle.h"
#include "Scoreboard.h"
using namespace std;

void changeText(sf::Text &text, string string);

int main() {
  // Configuring display window
  int resX = 1280, resY = 720;
  int newH = (1920*resY)/resX;
  int displace = (newH - 1080)/(-2);
  sf::RenderWindow window(sf::VideoMode(resX, resY), "Star Wars Pong");
  window.setFramerateLimit(60);

  // Initialize scoreboard
  Scoreboard score(window);

  // Reset score
  score.reset();

  // Instructions Text
  sf::Font font;
  font.loadFromFile("resources/fonts/jedi.ttf");
  sf::Text text;
  text.setFont(font);
  text.setFillColor(sf::Color::White);
  text.setString("Left Click - Score Blue, Right Click - Score Red");
  sf::FloatRect textRect = text.getLocalBounds();
  text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
  text.setPosition(sf::Vector2f(resX / 2, resY / 2));

  int maxScore = 11;
  bool hasWon = false;
  sf::Clock clock;
  clock.restart();
  while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
              window.close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
              score.score(1);
              cout << "Player 1 is now at: " << score.getPlayerOneScore() << " points" << endl;
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
              score.score(-1);
              cout << "Player 2 is now at: " << score.getPlayerTwoScore() << " points" << endl;
            }

            if (score.hasWon(maxScore)) {
              hasWon = true;
              if (score.getPlayerOneScore() >= maxScore) {
                cout << "Player One Won" << endl;
                changeText(text, "Player One Won");
              } else if (score.getPlayerTwoScore() >= maxScore) {
                cout << "Player Two Won" << endl;
                changeText(text, "Player Two Won");
              }
              if (clock.getElapsedTime().asSeconds() >= 1) {
                window.close();
              }
            }

            if (hasWon == true) {
              clock.getElapsedTime();
            } else {
              clock.restart();
            }

        }

        window.clear();
        score.draw(window);
        window.draw(text);
        window.display();
      }

    return 0;
}

void changeText(sf::Text &text, string string) {
  text.setString(string);
  sf::FloatRect textRect = text.getLocalBounds();
  text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
}
