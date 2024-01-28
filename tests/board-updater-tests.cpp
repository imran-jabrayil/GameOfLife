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
        BOOST_REQUIRE(cells.size() == 2);

        auto cell1 = *cells.begin();
        auto [fst1, snd1] = cell1.getCoordinates();
        BOOST_REQUIRE(fst1 == 0);
        BOOST_REQUIRE(snd1 == 1);

        auto cell2 = *(++cells.begin());
        auto [fst2, snd2] = cell2.getCoordinates();
        BOOST_REQUIRE(fst2 == 1);
        BOOST_REQUIRE(snd2 == 1);
    }


BOOST_AUTO_TEST_SUITE_END()
