#pragma once
#include <memory>

/*
 * @brief Dynamic Segment Tree with Lazy Propagation
 */
template <typename M, typename O, typename M::T (*act)(typename M::T, typename O::T)>
class DynamicLazySegmentTree {
    using T = typename M::T;
    using E = typename O::T;

public:
    DynamicLazySegmentTree() = default;
    explicit DynamicLazySegmentTree(long long n) : root(std::make_unique<Node>()) {
        size = 1;
        while (size < n) size <<= 1;
    }

    T operator[](long long k) const {
        return fold(k, k + 1);
    }

    void update(long long l, long long r, const E& x) const { update(l, r, x, root, 0, size); }

    T fold(long long l, long long r) const { return fold(l, r, root, 0, size); }

private:
    struct Node;
    using node_ptr = std::unique_ptr<Node>;

    struct Node {
        T val;
        E lazy;
        std::unique_ptr<Node> left, right;
        Node() : val(M::id), lazy(O::id), left(nullptr), right(nullptr) {}
    };

    const node_ptr root;
    long long size;

    void push(const node_ptr& n) const {
        if (n->lazy == O::id) return;
        if (!n->left) n->left = std::make_unique<Node>();
        n->left->lazy = O::op(n->left->lazy, n->lazy);
        if (!n->right) n->right = std::make_unique<Node>();
        n->right->lazy = O::op(n->right->lazy, n->lazy);
        n->val = act(n->val, n->lazy);
        n->lazy = O::id;
    }

    void update(long long a, long long b, const E& x, const node_ptr& n, long long l, long long r) const {
        push(n);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            n->lazy = O::op(n->lazy, x);
            push(n);
            return;
        }
        long long m = (l + r) / 2;
        if (!n->left) n->left = std::make_unique<Node>();
        update(a, b, x, n->left, l, m);
        if (!n->right) n->right = std::make_unique<Node>();
        update(a, b, x, n->right, m, r);
        n->val = M::op(n->left->val, n->right->val);
    }

    T fold(long long a, long long b, const node_ptr& n, long long l, long long r) const {
        push(n);
        if (r <= a || b <= l) return M::id;
        if (a <= l && r <= b) return n->val;
        long long m = (l + r) / 2;
        T vl = n->left ? fold(a, b, n->left, l, m) : M::id;
        T vr = n->right ? fold(a, b, n->right, m, r) : M::id;
        return M::op(vl, vr);
    }
};