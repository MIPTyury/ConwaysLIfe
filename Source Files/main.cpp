#include "../Headers/GameLogic.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Conway's Life");
    window.setFramerateLimit(144);
    window.setKeyRepeatEnabled(false);

    Field field(60, 40);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }


        }

        window.clear();
        InteractionWrapper(field, window);
        GameLogicWrapper(field);
        field.DrawField(window);
        window.display();
    }

    return 0;
}