#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Cell {
    int _size = 0;
    bool _alive = true;
    sf::RectangleShape _cell;
    sf::Vector2f _pos;
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
        _alive = true;
    }

    void Kill() {
        _cell.setFillColor(sf::Color::Black);
        _alive = false;
    }

    void SetPos(sf::RenderWindow &window, sf::Vector2f pos) {
        _cell.setPosition(pos);
        _pos = pos;
    }

    sf::Vector2f GetPos() {
        return _pos;
    }

    bool aliveFlag () {
        return _alive;
    }
};