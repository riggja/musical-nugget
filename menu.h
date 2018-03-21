// Class created by Matthew

#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
using namespace std;

#define MAX_NUMBER_OF_ITEMS 2

class Menu {
    public:
        Menu(float width, float height); // Constructor takes in width and height of Window object
        ~Menu();
        
        void draw(sf::RenderWindow &window); // Draws Menu objects
        void MoveUp(); // Moves selection up
        void MoveDown(); // Moves selection down
        int GetPressedItem() { return selectedItemIndex; } // Changes gamestate
    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
};
