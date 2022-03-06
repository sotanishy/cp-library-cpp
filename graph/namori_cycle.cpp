#pragma once
#include <stack>
#include <vector>

/**
 * @brief Namori Cycle
 */
std::vector<int> namori_cycle(const std::vector<std::vector<int>>& G) {
    int n = G.size();
    std::vector<int> deg(n);
    std::stack<int> st;
    for (int i = 0; i < n; ++i) {
        deg[i] = G[i].size();
        if (deg[i] == 1) st.push(i);
    }
    while (!st.empty()) {
        int v = st.top();
        st.pop();
        deg[v] = 0;
        for (int u : G[v]) {
            if (deg[u] == 0) continue;
            --deg[u];
            if (deg[u] == 1) {
                st.push(u);
            }
        }
    }
    int v, p = -1;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 2) {
            v = i;
            break;
        }
    }
    std::vector<int> cycle;
    do {
        cycle.push_back(v);
        for (int u : G[v]) {
            if (u != p && deg[u] == 2) {
                p = v;
                v = u;
                break;
            }
        }
    } while (v != cycle[0]);
    return cycle;
}