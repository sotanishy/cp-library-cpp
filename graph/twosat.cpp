#pragma once
#include <vector>
#include "scc.cpp"

/*
 * @brief 2-SAT
 * @docs docs/graph/twosat.md
 */
class TwoSat {
public:
    TwoSat() = default;
    explicit TwoSat(int n) : n(n), scc(2 * n), val(n) {}

    void add_clause(int u, bool a, int v, bool b) {
        scc.add_edge(n * a + u, n * (!b) + v);
        scc.add_edge(n * b + v, n * (!a) + u);
    }

    void solve() {
        scc.build();
        for (int i = 0; i < n; ++i) {
            if (scc[i] == scc[n + i]) {
                satisfiable = false;
                break;
            }
            val[i] = scc[i] > scc[n + i];
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
    SCC scc;
    std::vector<bool> val;
    bool satisfiable = true;
};