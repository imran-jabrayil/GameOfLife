//
// Created by Imran Jabrayilov on 28.01.24.
//

#ifndef CELL_HPP
#define CELL_HPP

#include <tuple>

class Cell {
private:
    uint32_t _id;

public:
    Cell(uint16_t x, uint16_t y);

    uint32_t getId() const;
    std::tuple<uint16_t, uint16_t> getCoordinates() const;
};

#endif //CELL_HPP
