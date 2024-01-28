#include <QApplication>
#include <QPushButton>

#include "game/cells/Cell.hpp"
#include "game/cells/CellStorage.hpp"
#include "game/drawer/Drawer.hpp"

int main(int argc, char *argv[]) {
    // QApplication a(argc, argv);
    // QPushButton button("Hello world!", nullptr);
    // button.resize(200, 100);
    // button.show();
    // return QApplication::exec();

    auto cells = std::vector<Cell>{
        Cell{ 2, 1 },
        Cell{ 2, 2 },
        Cell{ 2, 3 },
        Cell{ 1, 3},
        Cell{ 0, 2}
    };
    for (auto cell : cells)
        CellStorage::addCell(cell);
    Drawer::Show();
    return 0;
}
