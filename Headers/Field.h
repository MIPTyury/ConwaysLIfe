#include "../Headers/Cells.h"
#include "cmath"

class Field {
    int _xSize = 0;
    int _ySize = 0;
    Cell **_field;
public:
    Field(int xSize, int ySize) {
        _xSize = xSize;
        _ySize = ySize;

        _field = new Cell *[xSize];
        for (int i = 0; i < xSize; i++) {
            _field[i] = new Cell[ySize];
        }
    }

    Field(Field &other) {
        _xSize = other.GetXSize();
        _ySize = other.GetYSize();
        _field = new Cell *[other._xSize];

        for (int i = 0; i < _xSize; i++) {
            _field[i] = new Cell[_ySize];
        }

        for (int i = 0; i < GetXSize(); i++) {
            for (int j = 0; j < GetYSize(); j++) {
                _field[i][j] = other._field[i][j];
            }
        }
    }

    void DeleteField() {
        for (int i = 0; i < _xSize; i++) {
            delete [] _field[i];
        }
        delete [] _field;
    }

    int GetXSize() { return _xSize; }

    int GetYSize() { return _ySize; }


    void SetPosField(sf::RenderWindow &window) {
        int width = window.getSize().x;
        int height = window.getSize().y;

        for (int i = 0; i < _xSize; i++) {
            for (int j = 0; j < _ySize; j++) {
                _field[i][j].SetPos(window, sf::Vector2f(round(width / (GetXSize() + 1)) + 11 * i,
                                                         round(height / (GetYSize() + 1)) + 11 * j));
            }
        }
    }

    void DrawField(sf::RenderWindow &window) {
        SetPosField(window);

        for (int i = 0; i < _xSize; i++) {
            for (int j = 0; j < _ySize; j++) {
                _field[i][j].DrawCell(window);
            }
        }
    }

    void ReviveAll() {
        for (int i = 0; i < _xSize; i++) {
            for (int j = 0; j < _ySize; j++) {
                _field[i][j].Revive();
            }
        }
    }

    void KillAll() {
        for (int i = 0; i < _xSize; i++) {
            for (int j = 0; j < _ySize; j++) {
                _field[i][j].Kill();
            }
        }
    }

    Cell** FieldArray () {
        return _field;
    }


};

