#include <bits/stdc++.h>

/*
 * @brief Dynamic Segment Tree
 * @docs docs/data-structure/dynamic_segment_tree.md
 */
template <typename M>
class DynamicSegmentTree {
    using T = typename M::T;

public:
    DynamicSegmentTree() = default;
    explicit DynamicSegmentTree(int n) : root(std::make_unique<Node>()) {
        size = 1;
        while (size < n) size <<= 1;
    }

    T operator[](int k) const {
        return fold(k, k + 1);
    }

    void update(int k, const T& x) const { update(k, x, root, 0, size); }

    T fold(int l, int r) const { return fold(l, r, root, 0, size); }

private:
    struct Node {
        std::unique_ptr<Node> left, right;
        T val;
        Node() : left(nullptr), right(nullptr), val(M::id) {}
    };

    std::unique_ptr<Node> const root;
    int size;

    void update(int k, const T& x, std::unique_ptr<Node> const& n, int l, int r) const {
        if (r - l == 1) {
            n->val = x;
            return;
        }
        int m = (l + r) / 2;
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

    T fold(int a, int b, std::unique_ptr<Node> const& n, int l, int r) const {
        if (r <= a || b <= l) return M::id;
        if (a <= l && r <= b) return n->val;
        int m = (l + r) / 2;
        T vl = n->left ? fold(a, b, n->left, l, m) : M::id;
        T vr = n->right ? fold(a, b, n->right, m, r) : M::id;
        return vl + vr;
    }
};