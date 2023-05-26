#pragma once
#include <stack>
#include <utility>
#include <vector>

std::vector<int> eulerian_walk(const std::vector<std::pair<int, int>>& edges,
                               int V) {
    std::vector<std::vector<std::pair<int, int>>> G(V);
    std::vector<int> deg(V);
    for (int i = 0; i < (int)edges.size(); ++i) {
        auto [a, b] = edges[i];
        G[a].push_back({b, i});
        G[b].push_back({a, i});
        ++deg[a];
        ++deg[b];
    }
    int s = 0;
    int cnt = 0;
    for (int i = 0; i < V; ++i) {
        if (deg[i] % 2) {
            ++cnt;
            s = i;
        }
    }
    if (cnt != 0 && cnt != 2) return {};
    std::vector<int> ret;
    std::stack<int> st;
    st.push(s);
    std::vector<bool> used(edges.size());
    while (!st.empty()) {
        int u = st.top();
        while (!G[u].empty() && used[G[u].back().second]) G[u].pop_back();
        if (G[u].empty()) {
            ret.push_back(u);
            st.pop();
        } else {
            auto [v, i] = G[u].back();
            G[u].pop_back();
            used[i] = true;
            st.emplace(v);
        }
    }
    return ret;
}