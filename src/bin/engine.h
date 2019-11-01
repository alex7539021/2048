#ifndef TGameEngine_H
#define TGameEngine_H

#include <display/display.h>

#include "logic.h"

class TGameEngine {

public:
    TGameEngine();
    ~TGameEngine();

    void game();
    void dispstate(std::vector<int> &state, TDisplay &display, int action);
    void disptile(int i, TDisplay &display, float x, float y);
};

#endif