#pragma once
#include <algorithm>
#include <limits>
#include <vector>

#include "../data-structure/segtree/segment_tree.hpp"
#include "../graph/mst.hpp"

template <typename U>
struct MinMonoid {
    using T = std::pair<U, int>;
    static T id() { return {std::numeric_limits<U>::max(), -1}; }
    static T op(T a, T b) { return std::min(a, b); }
};

template <typename T>
std::pair<T, std::vector<std::pair<int, int>>> manhattan_mst(
    std::vector<std::pair<T, T>> pts) {
    std::vector<int> idx(pts.size());
    std::iota(idx.begin(), idx.end(), 0);

    std::vector<std::tuple<int, int, T>> edges;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                // sort by y-x asc then by y desc
                std::ranges::sort(idx, {}, [&](int i) {
                    auto [x, y] = pts[i];
                    return std::make_tuple(y - x, -y, i);
                });

                // compress y
                std::vector<T> cs;
                cs.reserve(pts.size());
                for (auto [x, y] : pts) cs.push_back(y);
                std::ranges::sort(cs);
                cs.erase(std::ranges::unique(cs).begin(), cs.end());

                // sweep
                SegmentTree<MinMonoid<T>> st(cs.size());

                for (int i : idx) {
                    auto [x, y] = pts[i];
                    int k = std::ranges::lower_bound(cs, y) - cs.begin();
                    auto [d, j] = st.fold(k, cs.size());
                    if (j != -1) {
                        edges.push_back({i, j, d - (x + y)});
                    }
                    st.update(k, {x + y, i});
                }

                for (auto& p : pts) std::swap(p.first, p.second);
            }
            for (auto& p : pts) p.first *= -1;
        }
        for (auto& p : pts) p.second *= -1;
    }

    auto [weight, mst_edges] = kruskal(edges, pts.size());
    std::vector<std::pair<int, int>> ret(mst_edges.size());
    std::ranges::transform(mst_edges, ret.begin(), [&](const auto& e) {
        return std::make_pair(std::get<0>(e), std::get<1>(e));
    });
    return {weight, ret};
}