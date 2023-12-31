#include "../Headers/Field.h"

bool started = false;

sf::Vector2i GetMousePosition(sf::RenderWindow &window) {
    return sf::Mouse::getPosition(window);
}

bool ClickTrigger() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        return true;
    }
    return false;
}

void ReviveTrigger(Cell &cell, sf::RenderWindow &window) {
    sf::Vector2i pos = GetMousePosition(window);

    if (pos.x >= cell.GetPos().x && cell.GetPos().x + 10 >= pos.x &&
        pos.y >= cell.GetPos().y && cell.GetPos().y + 10 >= pos.y) {
        if (ClickTrigger()) {
            if (cell.aliveFlag()) {
                cell.Kill();
            } else {
                cell.Revive();
            }
        }
    }
}

void FullFieldReviveTrigger(Field &field, sf::RenderWindow &window) {
    for (int i = 0; i < field.GetXSize(); i++) {
        for (int j = 0; j < field.GetYSize(); j++) {
            ReviveTrigger(field.FieldArray()[i][j], window);
        }
    }
}

void ClearBoard(Field &field) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        field.KillAll();
    }
}

void QuitGame(sf::RenderWindow &window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        window.close();
    }
}

bool Started() {
    return started;
}

void Restart(Field &field) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        started = false;
        field.KillAll();
    }
}

void Edit(Field &field) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        started = false;
    }
}

void InteractionWrapper(Field &field, sf::RenderWindow &window) {
    if (!Started()) {
        FullFieldReviveTrigger(field, window);
    }
    QuitGame(window);
    ClearBoard(field);
    Edit(field);
    Restart(field);
}