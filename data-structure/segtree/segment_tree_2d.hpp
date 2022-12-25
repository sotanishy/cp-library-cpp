#pragma once
#include <algorithm>
#include <utility>
#include <vector>
#include "segment_tree.cpp"

template <typename X, typename Y, typename M>
class SegmentTree2D {
    using T = typename M::T;

public:
    SegmentTree2D() = default;
    explicit SegmentTree2D(const std::vector<std::pair<X, Y>>& pts) {
        for (auto& [x, y] : pts) {
            xs.push_back(x);
        }
        std::sort(xs.begin(), xs.end());
        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());

        const int n = xs.size();
        size = 1;
        while (size < n) size <<= 1;
        ys.resize(2 * size);
        seg.resize(2 * size);

        for (auto& [x, y] : pts) {
            ys[size + getx(x)].push_back(y);
        }

        for (int i = 0; i < n; ++i) {
            std::sort(ys[size + i].begin(), ys[size + i].end());
            ys[size + i].erase(std::unique(ys[size + i].begin(), ys[size + i].end()), ys[size + i].end());
        }
        for (int i = size - 1; i > 0; --i) {
            std::merge(ys[2*i].begin(), ys[2*i].end(), ys[2*i+1].begin(), ys[2*i+1].end(), std::back_inserter(ys[i]));
            ys[i].erase(std::unique(ys[i].begin(), ys[i].end()), ys[i].end());
        }
        for (int i = 0; i < size + n; ++i) {
            seg[i] = SegmentTree<M>(ys[i].size());
        }
    }

    T get(X x, Y y) const {
        int kx = getx(x);
        assert(kx < (int) xs.size() && xs[kx] == x);
        kx += size;
        int ky = gety(kx, y);
        assert(ky < (int) ys[kx].size() && ys[kx][ky] == y);
        return seg[kx][ky];
    }

    void update(X x, Y y, T val) {
        int kx = getx(x);
        assert(kx < (int) xs.size() && xs[kx] == x);
        kx += size;
        int ky = gety(kx, y);
        assert(ky < (int) ys[kx].size() && ys[kx][ky] == y);
        seg[kx].update(ky, val);
        while (kx >>= 1) {
            ky = gety(kx, y);
            int kl = gety(2*kx, y), kr = gety(2*kx+1, y);
            T vl = (kl < (int) ys[2*kx].size() && ys[2*kx][kl] == y ? seg[2*kx][kl] : M::id());
            T vr = (kr < (int) ys[2*kx+1].size() && ys[2*kx+1][kr] == y ? seg[2*kx+1][kr] : M::id());
            seg[kx].update(ky, M::op(vl, vr));
        }
    }

    T fold(X sx, X tx, Y sy, Y ty) const {
        T ret = M::id();
        for (int l = size + getx(sx), r = size + getx(tx); l < r; l >>= 1, r >>= 1) {
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

    int getx(X x) const { return std::lower_bound(xs.begin(), xs.end(), x) - xs.begin(); }
    int gety(int k, Y y) const { return std::lower_bound(ys[k].begin(), ys[k].end(), y) - ys[k].begin(); }
};