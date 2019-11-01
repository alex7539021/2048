#include "logic.h"

#include <iostream>

/*
 [0,  1,  2,  3,
  4,  5,  6,  7,
  8,  9,  10, 11,
  12, 13, 14, 15]
*/

TGameLogic::TGameLogic() {
    game_status = 0;   //1 - vin, 2 - lose
    srand(time(NULL));
    for (int k = 0; k < 16; ++k) {
        state[k] = 0;
    }

    int i, j;
    i = rand() % 16;
    j = rand() % 16;
    while (i == j) {
        j = rand() % 16;
    }
    state[i] = 2;
    state[j] = 2;

    empty = 14;
}

TGameLogic::~TGameLogic() {}

int TGameLogic::action(int num) {
    srand(time(NULL));
    char act = 0;

    switch (num) {
    case 1: 
        for (int i = 0; i < 4; ++i) {
            if (state[i + 8] == 0) {
                state[i + 8] = state[i + 12];
                state[i + 12] = 0;
                if (state[i + 8]) {
                    act = 1;
                }
            }
            if (state[i + 4] == 0) {
                state[i + 4] = state[i + 8];
                state[i + 8] = state[i + 12];
                state[i + 12] = 0;
                if ((state[i + 4]) || (state[i + 8])) {
                    act = 1;
                }
            }
            if (state[i] == 0) {
                state[i] = state[i + 4];
                state[i + 4] = state[i + 8];
                state[i + 8] = state[i + 12];
                state[i + 12] = 0;
                if ((state[i]) || (state[i + 4]) || (state[i + 8])) {
                    act = 1;
                }
            }
            if ((state[i] != 0) && (state[i] == state[i + 4])) {
                state[i] *= 2;
                state[i + 4] = state[i + 8];
                state[i + 8] = state[i + 12];
                state[i + 12] = 0;
                act = 1;
                empty += 1;
                if (state[i] == 2048) {
                    game_status = 1;
                }
            }
            if ((state[i + 4] != 0) && (state[i + 4] == state[i + 8])) {
                state[i + 4] *= 2;
                state[i + 8] = state[i + 12];
                state[i + 12] = 0;
                act = 1;
                empty += 1;
                if (state[i + 4] == 2048) {
                    game_status = 1;
                }
            }
            if ((state[i + 8] != 0) && (state[i + 8] == state[i + 12])) {
                state[i + 8] *= 2;
                state[i + 12] = 0;
                act = 1;
                empty += 1;
                if (state[i + 8] == 2048) {
                    game_status = 1;
                }
            }
        }
        break;

    case 2: 
        for (int i = 0; i < 4; ++i) {
            if (state[i + 4] == 0) {
                state[i + 4] = state[i];
                state[i] = 0;
                if (state[i + 4]) {
                    act = 1;
                }
            }
            if (state[i + 8] == 0) {
                state[i + 8] = state[i + 4];
                state[i + 4] = state[i];
                state[i] = 0;
                if ((state[i + 4]) || (state[i + 8])) {
                    act = 1;
                }
            }
            if (state[i + 12] == 0) {
                state[i + 12] = state[i + 8];
                state[i + 8] = state[i + 4];
                state[i + 4] = state[i];
                state[i] = 0;
                if ((state[i + 4]) || (state[i + 8]) || (state[i + 12])) {
                    act = 1;
                }
            }
            if ((state[i + 12] != 0) && (state[i + 12] == state[i + 8])) {
                state[i + 12] *= 2;
                state[i + 8] = state[i + 4];
                state[i + 4] = state[i];
                state[i] = 0;
                act = 1;
                empty += 1;
                if (state[i + 12] == 2048) {
                    game_status = 1;
                }
            }
            if ((state[i + 8] != 0) && (state[i + 8] == state[i + 4])) {
                state[i + 8] *= 2;
                state[i + 4] = state[i];
                state[i] = 0;
                act = 1;
                empty += 1;
                if (state[i + 8] == 2048) {
                    game_status = 1;
                }
            }
            if ((state[i + 4] != 0) && (state[i + 4] == state[i])) {
                state[i + 4] *= 2;
                state[i] = 0;
                act = 1;
                empty += 1;
                if (state[i + 4] == 2048) {
                    game_status = 1;
                }
            }
        }
        break;

    case 3: 
        for (int j = 0; j < 4; ++j) {
            int i = j * 4;
            if (state[i + 1] == 0) {
                state[i + 1] = state[i];
                state[i] = 0;
                if (state[i + 1]) {
                    act = 1;
                }
            }
            if (state[i + 2] == 0) {
                state[i + 2] = state[i + 1];
                state[i + 1] = state[i];
                state[i] = 0;
                if ((state[i + 2]) || (state[i + 1])) {
                    act = 1;
                }
            }
            if (state[i + 3] == 0) {
                state[i + 3] = state[i + 2];
                state[i + 2] = state[i + 1];
                state[i + 1] = state[i];
                state[i] = 0;
                if ((state[i + 3]) || (state[i + 2]) || (state[i + 1])) {
                    act = 1;
                }
            }
            if ((state[i + 3] != 0) && (state[i + 3] == state[i + 2])) {
                state[i + 3] *= 2;
                state[i + 2] = state[i + 1];
                state[i + 1] = state[i];
                state[i] = 0;
                act = 1;
                empty += 1;
                if (state[i + 3] == 2048) {
                    game_status = 1;
                }
            }
            if ((state[i + 2] != 0) && (state[i + 2] == state[i + 1])) {
                state[i + 2] *= 2;
                state[i + 1] = state[i];
                state[i] = 0;
                act = 1;
                empty += 1;
                if (state[i + 2] == 2048) {
                    game_status = 1;
                }
            }
            if ((state[i + 1] != 0) && (state[i + 1] == state[i])) {
                state[i + 1] *= 2;
                state[i] = 0;
                act = 1;
                empty += 1;
                if (state[i + 1] == 2048) {
                    game_status = 1;
                }
            }
        }
        break;

    case 4: 
        for (int j = 0; j < 4; ++j) {
            int i = j * 4;
            if (state[i + 2] == 0) {
                state[i + 2] = state[i + 3];
                state[i + 3] = 0;
                if (state[i + 2]) {
                    act = 1;
                }
            }
            if (state[i + 1] == 0) {
                state[i + 1] = state[i + 2];
                state[i + 2] = state[i + 3];
                state[i + 3] = 0;
                if ((state[i + 1]) || (state[i + 2])) {
                    act = 1;
                }
            }
            if (state[i] == 0) {
                state[i] = state[i + 1];
                state[i + 1] = state[i + 2];
                state[i + 2] = state[i + 3];
                state[i + 3] = 0;
                if ((state[i]) || (state[i + 1]) || (state[i + 2])) {
                    act = 1;
                }
            }
            if ((state[i] != 0) && (state[i] == state[i + 1])) {
                state[i] *= 2;
                state[i + 1] = state[i + 2];
                state[i + 2] = state[i + 3];
                state[i + 3] = 0;
                act = 1;
                empty += 1;
                if (state[i] == 2048) {
                    game_status = 1;
                }
            }
            if ((state[i + 1] != 0) && (state[i + 1] == state[i + 2])) {
                state[i + 1] *= 2;
                state[i + 2] = state[i + 3];
                state[i + 3] = 0;
                act = 1;
                empty += 1;
                if (state[i + 1] == 2048) {
                    game_status = 1;
                }
            }
            if ((state[i + 2] != 0) && (state[i + 2] == state[i + 3])) {
                state[i + 2] *= 2;
                state[i + 3] = 0;
                act = 1;
                empty += 1;
                if (state[i + 2] == 2048) {
                    game_status = 1;
                }
            }
        }
        break;
    }

    if (empty == 0) { //поле заполнено 
        game_status = 2;
    }

    if (act && (!game_status)) { //появление нового квадрата (4 с вероятностью 20%)
        int i = 0;
        int j;
        j = rand() % empty;

        while (1) {
            if (state[i % 16] == 0) {
                if (!j) {
                    int k;
                    k = rand() % 10;
                    if (k < 8) {
                        state[i % 16] = 2;
                        empty -= 1;
                        break;
                    } else {
                        state[i % 16] = 4;
                        empty -= 1;
                        break;
                    }
                }
                j -= 1;
            }
            i++;
        }
    }
    return game_status;
}

void TGameLogic::printstate() {
    for (int i = 0; i < 16; ++i) {
        std::cout << state[i] << ' ';
        if (i % 4 == 3) {
            std::cout << std::endl;
        }
    }
}

std::vector<int> TGameLogic::getstate() const {
    std::vector<int> copy(16);
    for (int i = 0; i < 16; ++i) {
        copy[i] = state[i];
    }
    return copy;
}
