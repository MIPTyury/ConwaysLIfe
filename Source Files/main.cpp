#include "../Headers/Field.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Conway's Life");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Cell cell;
    cell.Revive();
    cell.SetPos(window, sf::Vector2f(window.getSize().x/2, window.getSize().y/2));

    Field field(60, 40);
    field.ReviveAll();

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
//        cell.SetPos(window, sf::Vector2f(window.getSize().x/2, window.getSize().y/2));
//        cell.DrawCell(window);
        field.DrawField(window);
        window.display();
    }

    return 0;
}