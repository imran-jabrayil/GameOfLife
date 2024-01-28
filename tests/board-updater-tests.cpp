//
// Created by Imran Jabrayilov on 28.01.24.
//


#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "game/cells/Cell.hpp"
#include "game/cells/CellStorage.hpp"
#include "game/board/BoardUpdater.hpp"


BOOST_AUTO_TEST_SUITE(BoardUpdaterTests)

    BOOST_AUTO_TEST_CASE(BoardUpdate) {
        CellStorage::addCell(Cell{0, 0});
        CellStorage::addCell(Cell{1, 1});
        CellStorage::addCell(Cell{0, 2});

        BoardUpdater::Update();

        const auto cells = CellStorage::getCells();
        BOOST_TEST(cells.size() == 1);

        auto cell = *cells.begin();
        auto coordinates = cell.getCoordinates();
        BOOST_TEST(coordinates.first == 0);
        BOOST_TEST(coordinates.second == 1);
    }


BOOST_AUTO_TEST_SUITE_END()
