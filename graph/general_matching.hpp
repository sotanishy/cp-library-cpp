#pragma once
#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

class GeneralMatching {
public:
    GeneralMatching() = default;
    explicit GeneralMatching(int n) : n(n), m(n + n / 2), G(m, std::vector<bool>(m)), mate(m, -1) {}

    void add_edge(int u, int v) {
        G[u][v] = G[v][u] = true;
    }

    std::vector<std::pair<int, int>> max_matching() {
        // par: parent in the alternating forest
        // dep: 0 if even, 1 if odd, -1 if not in the forest
        // comp: id of the comp in the forest
        // alive: whether the blossom/vertex is alive
        // blossom: members of the blossom
        std::vector<int> par(m), dep(m), comp(m);
        std::vector<bool> alive(m, true);
        std::vector<std::vector<int>> blossom(m);

        auto get_ancestors = [&](int v) {
            std::vector<int> ret;
            while (v != -1) {
                ret.push_back(v);
                v = par[v];
            }
            return ret;
        };

        auto flip_to_root = [&](int v) {
            mate[v] = -1;
            int w = par[v];
            while (w != -1) {
                int p = par[w];
                mate[w] = p;
                mate[p] = w;
                w = par[p];
            }
        };

        for (int ans = 0; ; ++ans) {
            std::fill(par.begin(), par.end(), -1);
            std::fill(dep.begin(), dep.end(), -1);
            std::fill(comp.begin(), comp.end(), -1);
            bool augment = false;
            int c = n;  // n + number of blossoms

            // seed
            std::queue<int> que;
            for (int v = 0; v < n; ++v) {
                if (mate[v] == -1) {
                    que.push(v);
                    dep[v] = 0;
                    comp[v] = v;
                }
            }

            // repeat until an augmenting path is found
            while (!que.empty() && !augment) {
                int v = que.front();
                que.pop();
                if (!alive[v]) continue;
                for (int u = 0; u < c; ++u) {
                    if (!G[v][u] || !alive[u] || dep[u] == 1) continue;
                    if (dep[u] == -1) {
                        // grow
                        int w = mate[u];
                        par[u] = v;
                        par[w] = u;
                        dep[u] = 1;
                        dep[w] = 0;
                        comp[u] = comp[w] = comp[v];
                        que.push(w);
                    } else if (comp[v] == comp[u]) {
                        // shrink

                        // build the blossom
                        auto av = get_ancestors(v);
                        auto au = get_ancestors(u);
                        int w;  // lca
                        while (!av.empty() && !au.empty() && av.back() == au.back()) {
                            w = av.back();
                            av.pop_back();
                            au.pop_back();
                        }
                        blossom[c] = std::move(av);
                        blossom[c].push_back(w);
                        std::reverse(blossom[c].begin(), blossom[c].end());
                        std::move(au.begin(), au.end(), std::back_inserter(blossom[c]));

                        // contract
                        if (par[w] != -1) mate[par[w]] = c;
                        par[c] = mate[c] = par[w];
                        dep[c] = 0;
                        comp[c] = comp[w];
                        for (int x : blossom[c]) {
                            alive[x] = false;
                            mate[x] = -1;
                        }
                        for (int x : blossom[c]) {
                            for (int y = 0; y < c; ++y) {
                                if (G[x][y] && alive[y]) {
                                    G[y][c] = G[c][y] = true;
                                    if (par[y] == x) par[y] = c;
                                }
                            }
                        }

                        que.push(c);
                        ++c;
                        break;
                    } else {
                        // augment
                        augment = true;
                        flip_to_root(v);
                        flip_to_root(u);
                        mate[v] = u;
                        mate[u] = v;
                        break;
                    }
                }
            }

            // restore blossoms
            while (c > n) {
                --c;
                int b = blossom[c].size();

                // select the base
                int base_idx;
                if (mate[c] == -1) {
                    base_idx = 0;
                } else {
                    base_idx = -1;
                    for (int i = 0; i < b; ++i) {
                        int x = blossom[c][i];
                        int y = mate[c];
                        if (G[x][y]) {
                            base_idx = i;
                            mate[c] = -1;
                            mate[y] = x;
                            mate[x] = y;
                            break;
                        }
                    }
                    assert(base_idx != -1);
                }

                // restore matches
                for (int i = 1; i < b; i += 2) {
                    int u = blossom[c][(base_idx + i) % b];
                    int v = blossom[c][(base_idx + i + 1) % b];
                    mate[u] = v;
                    mate[v] = u;
                }

                for (int x : blossom[c]) alive[x] = true;
                for (int y = 0; y < c; ++y) G[c][y] = G[y][c] = false;
                blossom[c].clear();
            }

            if (!augment) {
                std::vector<std::pair<int, int>> matches;
                for (int i = 0; i < n; ++i) {
                    if (i < mate[i]) {
                        matches.emplace_back(i, mate[i]);
                    }
                }
                return matches;
            }
        }
    }

private:
    int n, m;  // m: maximum number of vertices + blossoms
    std::vector<std::vector<bool>> G;  // adjacency matrix
    std::vector<int> mate;  // -1 if not matched
};