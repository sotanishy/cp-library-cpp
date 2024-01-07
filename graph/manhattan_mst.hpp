#pragma once
#include <algorithm>
#include <limits>
#include <vector>

#include "../data-structure/segtree/segment_tree.hpp"
#include "../graph/edge.cpp"
#include "../graph/mst.cpp"

template <typename U>
struct MinMonoid {
    using T = std::pair<U, int>;
    static T id() { return {std::numeric_limits<U>::max(), -1}; }
    static T op(T a, T b) { return std::min(a, b); }
};

template <typename T>
std::pair<T, std::vector<Edge<T>>> manhattan_mst(
    std::vector<std::pair<T, T>> pts) {
    std::vector<int> idx(pts.size());
    std::iota(idx.begin(), idx.end(), 0);

    std::vector<Edge<T>> edges;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                // sort by y-x asc then by y desc
                std::sort(idx.begin(), idx.end(), [&](auto& i, auto& j) {
                    auto [xi, yi] = pts[i];
                    auto [xj, yj] = pts[j];
                    if (yi - xi != yj - xj) return yi - xi < yj - xj;
                    if (yi != yj) return yi > yj;
                    return i < j;
                });

                // compress y
                std::vector<T> cs;
                cs.reserve(pts.size());
                for (auto [x, y] : pts) cs.push_back(y);
                std::sort(cs.begin(), cs.end());
                cs.erase(std::unique(cs.begin(), cs.end()), cs.end());

                // sweep
                SegmentTree<MinMonoid<T>> st(cs.size());

                for (int i : idx) {
                    auto [x, y] = pts[i];
                    int k =
                        std::lower_bound(cs.begin(), cs.end(), y) - cs.begin();
                    auto [d, j] = st.fold(k, cs.size());
                    if (j != -1) {
                        edges.push_back(Edge<T>(i, j, d - (x + y)));
                    }
                    st.update(k, {x + y, i});
                }

                for (auto& p : pts) std::swap(p.first, p.second);
            }
            for (auto& p : pts) p.first *= -1;
        }
        for (auto& p : pts) p.second *= -1;
    }

    return kruskal(edges, pts.size());
}