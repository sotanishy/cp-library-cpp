#pragma once
#include <vector>
#include "scc.cpp"

class TwoSat {
public:
    TwoSat() = default;
    explicit TwoSat(int n) : n(n), G(2 * n), val(n) {}

    void add_clause(int u, bool a, int v, bool b) {
        G[n * a + u].push_back(n * (!b) + v);
        G[n * b + v].push_back(n * (!a) + u);
    }

    void solve() {
        auto comp = scc(G);
        for (int i = 0; i < n; ++i) {
            if (comp[i] == comp[n + i]) {
                satisfiable = false;
                break;
            }
            val[i] = comp[i] > comp[n + i];
        }
    }

    bool is_satisfiable() const noexcept {
        return satisfiable;
    }

    bool operator[](int i) const {
        return val[i];
    }

private:
    int n;
    std::vector<std::vector<int>> G;
    std::vector<bool> val;
    bool satisfiable = true;
};