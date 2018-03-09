#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Background {
    private:
        sf::Texture * a;
        sf::Clock Clock;
        int images;
    public:
        Background(int);
};

#endif // BACKGROUND_H