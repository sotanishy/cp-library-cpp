#pragma once
#include <algorithm>
#include <map>
#include <stack>
#include <utility>
#include <vector>

#include "../graph/bipartite_matching.hpp"

std::vector<int> bipartite_edge_coloring(
    const std::vector<std::pair<int, int>>& edges, int n1, int n2) {
    const int E = edges.size();
    // find the maximum degree D
    std::vector<int> deg1(n1), deg2(n2);
    for (auto [a, b] : edges) {
        ++deg1[a], ++deg2[b];
    }
    const int D = std::max(*max_element(deg1.begin(), deg1.end()),
                           *max_element(deg2.begin(), deg2.end()));

    // convert to D-regular bipartite graph
    // merge vertices with the sum of degrees <= D
    auto contract = [&](const auto& deg) {
        const int n = deg.size();
        std::vector<std::pair<int, int>> vs(n);
        for (int i = 0; i < n; ++i) vs[i] = {deg[i], i};
        std::sort(vs.begin(), vs.end());

        std::vector<int> id(n);
        std::vector<int> ndeg;

        int k = 0;
        for (int i = 0; i < n;) {
            int d = 0;
            int j = i;
            while (j < n && d + vs[j].first <= D) {
                d += vs[j].first;
                id[vs[j].second] = k;
                ++j;
            }
            ndeg.push_back(d);
            ++k;
            i = j;
        }

        return std::make_pair(id, ndeg);
    };

    auto [id1, ndeg1] = contract(deg1);
    auto [id2, ndeg2] = contract(deg2);

    using Edge = std::tuple<int, int, int>;
    std::vector<Edge> edges2;
    for (int i = 0; i < E; ++i) {
        auto [a, b] = edges[i];
        edges2.emplace_back(id1[a], id2[b], i);
    }

    // add dummy vertices
    const int n = std::max(ndeg1.size(), ndeg2.size());
    ndeg1.resize(n);
    ndeg2.resize(n);

    // add dummy edges
    int j = 0;
    int nE = E;
    for (int i = 0; i < n; ++i) {
        while (ndeg1[i] < D) {
            while (ndeg2[j] == D) ++j;
            edges2.emplace_back(i, j, nE++);
            ++ndeg1[i];
            ++ndeg2[j];
        }
    }

    // find the edge coloring
    std::vector<int> color(nE);
    int k = 0;

    auto rec = [&](auto& rec, const std::vector<Edge>& edges, int D) -> void {
        if (D == 1) {
            for (auto [a, b, i] : edges) {
                color[i] = k;
            }
            ++k;
            return;
        } else if (D % 2 == 0) {
            // find an eulerian walk for each connected component
            // partition the graph into two
            std::vector<std::vector<std::pair<int, int>>> G(2 * n);
            for (int j = 0; j < (int)edges.size(); ++j) {
                auto [a, b, i] = edges[j];
                G[a].emplace_back(n + b, j);
                G[n + b].emplace_back(a, j);
            }
            std::vector<bool> used_v(2 * n), used_e(edges.size());
            std::vector<std::vector<Edge>> edges2(2);

            for (int v = 0; v < n; ++v) {
                if (used_v[v]) continue;

                std::vector<int> walk;
                std::stack<std::pair<int, int>> st;
                st.emplace(v, -1);
                while (!st.empty()) {
                    auto [u, j] = st.top();
                    used_v[u] = true;
                    while (!G[u].empty() && used_e[G[u].back().second]) {
                        G[u].pop_back();
                    }
                    if (G[u].empty()) {
                        walk.push_back(j);
                        st.pop();
                    } else {
                        auto [v, k] = G[u].back();
                        G[u].pop_back();
                        used_e[k] = true;
                        st.emplace(v, k);
                    }
                }

                for (int i = 0; i < (int)walk.size() - 1; ++i) {
                    edges2[i % 2].push_back(edges[walk[i]]);
                }
            }
            rec(rec, edges2[0], D / 2);

            int nD = 1;
            while (nD < D / 2) nD <<= 1;

            // add nD-D/2 edges from edges2[0] to edges2[1]
            for (auto [a, b, i] : edges2[0]) {
                if (color[i] >= k - (nD - D / 2)) {
                    edges2[1].emplace_back(a, b, i);
                }
            }
            k -= nD - D / 2;

            rec(rec, edges2[1], nD);
        } else {
            // paint the edges in a perfect matching with the same color
            BipartiteMatching bm(n, n);
            for (auto [a, b, i] : edges) {
                bm.add_edge(a, b);
            }
            std::vector<int> match(n, -1);
            for (auto [a, b] : bm.max_matching()) {
                match[a] = b;
            }
            std::vector<Edge> edges2;
            for (auto [a, b, i] : edges) {
                if (match[a] == b) {
                    color[i] = k;
                    match[a] = -1;
                } else {
                    edges2.emplace_back(a, b, i);
                }
            }
            ++k;
            rec(rec, edges2, D - 1);
        }
    };

    rec(rec, edges2, D);
    color.resize(E);
    return color;
}

