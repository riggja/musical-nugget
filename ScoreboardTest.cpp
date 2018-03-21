#include "Scoreboard.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

int main() {
    // Configuring display window
    int resX = 1280, resY = 720;
    int newH = (1920*resY)/resX;
    int displace = (newH - 1080)/(-2);
    sf::RenderWindow window(sf::VideoMode(resX, resY), "Star Wars Pong");
    window.setFramerateLimit(60);
    
    Scoreboard test(window);
    test.score(1);
}