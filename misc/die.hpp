#pragma once
#include <cassert>

/**
 * @brief Die
 */
struct Die {
    int top = 1, south = 2, east = 3, west = 4, north = 5, bottom = 6;

    void roll(char dir) {
        if (dir == 'N') {
            int tmp = top;
            top = south;
            south = bottom;
            bottom = north;
            north = tmp;
        } else if (dir == 'E') {
            int tmp = top;
            top = west;
            west = bottom;
            bottom = east;
            east = tmp;
        } else if (dir == 'W') {
            int tmp = top;
            top = east;
            east = bottom;
            bottom = west;
            west = tmp;
        } else if (dir == 'S') {
            int tmp = top;
            top = north;
            north = bottom;
            bottom = south;
            south = tmp;
        } else {
            assert(false);
        }
    }
};