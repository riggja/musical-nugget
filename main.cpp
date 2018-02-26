#include "game_state.h"
#include "main_menu.h"

game_state coreState;

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Ping");
    
    coreState.SetWindow(&window);
    coreState.SetState(new main_menu());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear(sf::Color::Black);
        
        coreState.Update();
        coreState.Render();

        window.display();
    }

    return 0;
}