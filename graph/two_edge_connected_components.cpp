#include <bits/stdc++.h>
#include "lowlink.cpp"

/*
 * @brief 2-Edge-Connected Components
 * @docs docs/graph/two_edge_connected_components.md
 */
class TwoEdgeConnectedComponents {
public:
    TwoEdgeConnectedComponents() = default;
    explicit TwoEdgeConnectedComponents(const std::vector<std::vector<int>>& G)
        : G(G), comp(G.size(), -1), lowlink(G) {
        for (int v = 0; v < (int) G.size(); ++v) {
            if (comp[v] == -1) dfs(v, cnt++);
        }
    }

    int operator[](int i) const {
        return comp[i];
    }

    int count() const noexcept {
        return cnt;
    }

private:
    std::vector<std::vector<int>> G;
    std::vector<int> comp;
    Lowlink lowlink;
    int cnt = 0;

    void dfs(int u, int c) {
        comp[u] = c;
        for (int v : G[u]) {
            if (comp[v] == -1 && !lowlink.is_bridge(u, v)) dfs(v, c);
        }
    }
};