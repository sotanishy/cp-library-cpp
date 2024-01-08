#pragma once
#include <algorithm>
#include <utility>
#include <vector>

class Lowlink {
   public:
    std::vector<int> ord, low;
    std::vector<std::pair<int, int>> bridge;
    std::vector<int> articulation;

    Lowlink() = default;
    explicit Lowlink(const std::vector<std::vector<int>>& G)
        : ord(G.size(), -1), low(G.size()), G(G) {
        for (int i = 0; i < (int)G.size(); ++i) {
            if (ord[i] == -1) dfs(i, -1);
        }
    }

    bool is_bridge(int u, int v) const {
        if (ord[u] > ord[v]) std::swap(u, v);
        return ord[u] < low[v];
    }

   private:
    std::vector<std::vector<int>> G;
    int k = 0;

    void dfs(int v, int p) {
        ord[v] = k++;
        low[v] = ord[v];
        bool is_articulation = false, checked = false;
        int cnt = 0;
        for (int c : G[v]) {
            if (c == p && !checked) {
                checked = true;
                continue;
            }
            if (ord[c] == -1) {
                ++cnt;
                dfs(c, v);
                low[v] = std::min(low[v], low[c]);
                if (p != -1 && ord[v] <= low[c]) is_articulation = true;
                if (ord[v] < low[c]) bridge.push_back(std::minmax(v, c));
            } else {
                low[v] = std::min(low[v], ord[c]);
            }
        }
        if (p == -1 && cnt > 1) is_articulation = true;
        if (is_articulation) articulation.push_back(v);
    }
};