std::vector<std::pair<int, int>> regular_bipartite_matching(
    const std::vector<std::pair<int, int>>& edges, int D) {
    const int n = edges.size() / D;

    auto rec = [&](auto& rec, const auto& edges, int D) {
        if (D == 1) {
            return edges;
        } else if (D % 2 == 0) {
            // find an eulerian walk for each connected component
            // partition the graph into two
            std::vector<std::vector<std::pair<int, int>>> G(2 * n);
            for (int j = 0; j < (int)edges.size(); ++j) {
                auto [a, b, d] = edges[j];
                G[a].emplace_back(n + b, j);
                G[n + b].emplace_back(a, j);
            }
            std::vector<bool> used_v(2 * n), used_e(edges.size());
            std::vector<std::vector<std::tuple<int, int, bool>>> edges2(2);
            std::vector<int> dummy_cnt(2);

            for (int v = 0; v < n; ++v) {
                if (used_v[v]) continue;

                std::vector<int> walk;
                std::stack<std::pair<int, int>> st;
                st.emplace(v, -1);
                while (!st.empty()) {
                    auto [u, j] = st.top();
                    used_v[u] = true;
                    while (!G[u].empty() && used_e[G[u].back().second]) {
                        G[u].pop_back();
                    }
                    if (G[u].empty()) {
                        walk.push_back(j);
                        st.pop();
                    } else {
                        auto [v, k] = G[u].back();
                        G[u].pop_back();
                        used_e[k] = true;
                        st.emplace(v, k);
                    }
                }

                for (int i = 0; i < (int)walk.size() - 1; ++i) {
                    edges2[i % 2].push_back(edges[walk[i]]);
                    dummy_cnt[i % 2] += std::get<2>(edges[walk[i]]);
                }
            }
            return rec(rec, dummy_cnt[0] < dummy_cnt[1] ? edges2[0] : edges2[1],
                       D / 2);
        } else {
            int size = 1;
            while (size < D) size <<= 1;

            // add size-D dummy edges
            auto edges2 = edges;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < size - D; ++j) {
                    edges2.emplace_back(i, i, true);
                }
            }

            while (true) {
                auto res = rec(rec, edges2, size);
                int cnt = 0;
                for (auto [a, b, d] : res) {
                    cnt += d;
                }
                if (cnt == 0) return res;
                // add res size-D times
                edges2 = edges;
                for (auto [a, b, d] : res) {
                    for (int j = 0; j < size - D; ++j) {
                        edges2.emplace_back(a, b, d);
                    }
                }
            }
        }
    };

    std::vector<std::tuple<int, int, bool>> edges2;
    for (auto [a, b] : edges) {
        edges2.emplace_back(a, b, false);
    }
    auto res = rec(rec, edges2, D);
    std::vector<std::pair<int, int>> ret;
    for (auto [a, b, d] : res) {
        ret.emplace_back(a, b);
    }
    return ret;
}
