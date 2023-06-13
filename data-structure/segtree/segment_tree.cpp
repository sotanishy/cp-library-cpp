#pragma once
#include <algorithm>
#include <vector>

template <typename M>
class SegmentTree {
    using T = typename M::T;

   public:
    SegmentTree() = default;
    explicit SegmentTree(int n) : SegmentTree(std::vector<T>(n, M::id())) {}
    explicit SegmentTree(const std::vector<T>& v) {
        size = 1;
        while (size < (int)v.size()) size <<= 1;
        node.resize(2 * size, M::id());
        std::copy(v.begin(), v.end(), node.begin() + size);
        for (int i = size - 1; i > 0; --i)
            node[i] = M::op(node[2 * i], node[2 * i + 1]);
    }

    T operator[](int k) const { return node[k + size]; }

    void update(int k, const T& x) {
        k += size;
        node[k] = x;
        while (k >>= 1) node[k] = M::op(node[2 * k], node[2 * k + 1]);
    }

    T fold(int l, int r) const {
        T vl = M::id(), vr = M::id();
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = M::op(vl, node[l++]);
            if (r & 1) vr = M::op(node[--r], vr);
        }
        return M::op(vl, vr);
    }

    template <typename F>
    int find_first(int l, F cond) const {
        T v = M::id();
        for (l += size; l > 0; l >>= 1) {
            if (l & 1) {
                T nv = M::op(v, node[l]);
                if (cond(nv)) {
                    while (l < size) {
                        nv = M::op(v, node[2 * l]);
                        if (cond(nv))
                            l = 2 * l;
                        else
                            v = nv, l = 2 * l + 1;
                    }
                    return l + 1 - size;
                }
                v = nv;
                ++l;
            }
        }
        return -1;
    }

    template <typename F>
    int find_last(int r, F cond) const {
        T v = M::id();
        for (r += size; r > 0; r >>= 1) {
            if (r & 1) {
                --r;
                T nv = M::op(node[r], v);
                if (cond(nv)) {
                    while (r < size) {
                        nv = M::op(node[2 * r + 1], v);
                        if (cond(nv))
                            r = 2 * r + 1;
                        else
                            v = nv, r = 2 * r;
                    }
                    return r - size;
                }
                v = nv;
            }
        }
        return -1;
    }

   private:
    int size;
    std::vector<T> node;
};