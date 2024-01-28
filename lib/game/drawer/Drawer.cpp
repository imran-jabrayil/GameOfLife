//
// Created by Imran Jabrayilov on 28.01.24.
//

#include <iostream>
#include <thread>

#include "game/board/BoardUpdater.hpp"
#include "game/cells/Cell.hpp"
#include "game/cells/CellStorage.hpp"
#include "game/drawer/Drawer.hpp"
#include "settings.hpp"

#ifdef _WIN32
#include <windows.h>
#define CLEAR system("cls")
#else
#include <unistd.h>
#define CLEAR system("clear")
#endif

void Drawer::Show() {
    std::cout << "+";
    for (auto _ = 0; _ < WIDTH * 2; ++_) std::cout << '=';
    std::cout << "+" << std::endl;

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PERIOD));
        auto cells = CellStorage::getCells();
        CLEAR;

        for (uint16_t row = 0; row < HEIGHT; ++row) {
            std::cout << "|";
            for (uint16_t col = 0; col < WIDTH; ++col) {
                Cell cell{ row, col };
                std::cout << (cells.contains(cell) ? "+ " : "  ");
            }
            std::cout << "|" << std::endl;
        }
        std::cout << "+";
        for (auto _ = 0; _ < WIDTH * 2; ++_) std::cout << '=';
        std::cout << "+" << std::endl;

        BoardUpdater::Update();
    }
}
