#pragma once
#include <algorithm>
#include <bit>
#include <numeric>
#include <vector>

template <typename M, typename O,
          typename M::T (*act)(typename M::T, typename O::T)>
class LazySegmentTree {
    using T = M::T;
    using E = O::T;

   public:
    LazySegmentTree() = default;
    explicit LazySegmentTree(int n)
        : LazySegmentTree(std::vector<T>(n, M::id())) {}
    explicit LazySegmentTree(const std::vector<T>& v)
        : size(std::bit_ceil(v.size())),
          node(2 * size, M::id()),
          lazy(2 * size, O::id()) {
        std::ranges::copy(v, node.begin() + size);
        for (int i = size - 1; i > 0; --i) {
            node[i] = M::op(node[2 * i], node[2 * i + 1]);
        }
    }

    T operator[](int k) { return fold(k, k + 1); }

    void update(int l, int r, const E& x) { update(l, r, x, 1, 0, size); }

    T fold(int l, int r) { return fold(l, r, 1, 0, size); }

    T fold_all() {
        push(1);
        return node[1];
    }

    template <typename F>
    int find_first(int l, F cond) {
        T v = M::id();
        return find_first(l, size, 1, 0, size, v, cond);
    }

    template <typename F>
    int find_last(int r, F cond) {
        T v = M::id();
        return find_last(0, r, 1, 0, size, v, cond);
    }

   private:
    int size;
    std::vector<T> node;
    std::vector<E> lazy;

    void push(int k) {
        if (lazy[k] == O::id()) return;
        if (k < size) {
            lazy[2 * k] = O::op(lazy[2 * k], lazy[k]);
            lazy[2 * k + 1] = O::op(lazy[2 * k + 1], lazy[k]);
        }
        node[k] = act(node[k], lazy[k]);
        lazy[k] = O::id();
    }

    void update(int a, int b, const E& x, int k, int l, int r) {
        push(k);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] = O::op(lazy[k], x);
            push(k);
            return;
        }
        int m = std::midpoint(l, r);
        update(a, b, x, 2 * k, l, m);
        update(a, b, x, 2 * k + 1, m, r);
        node[k] = M::op(node[2 * k], node[2 * k + 1]);
    }

    T fold(int a, int b, int k, int l, int r) {
        push(k);
        if (r <= a || b <= l) return M::id();
        if (a <= l && r <= b) return node[k];
        int m = std::midpoint(l, r);
        return M::op(fold(a, b, 2 * k, l, m), fold(a, b, 2 * k + 1, m, r));
    }

    template <typename F>
    int find_first(int a, int b, int k, int l, int r, T& v, F cond) {
        push(k);
        if (r <= a) return -1;
        if (b <= l) return l;
        if (a <= l && r <= b && !cond(M::op(v, node[k]))) {
            v = M::op(v, node[k]);
            return -1;
        }
        if (r - l == 1) return r;
        int m = std::midpoint(l, r);
        int res = find_first(a, b, 2 * k, l, m, v, cond);
        if (res != -1) return res;
        return find_first(a, b, 2 * k + 1, m, r, v, cond);
    }

    template <typename F>
    int find_last(int a, int b, int k, int l, int r, T& v, F cond) {
        push(k);
        if (b <= l) return -1;
        if (r <= a) return r;
        if (a <= l && r <= b && !cond(M::op(node[k], v))) {
            v = M::op(node[k], v);
            return -1;
        }
        if (r - l == 1) return l;
        int m = std::midpoint(l, r);
        int res = find_last(a, b, 2 * k + 1, m, r, v, cond);
        if (res != -1) return res;
        return find_last(a, b, 2 * k, l, m, v, cond);
    }
};