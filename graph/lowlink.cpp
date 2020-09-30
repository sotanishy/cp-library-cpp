#include <bits/stdc++.h>

/*
 * @brief Lowlink
 * @docs docs/graph/lowlink.md
 */
class Lowlink {
public:
    Lowlink() = default;
    explicit Lowlink(const std::vector<std::vector<int>> G) : G(G), ord(G.size(), -1), low(G.size()) {
        for (int i = 0; i < (int) G.size(); ++i) {
            if (ord[i] == -1) dfs(i, -1);
        }
    }

    std::vector<std::pair<int, int>> get_bridges() const {
        return bridge;
    }

    std::vector<int> get_articulation_points() const {
        return articulation;
    }

private:
    std::vector<std::vector<int>> G;
    std::vector<int> ord, low;
    std::vector<std::pair<int, int>> bridge;
    std::vector<int> articulation;
    int k = 0;

    void dfs(int v, int p) {
        ord[v] = k++;
        low[v] = ord[v];
        bool is_articulation = false;
        int cnt = 0;
        for (int c : G[v]) {
            if (ord[c] == -1) {
                ++cnt;
                dfs(c, v);
                low[v] = std::min(low[v], low[c]);
                if (p != -1 && ord[v] <= low[c]) is_articulation = true;
                if (ord[v] < low[c]) bridge.emplace_back(std::min(v, c), std::max(v, c));
            } else if (c != p) {
                low[v] = std::min(low[v], ord[c]);
            }
        }
        if (p == -1 && cnt > 1) is_articulation = true;
        if (is_articulation) articulation.push_back(v);
    }
};