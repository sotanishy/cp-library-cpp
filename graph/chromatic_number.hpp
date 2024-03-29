#pragma once
#include <bit>
#include <vector>

int chromatic_number(std::vector<std::vector<bool>>& G) {
    const int n = G.size();
    std::vector<int> neighbor(n);
    for (int i = 0; i < (int)G.size(); ++i) {
        for (int j = 0; j < (int)G.size(); ++j) {
            if (G[i][j]) neighbor[i] |= 1 << j;
        }
    }
    // number of subsets of S that are independent
    std::vector<int> ind(1 << n);
    ind[0] = 1;
    for (int S = 1; S < (1 << n); ++S) {
        int v = std::countr_zero((unsigned int)S);
        // (not containing v) + (containing v)
        ind[S] = ind[S ^ (1 << v)] + ind[(S ^ (1 << v)) & ~neighbor[v]];
    }
    // number of ways to choose k subsets of S that are independent
    auto f = ind;
    for (int k = 1;; ++k) {
        // numer of ways to choose k subsets of S so that they cover S
        int g = 0;
        for (int S = 0; S < (1 << n); ++S) {
            g += (std::popcount((unsigned int)S) & 1 ? -1 : 1) * f[S];
        }
        if (g) return k;
        for (int S = 1; S < (1 << n); ++S) {
            f[S] *= ind[S];
        }
    }
}