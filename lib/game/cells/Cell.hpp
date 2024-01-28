//
// Created by Imran Jabrayilov on 28.01.24.
//

#ifndef __CELL_HPP__
#define __CELL_HPP__

#include <cstdint>
#include <utility>

class Cell {
private:
    uint32_t _id;

public:
    Cell(uint16_t x, uint16_t y);

    uint32_t getId() const;
    std::pair<uint16_t, uint16_t> getCoordinates() const;
    bool operator<(const Cell &cell) const;
    bool operator==(const Cell &cell) const;
};

#endif // __CELL_HPP__
