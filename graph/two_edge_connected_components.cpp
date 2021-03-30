#pragma once
#include <vector>
#include "lowlink.cpp"

class TwoEdgeConnectedComponents : Lowlink {
public:
    TwoEdgeConnectedComponents() = default;
    explicit TwoEdgeConnectedComponents(const std::vector<std::vector<int>>& G) : Lowlink(G), comp(G.size(), -1) {
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
    std::vector<int> comp;
    int cnt = 0;

    void dfs(int u, int c) {
        comp[u] = c;
        for (int v : G[u]) {
            if (comp[v] == -1 && !is_bridge(u, v)) dfs(v, c);
        }
    }
};