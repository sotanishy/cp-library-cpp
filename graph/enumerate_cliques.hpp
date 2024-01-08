#pragma once
#include <cmath>
#include <vector>

std::vector<std::vector<int>> enumerate_cliques(
    const std::vector<std::vector<bool>>& G) {
    int N = G.size(), M = 0;
    std::vector<int> deg(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (G[i][j]) {
                ++deg[i];
                ++M;
            }
        }
    }
    M /= 2;
    int B = std::sqrt(2 * M);
    std::vector<std::vector<int>> cliques;

    auto check = [&](const std::vector<int>& vs, bool use_first) {
        int n = vs.size();
        for (int S = 1; S < 1 << n; ++S) {
            if (use_first && !(S & 1)) continue;
            bool ok = true;
            for (int i = 0; i < n - 1; ++i) {
                if (!(S >> i & 1)) continue;
                for (int j = i + 1; j < n; ++j) {
                    if ((S >> j & 1) && !G[vs[i]][vs[j]]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) {
                cliques.emplace_back();
                for (int i = 0; i < n; ++i) {
                    if (S >> i & 1) {
                        cliques.back().push_back(vs[i]);
                    }
                }
            }
        }
    };

    std::vector<bool> checked(N);
    std::vector<int> big;
    for (int i = 0; i < N; ++i) {
        if (deg[i] >= B) {
            big.push_back(i);
            continue;
        }
        std::vector<int> vs;
        vs.push_back(i);
        for (int j = 0; j < N; ++j) {
            if (G[i][j] && !checked[j]) {
                vs.push_back(j);
            }
        }
        check(vs, true);
        checked[i] = true;
    }
    check(big, false);
    return cliques;
}
