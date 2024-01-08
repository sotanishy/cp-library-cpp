#pragma once
#include <algorithm>
#include <stack>
#include <vector>

std::vector<int> topological_sort(const std::vector<std::vector<int>>& G) {
    const int n = G.size();
    std::vector<int> par_count(n);
    for (int u = 0; u < n; ++u) {
        for (int v : G[u]) ++par_count[v];
    }
    std::stack<int> st;
    for (int v = 0; v < n; ++v) {
        if (par_count[v] == 0) st.push(v);
    }

    std::vector<int> ord;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        ord.push_back(u);
        for (int v : G[u]) {
            --par_count[v];
            if (par_count[v] == 0) st.push(v);
        }
    }

    if (*std::ranges::max_element(par_count) > 0) return {};
    return ord;
}