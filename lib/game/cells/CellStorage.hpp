//
// Created by Imran Jabrayilov on 28.01.24.
//

#ifndef CELLSTORAGE_HPP
#define CELLSTORAGE_HPP

#include <set>

class Cell;

class CellStorage {
public:
    static void addCell(const Cell& cell);
    static void createCell(uint16_t x, uint16_t y);
    static void removeCellByCoordinates(uint16_t x, uint16_t y);

    static std::set<Cell> &getCells();
    static void updateCells(const std::set<Cell> &cells);
};

#endif //CELLSTORAGE_HPP
