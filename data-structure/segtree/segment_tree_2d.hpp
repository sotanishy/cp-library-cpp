#pragma once
#include <algorithm>
#include <bit>
#include <cassert>
#include <utility>
#include <vector>

#include "segment_tree.hpp"

template <typename X, typename Y, typename M>
class SegmentTree2D {
    using T = M::T;

   public:
    SegmentTree2D() = default;
    explicit SegmentTree2D(const std::vector<std::pair<X, Y>>& pts) {
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
        for (int i = 0; i < size + n; ++i) {
            seg[i] = SegmentTree<M>(ys[i].size());
        }
    }

    T get(X x, Y y) const {
        int kx = getx(x);
        assert(kx < (int)xs.size() && xs[kx] == x);
        kx += size;
        int ky = gety(kx, y);
        assert(ky < (int)ys[kx].size() && ys[kx][ky] == y);
        return seg[kx][ky];
    }

    void update(X x, Y y, T val) {
        int kx = getx(x);
        assert(kx < (int)xs.size() && xs[kx] == x);
        kx += size;
        int ky = gety(kx, y);
        assert(ky < (int)ys[kx].size() && ys[kx][ky] == y);
        seg[kx].update(ky, val);
        while (kx >>= 1) {
            ky = gety(kx, y);
            int kl = gety(2 * kx, y), kr = gety(2 * kx + 1, y);
            T vl = (kl < (int)ys[2 * kx].size() && ys[2 * kx][kl] == y
                        ? seg[2 * kx][kl]
                        : M::id());
            T vr = (kr < (int)ys[2 * kx + 1].size() && ys[2 * kx + 1][kr] == y
                        ? seg[2 * kx + 1][kr]
                        : M::id());
            seg[kx].update(ky, M::op(vl, vr));
        }
    }

    T fold(X sx, X tx, Y sy, Y ty) const {
        T ret = M::id();
        for (int l = size + getx(sx), r = size + getx(tx); l < r;
             l >>= 1, r >>= 1) {
            if (l & 1) {
                ret = M::op(ret, seg[l].fold(gety(l, sy), gety(l, ty)));
                ++l;
            }
            if (r & 1) {
                --r;
                ret = M::op(ret, seg[r].fold(gety(r, sy), gety(r, ty)));
            }
        }
        return ret;
    }

   private:
    int size;
    std::vector<X> xs;
    std::vector<std::vector<Y>> ys;
    std::vector<SegmentTree<M>> seg;

    int getx(X x) const { return std::ranges::lower_bound(xs, x) - xs.begin(); }
    int gety(int k, Y y) const {
        return std::ranges::lower_bound(ys[k], y) - ys[k].begin();
    }
};