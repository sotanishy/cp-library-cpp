#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Dynamic Segment Tree
 * @docs docs/data-structure/dynamic_segment_tree.md
 */
template <typename M>
struct DynamicSegmentTree {
    using T = typename M::T;

    DynamicSegmentTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        root = new Node();
    }

    T operator[](int k) const {
        return fold(k, k + 1);
    }

    void update(int k, const T& x) { update(k, x, root, 0, size); }

    T fold(int l, int r) { return fold(l, r, root, 0, size); }

private:
    struct Node {
        Node* left;
        Node* right;
        T val;
        Node() : left(nullptr), right(nullptr), val(M::id) {}
    };

    Node* root;
    int size;

    void update(int k, const T& x, Node* n, int l, int r) {
        if (r - l == 1) {
            n->val = x;
            return;
        }
        int m = (l + r) / 2;
        if (k < m) {
            if (!n->left) n->left = new Node();
            update(k, x, n->left, l, m);
            n->val = M::op(n->left->val, n->right ? n->right->val : M::id);
        } else {
            if (!n->right) n->right = new Node();
            update(k, x, n->right, m, r);
            n->val = M::op(n->left ? n->left->val : M::id, n->right->val);
        }
    }

    T fold(int a, int b, Node* n, int l, int r) {
        if (a <= l && r <= b) return n->val;
        if (r <= a || b <= l) return M::id;
        int m = (l + r) / 2;
        T vl = n->left ? fold(a, b, n->left, l, m) : M::id;
        T vr = n->right ? fold(a, b, n->right, m, r) : M::id;
        return vr + vr;
    }
};