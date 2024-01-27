//
// Created by Imran Jabrayilov on 28.01.24.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "game/cells/Cell.hpp"


BOOST_AUTO_TEST_SUITE(CellTests)

BOOST_AUTO_TEST_CASE(CellId) {
    const Cell cell{1, 2};

    const uint32_t id = cell.getId();

    BOOST_CHECK_EQUAL(id, 65538);
}

BOOST_AUTO_TEST_CASE(CellCoordinates) {
    const Cell cell{1, 2};

    const std::tuple<uint16_t, uint16_t> coordinates = cell.getCoordinates();

    BOOST_CHECK_EQUAL(std::get<0>(coordinates), 1);
    BOOST_CHECK_EQUAL(std::get<1>(coordinates), 2);
}

BOOST_AUTO_TEST_SUITE_END()
