#pragma once
#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

template <typename T>
std::vector<int> assignment(const std::vector<std::vector<T>>& cost) {
    constexpr T INF = std::numeric_limits<T>::max();
    const int n = cost.size(), m = cost[0].size();
    std::vector<T> yrow(n), ycol(m);
    std::vector<int> materow(n, -1), matecol(m, -1), par(m, -1);
    std::vector<bool> usedrow(n), usedcol(m);
    std::vector<T> slack(m), slack_idx(m, -1);

    for (int i = 0; i < n; ++i) {
        yrow[i] = *std::ranges::max_element(cost[i]);
    }

    // add the edge (j, i) to the alternating tree
    auto add_to_tree = [&](int i) {
        usedrow[i] = true;
        for (int j = 0; j < m; ++j) {
            T s = yrow[i] + ycol[j] - cost[i][j];
            if (s < slack[j]) {
                slack[j] = s;
                slack_idx[j] = i;
            }
        }
    };

    auto augment = [&](int i, int j) {
        while (true) {
            int k = materow[i];
            matecol[j] = i;
            materow[i] = j;

            if (k == -1) break;
            j = k;
            i = par[j];
        }
    };

    for (int t = 0; t < n; ++t) {
        std::fill(usedrow.begin(), usedrow.end(), false);
        std::fill(usedcol.begin(), usedcol.end(), false);
        std::ranges::fill(par, -1);
        std::queue<int> que;
        // seed
        for (int i = 0; i < n; ++i) {
            if (materow[i] == -1) {
                que.push(i);
                usedrow[i] = true;
                for (int j = 0; j < m; ++j) {
                    slack[j] = yrow[i] + ycol[j] - cost[i][j];
                    slack_idx[j] = i;
                }
                break;
            }
        }

        // repeat until an augmenting path is found
        bool aug = false;
        while (!aug) {
            while (!aug && !que.empty()) {
                int i = que.front();
                que.pop();
                for (int j = 0; j < m; ++j) {
                    if (cost[i][j] == yrow[i] + ycol[j] && !usedcol[j]) {
                        if (matecol[j] == -1) {
                            // augment
                            augment(i, j);
                            aug = true;
                            break;
                        }
                        // grow
                        usedcol[j] = true;
                        par[j] = i;
                        add_to_tree(matecol[j]);
                        que.push(matecol[j]);
                    }
                }
            }
            if (aug) break;

            // update y
            T delta = INF;
            for (int j = 0; j < m; ++j) {
                if (!usedcol[j]) delta = std::min(delta, slack[j]);
            }
            for (int i = 0; i < n; ++i) {
                if (usedrow[i]) yrow[i] -= delta;
            }
            for (int j = 0; j < m; ++j) {
                if (usedcol[j])
                    ycol[j] += delta;
                else
                    slack[j] -= delta;
            }
            // add new edges of the equality graph to the alternating tree
            for (int j = 0; j < m; ++j) {
                if (!usedcol[j] && slack[j] == 0) {
                    if (matecol[j] == -1) {
                        augment(slack_idx[j], j);
                        aug = true;
                        break;
                    } else {
                        usedcol[j] = true;
                        par[j] = slack_idx[j];
                        add_to_tree(matecol[j]);
                        que.push(matecol[j]);
                    }
                }
            }
        }
    }
    return materow;
}