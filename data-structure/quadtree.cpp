#pragma once
#include <memory>
#include <vector>

/*
 * @brief Quadtree
 * @docs docs/data-structure/quadtree.md
 */
template <typename M>
class Quadtree {
    using T = typename M::T;

public:
    Quadtree() = default;
    Quadtree(int n) : root(std::make_unique<Node>()) {
        size = 1;
        while (size < n) size <<= 1;
    }

    T get(int x, int y) const { return fold(x, x + 1, y, y + 1); }

    void update(int x, int y, const T& val) const { update(x, y, val, root, 0, 0, size); }

    T fold(int l, int r, int b, int t) const { return fold(l, r, b, t, root, 0, 0, size); }

private:
    struct Node;
    using node_ptr = std::unique_ptr<Node>;

    struct Node {
        T val;
        node_ptr ch[4];
        Node() : val(M::id) {}
    };

    const node_ptr root;
    int size;

    void update(int x, int y, const T& val, const node_ptr& n, int p, int q, int len) const {
        if (len == 1) {
            n->val = val;
            return;
        }
        len /= 2;
        for (int i = 3; i >= 0; --i) {
            if (x >= p + len * (i >> 1) && y >= q + len * (i & 1)) {
                if (!n->ch[i]) n->ch[i] = std::make_unique<Node>();
                update(x, y, val, n->ch[i], p + len * (i >> 1), q + len * (i & 1), len);
                break;
            }
        }
        n->val = M::id;
        for (int i = 0; i < 4; ++i) {
            if (n->ch[i]) n->val = M::op(n->val, n->ch[i]->val);
        }
    }

    T fold(int l, int r, int b, int t, const node_ptr& n, int p, int q, int len) const {
        if (!n) return M::id;
        if (p + len <= l || r <= p || q + len <= b || t <= q) {
            return M::id;
        }
        if (l <= p && p + len <= r && b <= q && q + len <= t) {
            return n->val;
        }
        len /= 2;
        T val = M::id;
        for (int i = 0; i < 4; ++i) {
            if (n->ch[i]) val = M::op(val, fold(l, r, b, t, n->ch[i], p + len * (i >> 1), q + len * (i & 1), len));
        }
        return val;
    }
};