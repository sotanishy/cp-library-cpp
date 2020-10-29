#pragma once
#include <cassert>
#include <memory>
#include <utility>

/*
 * @brief Splay Tree
 * @docs docs/data-structure/bst/splay_tree.md
 */
template <typename M>
class SplayTree {
    using T = typename M::T;

public:
    SplayTree() = default;

    static SplayTree join(SplayTree l, SplayTree r) {
        return SplayTree(join(std::move(l.root), std::move(r.root)));
    }

    std::pair<SplayTree, SplayTree> split(int k) {
        auto p = split(std::move(root), k);
        return {SplayTree(std::move(p.first)), SplayTree(std::move(p.second))};
    }

    void set(int k, const T& x) {
        root = splay(std::move(root), k);
        root->val = x;
        recalc(root);
    }

    T fold(int l, int r) {
        auto a = split(std::move(root), l);
        auto b = split(std::move(a.second), r - l);
        auto ret = b.first ? b.first->sum : M::id;
        root = join(std::move(a.first), join(std::move(b.first), std::move(b.second)));
        return ret;
    }

    void reverse(int l, int r) {
        node_ptr a, b, c;
        std::tie(a, b) = split(std::move(root), l);
        std::tie(b, c) = split(std::move(b), r - l);
        b->rev ^= true;
        root = join(join(std::move(a), std::move(b)), std::move(c));
    }

    void insert(int k, const T& x) {
        auto p = split(std::move(root), k);
        root = join(join(std::move(p.first), std::make_unique<Node>(x)), std::move(p.second));
    }

    void erase(int k) {
        root = splay(std::move(root), k);
        root = join(std::move(root->left), std::move(root->right));
    }

    void push_front(const T& x) {
        root = join(std::make_unique<Node>(x), std::move(root));
    }

    void push_back(const T& x) {
        root = join(std::move(root), std::make_unique<Node>(x));
    }

    void pop_front() {
        root = split(std::move(root), 1).second;
    }

    void pop_back() {
        root = split(std::move(root), size() - 1).first;
    }

    int size() const {
        return size(root);
    }

    bool empty() const {
        return size() == 0;
    }

protected:
    struct Node;
    using node_ptr = std::unique_ptr<Node>;

    struct Node {
        node_ptr left, right;
        T val, sum;
        int sz;
        bool rev;

        Node() : Node(M::id) {}
        Node(const T& x) : left(nullptr), right(nullptr), val(x), sum(x), sz(1), rev(false) {}
    };

    node_ptr root;

    explicit SplayTree(node_ptr root) : root(std::move(root)) {}

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
            std::swap(t->left, t->right);
            if (t->left) t->left->rev ^= true;
            if (t->right) t->right->rev ^= true;
            t->rev = false;
            // if (t->left) reverse(t->left);
            // if (t->right) reverse(t->right);
            // t->rev = false;
        }
    }

    static node_ptr join(node_ptr l, node_ptr r) {
        if (!l) return r;
        if (!r) return l;
        l = splay(std::move(l), size(l) - 1);
        l->right = std::move(r);
        recalc(l);
        return l;
    }

    static std::pair<node_ptr, node_ptr> split(node_ptr t, int k) {
        assert(0 <= k && k <= size(t));
        if (k == 0) return {nullptr, std::move(t)};
        if (k == size(t)) return {std::move(t), nullptr};
        t = splay(std::move(t), k - 1);
        auto r = std::move(t->right);
        t->right = nullptr;
        recalc(t);
        return {std::move(t), std::move(r)};
    }

    static node_ptr rotate_left(node_ptr t) {
        node_ptr s = std::move(t->right);
        t->right = std::move(s->left);
        s->left = std::move(t);
        recalc(s->left);
        recalc(s);
        return s;
    }

    static node_ptr rotate_right(node_ptr t) {
        node_ptr s = std::move(t->left);
        t->left = std::move(s->right);
        s->right = std::move(t);
        recalc(s->right);
        recalc(s);
        return s;
    }

    static node_ptr splay(node_ptr t, int k) {
        assert(0 <= k && k <= size(t));
        push(t);
        int lsize = size(t->left);
        if (k == lsize) return t;
        if (k < lsize) {
            push(t->left);
            int llsize = size(t->left->left);
            if (k < llsize) {
                t->left->left = splay(std::move(t->left->left), k);
                t = rotate_right(std::move(t));
            } else if (llsize < k) {
                t->left->right = splay(std::move(t->left->right), k - llsize - 1);
                t->left = rotate_left(std::move(t->left));
            }
            return rotate_right(std::move(t));
        } else {
            push(t->right);
            k -= lsize + 1;
            int rlsize = size(t->right->left);
            if (k < rlsize) {
                t->right->left = splay(std::move(t->right->left), k);
                t->right = rotate_right(std::move(t->right));
            } else if (rlsize < k) {
                t->right->right = splay(std::move(t->right->right), k - rlsize - 1);
                t = rotate_left(std::move(t));
            }
            return rotate_left(std::move(t));
        }
    }
};