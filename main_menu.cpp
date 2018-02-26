#include <iostream>
#include "main_menu.h"

void main_menu::Initialize(sf::RenderWindow* window)
{
    this->font = new sf::Font();
    this->font->loadFromFile("font.ttf");
    
    this->title = new sf::Text("Ping", *this->font, 128U);
}

void main_menu::Update(sf::RenderWindow* window)
{
    
}

void main_menu::Render(sf::RenderWindow* window)
{
    window->draw(*this->title);
}

void main_menu::Destroy(sf::RenderWindow* window)
{
    delete this->font;
    delete this->title;
    std::cout << "destroyed\n";
}
