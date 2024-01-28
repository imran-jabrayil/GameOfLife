//
// Created by Imran Jabrayilov on 28.01.24.
//

#include <cassert>

#include "game/cells/Cell.hpp"
#include "settings.hpp"

Cell::Cell(uint16_t x, uint16_t y) {
    assert(x < HEIGHT && "X out of board");
    assert(y < WIDTH && "Y out of board");
    this->_id = x << 16 | y;
}


uint32_t Cell::getId() const {
    return this->_id;
}

std::pair<uint16_t, uint16_t> Cell::getCoordinates() const {
    return std::make_pair(this->_id >> 16, this->_id & 0xFFFF);
}

bool Cell::operator<(const Cell &cell) const
{
    return this->_id < cell._id;
}

bool Cell::operator==(const Cell &cell) const {
    return this->_id == cell._id;
}
