#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class Background {
    public:
        Background(int);
        ~Background();
    private:
        sf::Texture * textures;
        sf::Clock Clock;
        int images;
};

#endif // BACKGROUND_H