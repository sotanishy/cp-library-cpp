#pragma once
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include "../data-structure/fenwick_tree.cpp"
#include "centroid_decomposition.hpp"

template <typename Group>
class RangeContourAggregation {
    using T = typename Group::T;

public:
    RangeContourAggregation() = default;
    explicit RangeContourAggregation(const std::vector<std::vector<int>>& G)
        : seg(G.size()), seg_sub(G.size()), dist(G.size()), idx(G.size()),
          sub(G.size()), idx_sub(G.size()), first(G.size()), first_sub(G.size()) {

        std::tie(level, sz_comp, par) = centroid_decomposition(G);

        for (int v = 0; v < (int) G.size(); ++v) {
            // calculate for each vertex u,
            // dist: dist from v
            // idx: index in the BFS order
            // sub: subtree of v that u belongs to
            // idx_sub: index in the subtree

            // calculate for each depth d,
            // first: first index of depth d
            // first_sub: first index of depth d in the subtree i

            dist[v][v] = 0;
            std::queue<std::pair<int, int>> que;
            que.push({v, -1});
            int k = 0, sub_idx = 0;
            std::vector<int> ks;

            while (!que.empty()) {
                auto [u, i] = que.front();
                que.pop();

                // update component info
                int d = dist[v][u];
                if (d >= (int) first[v].size()) {
                    first[v].push_back(k);
                }
                idx[v][u] = k++;
                // enter subtree
                if (d == 1) {
                    i = sub_idx++;
                    ks.push_back(0);
                    first_sub[v].emplace_back();
                }
                // update subtree info
                if (i != -1) {
                    sub[v][u] = i;
                    if (d-1 >= (int) first_sub[v][i].size()) {
                        first_sub[v][i].push_back(ks[i]);
                    }
                    idx_sub[v][u] = ks[i]++;
                }

                for (int w : G[u]) {
                    if (level[w] > level[v] && !dist[v].count(w)) {
                        dist[v][w] = d + 1;
                        que.push({w, i});
                    }
                }
            }

            first[v].push_back(k);
            seg[v] = FenwickTree<Group>(k);
            for (int i = 0; i < sub_idx; ++i) {
                first_sub[v][i].push_back(ks[i]);
                seg_sub[v].emplace_back(ks[i]);
            }
        }
    }

    void update(int v, T x) {
        seg[v].update(0, x);
        for (int p = par[v]; p != -1; p = par[p]) {
            seg[p].update(idx[p][v], x);
            int i = sub[p][v];
            seg_sub[p][i].update(idx_sub[p][v], x);
        }
    }

    T fold(int v, int d) const {
        int dd = std::min((int) first[v].size() - 1, d);
        T res = seg[v].prefix_fold(first[v][dd]);
        for (int p = par[v]; p != -1; p = par[p]) {
            int dep = d - dist[p].at(v);
            if (dep >= 0) {
                dd = std::min((int) first[p].size() - 1, dep);
                res = Group::op(res, seg[p].prefix_fold(first[p][dd]));
                if (dd > 0) {
                    int i = sub[p].at(v);
                    dd = std::min((int) first_sub[p][i].size() - 1, dep - 1);
                    res = Group::op(res, Group::inv(seg_sub[p][i].prefix_fold(first_sub[p][i][dd])));
                }
            }
        }
        return res;
    }

private:
    std::vector<int> level, sz_comp, par;
    std::vector<FenwickTree<Group>> seg;
    std::vector<std::vector<FenwickTree<Group>>> seg_sub;
    std::vector<std::unordered_map<int, int>> dist, idx, sub, idx_sub;
    std::vector<std::vector<int>> first;
    std::vector<std::vector<std::vector<int>>> first_sub;
};