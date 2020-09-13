#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Dual Segment Tree
 * @docs docs/data-structure/dual_segment_tree.md
 */
template <typename M>
struct DualSegmentTree {
    using T = typename M::T;

    DualSegmentTree(size_t n) {
        size = 1;
        height = 1;
        while (size < n) size <<= 1, height++;
        lazy.resize(2 * size, M::id);
    }

    T operator[](size_t k) {
        k += size;
        propagate(k);
        return lazy[k];
    }

    void update(size_t l, size_t r, const T& x) {
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
    size_t size, height;
    vector<T> lazy;

    void push(size_t k) {
        if (lazy[k] == M::id) return;
        lazy[2 * k] = M::op(lazy[2 * k], lazy[k]);
        lazy[2 * k + 1] = M::op(lazy[2 * k + 1], lazy[k]);
        lazy[k] = M::id;
    }

    void propagate(size_t k) {
        for (size_t i = height; i > 0; i--) push(k >> i);
    }
};

// struct M {
//     using T = int;
//     inline static const T id = 0;
//     static T op(T a, T b) {
//         return a + b;
//     }
// };