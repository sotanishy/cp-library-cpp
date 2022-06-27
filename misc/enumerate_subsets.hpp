#pragma once
#include <vector>

/**
 * @brief Enumerate Subsets
 */
std::vector<int> enumerate_subsets(int n, int k) {
    if (k < 0 || n < k) return {};
    if (k == 0) return {0};
    std::vector<int> ret;
    int comb = (1 << k) - 1;
    while (comb < (1 << n)) {
        ret.push_back(comb);
        int x = comb & -comb;
        int y = comb + x;
        comb = ((comb & ~y) / x >> 1) | y;
    }
    return ret;
}