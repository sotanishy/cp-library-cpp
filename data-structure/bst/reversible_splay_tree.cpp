#pragma once
#include <algorithm>
#include <memory>

/*
 * @brief (deprecated) Reversible Splay Tree
 */
template <typename M, typename M::T (*flip)(typename M::T)>
class ReversibleSplayTree {
    using T = typename M::T;

protected:
    struct Node;

public:
    using node_ptr = std::shared_ptr<Node>;

    node_ptr make_node(const T& x) const {
        return std::make_shared<Node>(x);
    }

    void reverse(const node_ptr& t) const {
        std::swap(t->left, t->right);
        t->sum = flip(t->sum);
        t->rev ^= true;
    }

protected:
    struct Node {
        node_ptr left, right, par;
        T val, sum;
        int sz;
        bool rev;

        Node() : left(nullptr), right(nullptr), par(nullptr), sz(1), rev(false) {}
        Node(const T& x) : Node() {
            val = sum = x;
        }
    };

    bool is_root(const node_ptr& t) const {
        return !t->par || (t->par->left != t && t->par->right != t);
    }

    void recalc(const node_ptr& t) const {
        t->sz = 1;
        t->sum = t->val;
        if (t->left) {
            t->sz += t->left->sz;
            t->sum = M::op(t->left->sum, t->sum);
        }
        if (t->right) {
            t->sz += t->right->sz;
            t->sum = M::op(t->sum, t->right->sum);
        }
    }

    void rotate_left(node_ptr t) const {
        auto x = t->par, y = x->par;
        x->right = t->left;
        if (x->right) x->right->par = x;
        t->left = x;
        x->par = t;
        recalc(x);
        recalc(t);
        t->par = y;
        if (y) {
            if (y->left == x) y->left = t;
            if (y->right == x) y->right = t;
            recalc(y);
        }
    }

    void rotate_right(node_ptr t) const {
        auto x = t->par, y = x->par;
        x->left = t->right;
        if (x->left) x->left->par = x;
        t->right = x;
        x->par = t;
        recalc(x);
        recalc(t);
        t->par = y;
        if (y) {
            if (y->left == x) y->left = t;
            if (y->right == x) y->right = t;
            recalc(y);
        }
    }

    void push(const node_ptr& t) const {
        if (t->rev) {
            if (t->left) reverse(t->left);
            if (t->right) reverse(t->right);
            t->rev = false;
        }
    }

    void splay(node_ptr t) const {
        push(t);
        while (!is_root(t)) {
            auto x = t->par;
            if (is_root(x)) {
                push(x);
                push(t);
                if (x->left == t) rotate_right(t);
                else rotate_left(t);
            } else {
                auto y = x->par;
                push(y);
                push(x);
                push(t);
                if (y->left == x) {
                    if (x->left == t) {
                        rotate_right(x);
                        rotate_right(t);
                    } else {
                        rotate_left(t);
                        rotate_right(t);
                    }
                } else {
                    if (x->right == t) {
                        rotate_left(x);
                        rotate_left(t);
                    } else {
                        rotate_right(t);
                        rotate_left(t);
                    }
                }
            }
        }
    }
};