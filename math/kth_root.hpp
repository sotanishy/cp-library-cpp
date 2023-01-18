#pragma once
#include <cassert>
#include <cmath>

unsigned long long kth_root(unsigned long long x, int k) {
    using ull = unsigned long long;
    assert(k >= 1);
    if (x <= 1 || k == 1) return x;
    auto check = [&](ull a) {
        ull y = x;
        int e = k;
        while (e) {
            if (e & 1) {
                if (a == 0) return false;
                y /= a;
            }
            if (a > 0 && a > y / a)
                a = 0;
            else
                a *= a;
            e >>= 1;
        }
        return y > 0;
    };
    ull res = std::pow(x, std::nextafter(1.0 / k, 0.0));
    while (check(res + 1)) ++res;
    return res;
}