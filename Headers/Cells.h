#pragma once
#include <SFML/Graphics.hpp>

class Cell {
    int _size = 0;
    bool _alive = true;
    sf::RectangleShape _cell;
public:
    Cell(int size = 10) {
        _size = size;
        _cell = sf::RectangleShape(sf::Vector2f(_size, _size));
    }

    void DrawCell(sf::RenderWindow &window) {
        window.draw(_cell);
    }

    void Revive() {
        _cell.setFillColor(sf::Color::White);
    }

    void Kill() {
        _cell.setFillColor(sf::Color::Black);
    }

    void SetPos(sf::RenderWindow &window, sf::Vector2f pos) {
        _cell.setPosition(pos);
    }


};