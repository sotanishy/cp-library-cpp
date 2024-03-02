#pragma once
#include <algorithm>
#include <bit>
#include <cassert>
#include <utility>
#include <vector>

#include "dual_segment_tree.hpp"

/**
 * @brief 2D Dual Segment Tree
 */
template <typename X, typename Y, typename M>
class DualSegmentTree2D {
    using T = M::T;

   public:
    DualSegmentTree2D() = default;
    explicit DualSegmentTree2D(const std::vector<std::pair<X, Y>>& pts) {
        for (auto& [x, y] : pts) {
            xs.push_back(x);
        }
        std::ranges::sort(xs);
        xs.erase(std::ranges::unique(xs).begin(), xs.end());

        const int n = xs.size();
        size = std::bit_ceil((unsigned int)n);
        ys.resize(2 * size);
        seg.resize(2 * size);

        for (auto& [x, y] : pts) {
            ys[size + getx(x)].push_back(y);
        }

        for (int i = size + n - 1; i > 0; --i) {
            if (i >= size) {
                std::ranges::sort(ys[i]);
            } else {
                std::ranges::merge(ys[2 * i], ys[2 * i + 1],
                                   std::back_inserter(ys[i]));
            }
            ys[i].erase(std::ranges::unique(ys[i]).begin(), ys[i].end());
        }
        for (int i = 1; i < size + n; ++i) {
            seg[i] = DualSegmentTree<M>(ys[i].size());
        }
    }

    T get(X x, Y y) {
        int kx = getx(x);
        assert(kx < (int)xs.size() && xs[kx] == x);
        T ret = M::id();
        for (kx += size; kx > 0; kx >>= 1) {
            int ky = gety(kx, y);
            assert(ky < (int)ys[kx].size() && ys[kx][ky] == y);
            ret = M::op(ret, seg[kx][ky]);
        }
        return ret;
    }

    void update(X sx, X tx, Y sy, Y ty, T val) {
        for (int l = size + getx(sx), r = size + getx(tx); l < r;
             l >>= 1, r >>= 1) {
            if (l & 1) {
                seg[l].update(gety(l, sy), gety(l, ty), val);
                ++l;
            }
            if (r & 1) {
                --r;
                seg[r].update(gety(r, sy), gety(r, ty), val);
            }
        }
    }

   private:
    int size;
    std::vector<X> xs;
    std::vector<std::vector<Y>> ys;
    std::vector<DualSegmentTree<M>> seg;

    int getx(X x) const { return std::ranges::lower_bound(xs, x) - xs.begin(); }
    int gety(int k, Y y) const {
        return std::ranges::lower_bound(ys[k], y) - ys[k].begin();
    }
};
