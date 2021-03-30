#pragma once
#include <stack>
#include <utility>
#include <vector>
#include "lowlink.cpp"

class BiconnectedComponents : Lowlink {
public:
    BiconnectedComponents() = default;
    explicit BiconnectedComponents(const std::vector<std::vector<int>>& G) : Lowlink(G), used(G.size()) {
        for (int v = 0; v < (int) G.size(); ++v) {
            if (!used[v] == -1) dfs(v, -1);
        }
    }

    std::vector<std::vector<std::pair<int, int>>> get_biconnected_components() const {
        return bc;
    }

private:
    std::vector<std::vector<int>> G;
    std::vector<bool> used;
    std::stack<std::pair<int, int>> st;
    std::vector<std::vector<std::pair<int, int>>> bc;

    void dfs(int v, int p) {
        for (int c : G[v]) {
            if (c == p) continue;
            if (!used[c] || ord[c] < ord[v]) {
                st.emplace(v, c);
            }
            if (!used[c]) {
                dfs(c, v);
                if (low[c] >= ord[v]) {
                    bc.emplace_back();
                    while (true) {
                        auto e = st.top();
                        st.pop();
                        bc.back().push_back(e);
                        if (e.first == v) {
                            break;
                        }
                    }
                }
            }
        }
    }
};