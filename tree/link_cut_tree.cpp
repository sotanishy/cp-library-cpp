#include <bits/stdc++.h>

/*
 * @brief Link/Cut Tree
 */
template <typename M>
class LinkCutTree {
    using T = typename M::T;
    struct Node;

public:
    using node_ptr = std::shared_ptr<Node>;

    node_ptr make_node(const T& x) const {
        return std::make_shared<Node>(x);
    }

    void link(node_ptr v, node_ptr p) const {
        make_root(v);
        access(p);
        v->par = p;
        p->right = v;
        update(p);
    }

    void cut(node_ptr v) const {
        access(v);
        auto p = v->left;
        v->left = p->par = nullptr;
        update(v);
    }

    void make_root(node_ptr v) const {
        access(v);
        reverse(v);
        push(v);
    }

    void update(node_ptr v, const T& x) {
        access(v);
        v->val = x;
        update(v);
    }

    T fold(node_ptr u, node_ptr v) {
        make_root(u);
        access(v);
        return v->sum;
    }

private:
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

    void access(node_ptr v) const {
        node_ptr prev = nullptr;
        for (auto cur = v; cur; cur = cur->par) {
            splay(cur);
            cur->right = prev;
            update(cur);
            prev = cur;
        }
        splay(v);
    }

    void update(const node_ptr& t) const {
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

    void push(const node_ptr& t) const {
        if (t->rev) {
            if (t->left) reverse(t->left);
            if (t->right) reverse(t->right);
            t->rev = false;
        }
    }

    void reverse(const node_ptr& t) const {
        std::swap(t->left, t->right);
        t->rev ^= true;
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

    bool is_root(const node_ptr& t) const {
        return !t->par || (t->par->left != t && t->par->right != t);
    }

    void rotate_left(node_ptr t) const {
        auto x = t->par, y = x->par;
        x->right = t->left;
        if (x->right) x->right->par = x;
        t->left = x;
        x->par = t;
        update(x);
        update(t);
        t->par = y;
        if (y) {
            if (y->left == x) y->left = t;
            if (y->right == x) y->right = t;
            update(y);
        }
    }

    void rotate_right(node_ptr t) const {
        auto x = t->par, y = x->par;
        x->left = t->right;
        if (x->left) x->left->par = x;
        t->right = x;
        x->par = t;
        update(x);
        update(t);
        t->par = y;
        if (y) {
            if (y->left == x) y->left = t;
            if (y->right == x) y->right = t;
            update(y);
        }
    }
};