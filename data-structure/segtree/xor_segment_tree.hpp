#pragma once
#include <algorithm>
#include <bit>
#include <vector>

template <typename M>
class XorSegmentTree {
    using T = M::T;

   public:
    XorSegmentTree() = default;
    explicit XorSegmentTree(int n)
        : XorSegmentTree(std::vector<T>(n, M::id())) {}
    explicit XorSegmentTree(const std::vector<T>& v)
        : size(std::bit_ceil(v.size())),
          n(std::bit_width(size) - 1),
          table(2 * size),
          half(1 << ((n + 1) / 2)) {
        for (int k = 0; k < size; ++k) {
            table[size + k].resize(1, k < (int)v.size() ? v[k] : M::id());
        }
        for (int k = size - 1; k >= half; --k) pull(k);
    }

    void update(int k, const T& x) {
        k += size;
        table[k][0] = x;
        for (k >>= 1; k >= half; k >>= 1) pull(k);
    }

    T fold(int l, int r, int x) const {
        T vl = M::id(), vr = M::id();
        int i = 0;
        for (l += size, r += size; l < r && l > 2 * half;
             l >>= 1, r >>= 1, ++i) {
            if (l & 1) {
                vl = M::op(vl, table[l++ ^ (x >> i)][x & ((1 << i) - 1)]);
            }
            if (r & 1) {
                vr = M::op(table[--r ^ (x >> i)][x & ((1 << i) - 1)], vr);
            }
        }
        for (int k = l; k < r; ++k) {
            vl = M::op(vl, table[k ^ (x >> i)][x & ((1 << i) - 1)]);
        }
        return M::op(vl, vr);
    }

   private:
    int n, size, half;
    std::vector<std::vector<T>> table;

    void pull(int k) {
        int i = n - std::bit_width(k) + 1;
        table[k].resize(1 << i);
        for (int x = 0; x < (1 << i); ++x) {
            T vl = table[2 * k][x & ~(1 << (i - 1))];
            T vr = table[2 * k + 1][x & ~(1 << (i - 1))];
            if (x >> (i - 1) & 1) std::swap(vl, vr);
            table[k][x] = M::op(vl, vr);
        }
    }
};

template <typename M>
class XorSegmentTreeCommutative {
    using T = M::T;

   public:
    XorSegmentTreeCommutative() = default;
    explicit XorSegmentTreeCommutative(int n)
        : XorSegmentTreeCommutative(std::vector<T>(n, M::id())) {}
    explicit XorSegmentTreeCommutative(const std::vector<T>& v)
        : size(std::bit_ceil(v.size())), node(2 * size, M::id()) {
        std::ranges::copy(v, node.begin() + size);

        for (int k = size - 1; k > 0; --k) {
            node[k] = M::op(node[2 * k], node[2 * k + 1]);
        }
    }

    void update(int k, const T& x) {
        k += size;
        node[k] = x;
        while (k >>= 1) node[k] = M::op(node[2 * k], node[2 * k + 1]);
    }

    T fold(int l, int r, int x) const {
        T res = M::id();
        for (l += size, r += size; l < r; l >>= 1, r >>= 1, x >>= 1) {
            if (l & 1) res = M::op(res, node[l++ ^ x]);
            if (r & 1) res = M::op(node[--r ^ x], res);
        }
        return res;
    }

   private:
    int size;
    std::vector<T> node;
};