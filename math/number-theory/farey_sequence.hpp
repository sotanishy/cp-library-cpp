#pragma once
#include <utility>
#include <vector>

/**
 * @brief Farey Sequence
 */
std::vector<std::pair<int, int>> farey_sequence(int n) {
    int a = 0, b = 1, c = 1, d = n;
    std::vector<std::pair<int, int>> seq;
    seq.push_back({a, b});
    seq.push_back({c, d});
    while (d != 1) {
        int k = (n + b) / d;
        int e = k * c - a;
        int f = k * d - b;
        seq.push_back({e, f});
        a = c;
        b = d;
        c = e;
        d = f;
    }
    return seq;
}