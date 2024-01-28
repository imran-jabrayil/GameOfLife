#include <thread>
#include <vector>

#include "game/board/BoardUpdater.hpp"
#include "game/cells/Cell.hpp"
#include "game/cells/CellStorage.hpp"
#include "game/drawer/Drawer.hpp"
#include "settings.hpp"

int main(int argc, char *argv[]) {
#if GUI
    // QApplication a(argc, argv);
    // QPushButton button("Hello world!", nullptr);
    // button.resize(200, 100);
    // button.show();
    // return QApplication::exec();
#else // GUI
    for (const auto cells = std::vector<Cell>{
             Cell{ 2, 1 },
             Cell{ 2, 2 },
             Cell{ 2, 3 },
             Cell{ 1, 3},
             Cell{ 0, 2}
         }; auto cell : cells) CellStorage::addCell(cell);

    for (int _ = 0; _ < 1000; ++_) {
        std::this_thread::sleep_for(std::chrono::milliseconds(UPDATE_PERIOD));
        BoardUpdater::Update();
        Drawer::Show();
    }
    return 0;
#endif // GUI
}
