#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Dual Segment Tree
 * @docs docs/data-structure/dual_segment_tree.md
 */
template <typename M>
class DualSegmentTree {
    using T = typename M::T;

public:
    explicit DualSegmentTree(int n) {
        size = 1;
        height = 1;
        while (size < n) size <<= 1, height++;
        lazy.resize(2 * size, M::id);
    }

    T operator[](int k) {
        k += size;
        propagate(k);
        return lazy[k];
    }

    void update(int l, int r, const T& x) {
        l += size;
        r += size;
        propagate(l);
        propagate(r - 1);
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lazy[l] = M::op(lazy[l], x), l++;
            if (r & 1) --r, lazy[r] = M::op(lazy[r], x);
        }
    }

private:
    int size, height;
    vector<T> lazy;

    void push(int k) {
        if (lazy[k] == M::id) return;
        lazy[2 * k] = M::op(lazy[2 * k], lazy[k]);
        lazy[2 * k + 1] = M::op(lazy[2 * k + 1], lazy[k]);
        lazy[k] = M::id;
    }

    void propagate(int k) {
        for (int i = height; i > 0; i--) push(k >> i);
    }
};