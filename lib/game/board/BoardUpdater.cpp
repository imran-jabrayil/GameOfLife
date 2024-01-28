//
// Created by Imran Jabrayilov on 28.01.24.
//

#include <vector>

#include "game/cells/Cell.hpp"
#include "game/board/BoardUpdater.hpp"
#include "game/cells/CellStorage.hpp"
#include "settings.hpp"

static std::vector<Cell> getNeighbours(const Cell& cell) {
    static std::vector<std::pair<int8_t, int8_t>> directions{
        std::make_pair(-1, 0),
        std::make_pair(1, 0),
        std::make_pair(0, 1),
        std::make_pair(0, -1),
        std::make_pair(1, -1),
        std::make_pair(1, 1),
        std::make_pair(-1, -1),
        std::make_pair(-1, 1)
    };

    std::vector<Cell> neighbours;

    const auto [x, y] = cell.getCoordinates();
    for (const auto [fst, snd] : directions) {
#if BORDERLESS
        uint16_t newX = (x + HEIGHT + fst) % HEIGHT;
        uint16_t newY = (y + WIDTH + snd) % WIDTH;
#else // BORDERLESS
        if (x == 0 && fst == -1 || x == HEIGHT && fst == 1 ||
            y == 0 && snd == -1 || y == WIDTH && snd == 1) continue;
        uint16_t newX = x + fst;
        uint16_t newY = y + snd;
#endif // BORDERLESS

        neighbours.emplace_back( newX, newY );
    }

    return neighbours;
}

void BoardUpdater::Update() {
    const std::set<Cell> &current_cells = CellStorage::getCells();
    std::set<Cell> future_cells;

    std::set<Cell> future_neighbours;

    for (auto cell : current_cells) {
        auto neighbours = getNeighbours(cell);
        future_neighbours.insert(neighbours.begin(), neighbours.end());

        uint8_t counter = 0;
        for (auto c : neighbours)
            if (current_cells.contains(c)) ++counter;

        if (counter == 3 || counter == 2)
            future_cells.insert(cell);
    }

    for (auto cell : future_neighbours) {
        auto neighbours = getNeighbours(cell);

        uint8_t counter = 0;
        for (auto c : neighbours)
            if (current_cells.contains(c)) ++counter;

        if (counter == 3)
            future_cells.insert(cell);
    }

    CellStorage::updateCells(future_cells);
}


