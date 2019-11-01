#include "engine.h"

#include <vector>
#include <unistd.h>


TGameEngine::TGameEngine() {}

TGameEngine::~TGameEngine() {}

void TGameEngine::game() {

	TDisplay display;
    TGameLogic logic;

    std::vector<int> state;

    state = logic.getstate();

    dispstate(state, display, -1);

    int gameStatus = 0;

    double y = 0;

    while (!display.Closed()) {
        display.ProcessEvents();
        dispstate(state, display, -1);
        display.Render();

        if (display.IsKeyPressed(EKey::KEY_UP)) {
            usleep(300000);
            gameStatus = logic.action(1);
            state = logic.getstate();
        }
        if (display.IsKeyPressed(EKey::KEY_DOWN)) {
            usleep(300000);
            gameStatus = logic.action(2);
            state = logic.getstate();
        }
        if (display.IsKeyPressed(EKey::KEY_RIGHT)) {
            usleep(300000);
            gameStatus = logic.action(3);
            state = logic.getstate();
        }
        if (display.IsKeyPressed(EKey::KEY_LEFT)) {
            usleep(300000);
            gameStatus = logic.action(4);
            state = logic.getstate();
        }
    }
    if (gameStatus == 1) {
        display.DrawWinMessage();
        std::cout << "You win!" << std::endl; 
        sleep(4);
    }
    if (gameStatus == 2) {
        std::cout << "You lose(((" << std::endl; 
        sleep(4);
    }
    return;
}

void TGameEngine::dispstate(std::vector<int> &state, TDisplay &display, int action) {
    
    for (int i = 0; i < 16; ++i) {
        std::cout << state[i] << ' ';
        if (i % 4 == 3) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < 16; ++i) {
        if (state[i] != 0) {
            disptile(state[i], display, i / 4, i % 4);
        }
    }
}

void TGameEngine::disptile (int i, TDisplay &display, float x, float y) {
    switch (i) {
        case 1:
            display.DrawTile(x, y, ETileType::TILE_1);
            break;
        case 2:
            display.DrawTile(x, y, ETileType::TILE_2);
            break;
        case 4:
            display.DrawTile(x, y, ETileType::TILE_4);
            break;
        case 8:
            display.DrawTile(x, y, ETileType::TILE_8);
            break;
        case 16:
            display.DrawTile(x, y, ETileType::TILE_16);
            break;
        case 32:
            display.DrawTile(x, y, ETileType::TILE_32);
            break;
        case 64:
            display.DrawTile(x, y, ETileType::TILE_64);
            break;
        case 128:
            display.DrawTile(x, y, ETileType::TILE_128);
            break;
        case 256:
            display.DrawTile(x, y, ETileType::TILE_256);
            break;
        case 512:
            display.DrawTile(x, y, ETileType::TILE_512);
            break;
        case 1024:
            display.DrawTile(x, y, ETileType::TILE_1024);
            break;
        case 2048:
            display.DrawTile(x, y, ETileType::TILE_2048);
            break;
        default:
            display.DrawTile(x, y, ETileType::TILE_2048);
            break;
        }
}