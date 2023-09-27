#include "Interaction.h"

bool WillBeAlive(Field field, int i, int j) {
    int aliveCount = 0;

    Cell cell = field.FieldArray()[i][j];

    if (field.FieldArray()[i + 1][j].aliveFlag()) { aliveCount++; }
    if (field.FieldArray()[i][j + 1].aliveFlag()) { aliveCount++; }
    if (field.FieldArray()[i - 1][j].aliveFlag()) { aliveCount++; }
    if (field.FieldArray()[i][j - 1].aliveFlag()) { aliveCount++; }

    if (field.FieldArray()[i + 1][j + 1].aliveFlag()) { aliveCount++; }
    if (field.FieldArray()[i + 1][j - 1].aliveFlag()) { aliveCount++; }
    if (field.FieldArray()[i - 1][j + 1].aliveFlag()) { aliveCount++; }
    if (field.FieldArray()[i - 1][j - 1].aliveFlag()) { aliveCount++; }

    if (aliveCount == 3 && !cell.aliveFlag()) {
        return true;
    }
    if ((aliveCount == 2 || aliveCount == 3) && cell.aliveFlag()) {
        return true;
    }
    return false;
}

void NeighborhoodAnalysis(Field &field) {
    Field tmp(field);

    for (int i = 1; i < field.GetXSize() - 1; i++) {
        for (int j = 1; j < field.GetYSize() - 1; j++) {
            if (WillBeAlive(field, i, j)) {
                tmp.FieldArray()[i][j].Revive();
            } else {
                tmp.FieldArray()[i][j].Kill();
            }
        }
    }
    field = Field(tmp);
    tmp.DeleteField();
}

void GameLogicWrapper(Field &field) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        NeighborhoodAnalysis(field);
        started = true;
    }
}