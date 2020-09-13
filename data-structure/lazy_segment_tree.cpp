#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Segment Tree with Lazy Propagation
 * @docs docs/data-structure/lazy_segment_tree.md
 */
template <typename S>
struct LazySegmentTree {
    using V = typename S::V;
    using T = typename V::T;
    using O = typename S::O;
    using E = typename O::E;

    LazySegmentTree(size_t n) : LazySegmentTree(vector<T>(n, V::id)) {}
    LazySegmentTree(const vector<T>& v) {
        size = 1;
        height = 0;
        while (size < v.size()) size <<= 1, height++;
        node.resize(2 * size, V::id);
        lazy.resize(2 * size, O::id);
        copy(v.begin(), v.end(), node.begin() + size);
        for (size_t i = size - 1; i > 0; i--) node[i] = V::op(node[2 * i], node[2 * i + 1]);
    }

    T operator[](size_t k) {
        return fold(k, k + 1);
    }

    void update(size_t l, size_t r, const E& x) { update(l, r, x, 1, 0, size); }

    T fold(size_t l, size_t r) { return fold(l, r, 1, 0, size); }

private:
    size_t size, height;
    vector<T> node;
    vector<E> lazy;

    void push(size_t k, size_t len) {
        if (lazy[k] == O::id) return;
        if (k < size) {
            lazy[2 * k] = O::op(lazy[2 * k], lazy[k]);
            lazy[2 * k + 1] = O::op(lazy[2 * k + 1], lazy[k]);
        }
        node[k] = S::op(node[k], S::mul(lazy[k], len));
        lazy[k] = O::id;
    }

    void update(size_t a, size_t b, const E& x, size_t k, size_t l, size_t r) {
        push(k, r - l);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] = O::op(lazy[k], x);
            push(k, r - l);
            return;
        }
        size_t m = (l + r) / 2;
        update(a, b, x, 2 * k, l, m);
        update(a, b, x, 2 * k + 1, m, r);
        node[k] = V::op(node[2 * k], node[2 * k + 1]);
    }

    T fold(size_t a, size_t b, size_t k, int l, int r) {
        push(k, r - l);
        if (r <= a || b <= l) return V::id;
        if (a <= l && r <= b) return node[k];
        int m = (l + r) / 2;
        return V::op(fold(a, b, 2 * k, l, m),
                     fold(a, b, 2 * k + 1, m, r));
    }
};

// struct S {
//     struct V {
//         using T = ll;
//         inline static const T id = 0;
//         static T op(T a, T b) {
//             return a + b;
//         }
//     };

//     struct O {
//         using E = ll;
//         inline static const E id = 0;
//         static E op(E a, E b) {
//             return a + b;
//         }
//     };

//     static V::T op(V::T a, O::E b) {
//         return a + b;
//     }

//     static O::E mul(O::E a, size_t b) {
//         return a * b;
//     }
// };