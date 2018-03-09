#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "background.h"
using namespace std;

Background::Background(int i) {
    images = i;
    a = new sf::Texture[images];
    for (int j = 1; j <= images; j++) {
        string address = "resources/images/Background"; 
        string num = j;
        address += num;
        address += ".jpg";
        if(!(a[j].loadFromFile(address))) {
            cout << "cannot load background" << endl;
        }
    }
}
