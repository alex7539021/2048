#ifndef TGameLogic_H
#define TGameLogic_H

#include <display/display.h>

#include <vector>
#include <iostream>

class TGameLogic {

    int state[16]; //0 empty
    int game_status;   //1 - vin, 2 - lose
    int empty;

public:
    TGameLogic();
    ~TGameLogic();

    int action(int num);  // 1 up, 2 down, 3 right, 4 left
    std::vector<int> getstate() const;
    std::vector<std::pair<std::pair<int, int> ,int>> getmove() const;
    void printstate();
};

#endif