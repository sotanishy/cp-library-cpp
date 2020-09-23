#include <bits/stdc++.h>

class Random {
public:
    // returns a random integer in the range [0, n)
    unsigned int next_int(int n) {
        return xorshift() % n;
    }

    // returns a random double number in the range [0, 1)
    double next_double() {
        return xorshift() * (1.0 / 0xFFFFFFFFu);
    }

private:
    unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;

    unsigned int xorshift() {
        unsigned int t;
        t = x ^ (x << 11);
        x = y; y = z; z = w;
        return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
    }
};