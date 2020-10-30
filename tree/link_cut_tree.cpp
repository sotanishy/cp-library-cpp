#pragma once
#include <algorithm>
#include <memory>
#include <vector>

/*
 * @brief Link/Cut Tree
 * @docs docs/tree/link_cut_tree.md
 */
template <typename M, typename M::T (*flip)(typename M::T)>
class LinkCutTree {
    using T = typename M::T;

public:
    LinkCutTree() = default;
    explicit LinkCutTree(int n) {
        for (int i = 0; i < n; ++i) {
            vertex.push_back(std::make_shared<Node>(M::id));
        }
    }

    void link(int v, int p) {
        evert(v);
        expose(vertex[p]);
        vertex[v]->par = vertex[p];
        vertex[p]->right = vertex[v];
        recalc(vertex[p]);
    }

    void cut(int v) {
        expose(vertex[v]);
        auto p = vertex[v]->left;
        vertex[v]->left = p->par = nullptr;
        recalc(vertex[v]);
    }

    void evert(int v) {
        expose(vertex[v]);
        reverse(vertex[v]);
    }

    T get(int v) const {
        return vertex[v]->val;
    }

    void set(int v, const T& x) {
        expose(vertex[v]);
        vertex[v]->val = x;
        recalc(vertex[v]);
    }

    T fold(int u, int v) {
        evert(u);
        expose(vertex[v]);
        return vertex[v]->sum;
    }

private:
    struct Node;
    using node_ptr = std::shared_ptr<Node>;

    struct Node {
        node_ptr left, right, par;
        T val, sum;
        int sz;
        bool rev;

        Node(const T& x)
            : left(nullptr), right(nullptr), par(nullptr),
              val(x), sum(x), sz(1), rev(false) {}
    };

    std::vector<node_ptr> vertex;

    static void expose(node_ptr v) {
        node_ptr prev = nullptr;
        for (auto cur = v; cur; cur = cur->par) {
            splay(cur);
            cur->right = prev;
            recalc(cur);
            prev = cur;
        }
        splay(v);
    }

    // splay tree

    static int size(const node_ptr& t) {
        return t ? t->sz : 0;
    }

    static void recalc(const node_ptr& t) {
        if (!t) return;
        t->sz = size(t->left) + 1 + size(t->right);
        t->sum = t->val;
        if (t->left) t->sum = M::op(t->left->sum, t->sum);
        if (t->right) t->sum = M::op(t->sum, t->right->sum);
    }

    static void push(const node_ptr& t) {
        if (t->rev) {
            if (t->left) reverse(t->left);
            if (t->right) reverse(t->right);
            t->rev = false;
        }
    }

    static void reverse(const node_ptr& t) {
        std::swap(t->left, t->right);
        t->sum = flip(t->sum);
        t->rev ^= true;
    }

    static void rotate_left(node_ptr t) {
        node_ptr s = t->right;
        t->right = s->left;
        if (s->left) s->left->par = t;
        s->par = t->par;
        if (t->par) {
            if (t->par->left == t) {
                t->par->left = s;
            }
            if (t->par->right == t) {
                t->par->right = s;
            }
        }
        s->left = t;
        t->par = s;
        recalc(t);
        recalc(s);
    }

    static void rotate_right(node_ptr t) {
        node_ptr s = t->left;
        t->left = s->right;
        if (s->right) s->right->par = t;
        s->par = t->par;
        if (t->par) {
            if (t->par->left == t) {
                t->par->left = s;
            }
            if (t->par->right == t) {
                t->par->right = s;
            }
        }
        s->right = t;
        t->par = s;
        recalc(t);
        recalc(s);
    }

    static bool is_root(const node_ptr& t) {
        return !t->par || (t->par->left != t && t->par->right != t);
    }

    static void splay(node_ptr t) {
        push(t);
        while (!is_root(t)) {
            auto p = t->par;
            if (is_root(p)) {
                push(p);
                push(t);
                if (t == p->left) rotate_right(p);
                else rotate_left(p);
            } else {
                auto g = p->par;
                push(g);
                push(p);
                push(t);
                if (t == p->left) {
                    if (p == g->left) {
                        rotate_right(g);
                        rotate_right(p);
                    } else {
                        rotate_right(p);
                        rotate_left(g);
                    }
                } else {
                    if (p == g->left) {
                        rotate_left(p);
                        rotate_right(g);
                    } else {
                        rotate_left(g);
                        rotate_left(p);
                    }
                }
            }
        }
    }
};
