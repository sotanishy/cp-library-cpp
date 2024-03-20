#pragma once
#include <algorithm>
#include <vector>

#include "../data-structure/segtree/lazy_segment_tree.hpp"

struct CountMinMonoid {
    using T = std::pair<int, int>;  // min, count
    static T id() { return {(1u << 31) - 1, 0}; }
    static T op(T a, T b) {
        if (a.first < b.first) return a;
        if (a.first > b.first) return b;
        return {a.first, a.second + b.second};
    }
};

struct AddMonoid {
    using T = int;
    static T id() { return 0; }
    static T op(T a, T b) { return a + b; }
};

CountMinMonoid::T act(CountMinMonoid::T a, AddMonoid::T b) {
    return {a.first + b, a.second};
}

// rectangles are given in the form (l, d, r, u)
long long area_of_union_of_rectangles(
    const std::vector<std::tuple<long long, long long, long long, long long>>&
        rects) {
    std::vector<long long> xs, ys;
    for (auto [l, d, r, u] : rects) {
        xs.push_back(l);
        xs.push_back(r);
        ys.push_back(d);
        ys.push_back(u);
    }
    std::ranges::sort(xs);
    xs.erase(std::ranges::unique(xs).begin(), xs.end());
    std::ranges::sort(ys);
    ys.erase(std::ranges::unique(ys).begin(), ys.end());

    std::vector<std::vector<std::tuple<long long, long long, int>>> update(
        ys.size());
    for (auto [l, d, r, u] : rects) {
        int cl = std::ranges::lower_bound(xs, l) - xs.begin();
        int cd = std::ranges::lower_bound(ys, d) - ys.begin();
        int cr = std::ranges::lower_bound(xs, r) - xs.begin();
        int cu = std::ranges::lower_bound(ys, u) - ys.begin();
        update[cd].push_back({cl, cr, 1});
        update[cu].push_back({cl, cr, -1});
    }

    std::vector<std::pair<int, int>> init(xs.size() - 1);
    for (int x = 0; x < (int)xs.size() - 1; ++x) {
        init[x] = {0, xs[x + 1] - xs[x]};
    }

    LazySegmentTree<CountMinMonoid, AddMonoid, act> st(init);
    long long ans = 0;
    long long xlen = xs.back() - xs[0];
    for (int y = 0; y < (int)ys.size() - 1; ++y) {
        for (auto [l, r, diff] : update[y]) {
            st.update(l, r, diff);
        }
        auto [minval, len0] = st.fold_all();
        if (minval > 0) len0 = 0;
        ans += (xlen - len0) * (ys[y + 1] - ys[y]);
    }
    return ans;
}
