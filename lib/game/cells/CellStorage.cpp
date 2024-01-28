//
// Created by Imran Jabrayilov on 28.01.24.
//

#include "Cell.hpp"
#include "CellStorage.hpp"

static std::set<Cell> _cells;

void CellStorage::addCell(const Cell &cell) {
    _cells.insert(cell);
}

void CellStorage::createCell(const uint16_t x, const uint16_t y) {
    const Cell cell{ x, y };
    _cells.insert(cell);
}

void CellStorage::removeCellByCoordinates(const uint16_t x, const uint16_t y) {
    _cells.erase(Cell{ x, y });
}

std::set<Cell> &CellStorage::getCells() {
    return _cells;
}

void CellStorage::updateCells(const std::set<Cell> &cells) {
    _cells = cells;
}
