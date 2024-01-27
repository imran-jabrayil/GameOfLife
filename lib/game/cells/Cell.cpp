//
// Created by Imran Jabrayilov on 28.01.24.
//

#include "Cell.hpp"

Cell::Cell(uint16_t x, uint16_t y) {
    this->_id = x << 16 | y;
}

uint32_t Cell::getId() const {
    return this->_id;
}

std::tuple<uint16_t, uint16_t> Cell::getCoordinates() const {
    return std::make_tuple(this->_id >> 16, this->_id & 0xFFFF);
}
