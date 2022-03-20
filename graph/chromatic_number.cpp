#pragma once
#include <vector>

int chromatic_number(std::vector<std::vector<bool>>& G) {
    int n = G.size();
    std::vector<int> edges(n);
    for (int i = 0; i < (int) G.size(); ++i) {
        for (int j = 0; j < (int) G.size(); ++j) {
            if (G[i][j]) edges[i] |= 1 << j;
        }
    }
    // number of subsets of S that are independent
    std::vector<int> ind(1 << n);
    ind[0] = 1;
    for (int S = 1; S < (1 << n); ++S) {
        int v = __builtin_ctz(S);
        // (not containing v) + (containing v)
        ind[S] = ind[S ^ (1 << v)] + ind[(S ^ (1 << v)) & ~edges[v]];
    }
    // number of ways to choose k subsets of S that are independent
    auto f = ind;
    for (int k = 1; ; ++k) {
        // numer of ways to choose k subsets of S so that they cover S
        int g = 0;
        for (int S = 0; S < (1 << n); ++S) {
            g += (__builtin_parity(S) ? -1 : 1) * f[S];
        }
        if (g) return k;
        for (int S = 1; S < (1 << n); ++S) {
            f[S] *= ind[S];
        }
    }
}