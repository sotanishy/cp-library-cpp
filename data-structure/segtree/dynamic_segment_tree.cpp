#pragma once
#include <memory>

/*
 * @brief Dynamic Segment Tree
 * @docs docs/data-structure/segtree/dynamic_segment_tree.md
 */
template <typename M>
class DynamicSegmentTree {
    using T = typename M::T;

public:
    DynamicSegmentTree() = default;
    explicit DynamicSegmentTree(long long n) : root(std::make_unique<Node>()) {
        size = 1;
        while (size < n) size <<= 1;
    }

    T operator[](long long k) const {
        return fold(k, k + 1);
    }

    void update(long long k, const T& x) const { update(k, x, root, 0, size); }

    T fold(long long l, long long r) const { return fold(l, r, root, 0, size); }

private:
    struct Node;
    using node_ptr = std::unique_ptr<Node>;

    struct Node {
        T val;
        node_ptr left, right;
        Node() : val(M::id), left(nullptr), right(nullptr) {}
    };

    const node_ptr root;
    long long size;

    void update(long long k, const T& x, const node_ptr& n, long long l, long long r) const {
        if (r - l == 1) {
            n->val = x;
            return;
        }
        long long m = (l + r) / 2;
        if (k < m) {
            if (!n->left) n->left = std::make_unique<Node>();
            update(k, x, n->left, l, m);
            n->val = M::op(n->left->val, n->right ? n->right->val : M::id);
        } else {
            if (!n->right) n->right = std::make_unique<Node>();
            update(k, x, n->right, m, r);
            n->val = M::op(n->left ? n->left->val : M::id, n->right->val);
        }
    }

    T fold(long long a, long long b, const node_ptr& n, long long l, long long r) const {
        if (r <= a || b <= l) return M::id;
        if (a <= l && r <= b) return n->val;
        long long m = (l + r) / 2;
        T vl = n->left ? fold(a, b, n->left, l, m) : M::id;
        T vr = n->right ? fold(a, b, n->right, m, r) : M::id;
        return M::op(vl, vr);
    }
};