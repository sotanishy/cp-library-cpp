#include <bits/stdc++.h>

/*
 * @brief Segment Tree with Lazy Propagation
 * @docs docs/data-structure/segtree/lazy_segment_tree.md
 */
template <typename M, typename O, typename M::T (*act)(typename M::T, typename O::T)>
class LazySegmentTree {
    using T = typename M::T;
    using E = typename O::T;

public:
    LazySegmentTree() = default;
    explicit LazySegmentTree(int n) : LazySegmentTree(std::vector<T>(n, M::id)) {}
    explicit LazySegmentTree(const std::vector<T>& v) {
        size = 1;
        height = 0;
        while (size < (int) v.size()) size <<= 1, ++height;
        node.resize(2 * size, M::id);
        lazy.resize(2 * size, O::id);
        std::copy(v.begin(), v.end(), node.begin() + size);
        for (int i = size - 1; i > 0; --i) node[i] = M::op(node[2 * i], node[2 * i + 1]);
    }

    T operator[](int k) {
        return fold(k, k + 1);
    }

    void update(int l, int r, const E& x) { update(l, r, x, 1, 0, size); }

    T fold(int l, int r) { return fold(l, r, 1, 0, size); }

private:
    int size, height;
    std::vector<T> node;
    std::vector<E> lazy;

    void push(int k) {
        if (lazy[k] == O::id) return;
        if (k < size) {
            lazy[2 * k] = O::op(lazy[2 * k], lazy[k]);
            lazy[2 * k + 1] = O::op(lazy[2 * k + 1], lazy[k]);
        }
        node[k] = act(node[k], lazy[k]);
        lazy[k] = O::id;
    }

    void update(int a, int b, const E& x, int k, int l, int r) {
        push(k);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] = O::op(lazy[k], x);
            push(k);
            return;
        }
        int m = (l + r) / 2;
        update(a, b, x, 2 * k, l, m);
        update(a, b, x, 2 * k + 1, m, r);
        node[k] = M::op(node[2 * k], node[2 * k + 1]);
    }

    T fold(int a, int b, int k, int l, int r) {
        push(k);
        if (r <= a || b <= l) return M::id;
        if (a <= l && r <= b) return node[k];
        int m = (l + r) / 2;
        return M::op(fold(a, b, 2 * k, l, m),
                     fold(a, b, 2 * k + 1, m, r));
    }
};