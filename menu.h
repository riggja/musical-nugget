#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
using namespace std;

#define MAX_NUMBER_OF_ITEMS 3

#ifndef MENU_H
#define MENU_H

class Menu {
    public:
        Menu(float width, float height);
        ~Menu();
        
        void draw(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();
        int GetPressedItem() { return selectedItemIndex; }
    
    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
};

#endif // MENU_H