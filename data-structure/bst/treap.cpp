#pragma once
#include <cassert>
#include <memory>
#include <random>
#include <utility>

/*
 * @brief Treap
 * @docs docs/data-structure/bst/treap.md
 */
template <typename M>
class Treap {
    using T = typename M::T;

public:
    Treap() = default;

    static Treap join(Treap l, Treap r) {
        return Treap(join(std::move(l.root), std::move(r.root)));
    }

    std::pair<Treap, Treap> split(int k) {
        auto p = split(std::move(root), k);
        return {Treap(std::move(p.first)), Treap(std::move(p.second))};
    }

    void update(int k, const T& x) const {
        update(root, k, x);
    }

    T fold(int l, int r) {
        assert(0 <= l && l < r && r <= size());
        node_ptr a, b, c;
        std::tie(a, b) = split(std::move(root), l);
        std::tie(b, c) = split(std::move(b), r - l);
        auto ret = b->sum;
        root = join(join(std::move(a), std::move(b)), std::move(c));
        return ret;
    }

    void reverse(int l, int r) {
        assert(0 <= l && l < r && r <= size());
        node_ptr a, b, c;
        std::tie(a, b) = split(std::move(root), l);
        std::tie(b, c) = split(std::move(b), r - l);
        b->rev ^= true;
        root = join(join(std::move(a), std::move(b)), std::move(c));
    }

    void insert(int k, const T& x) {
        auto s = split(std::move(root), k);
        root = join(join(std::move(s.first), std::make_unique<Node>(x)), std::move(s.second));
    }

    void erase(int k) {
        auto p = split(std::move(root), k);
        auto q = split(std::move(p.second), 1);
        return join(std::move(p.first), std::move(q.second));
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

private:
    struct Node;
    using node_ptr = std::unique_ptr<Node>;

    static unsigned int rand() {
        static std::random_device rd;
        static std::mt19937 rng(rd());
        return rng();
    }

    struct Node {
        node_ptr left, right;
        T val, sum;
        unsigned int pri;
        int sz;
        bool rev;

        Node() : Node(M::id) {}
        Node(const T& x) : left(nullptr), right(nullptr), val(x), sum(val), pri(rand()), sz(1), rev(false) {}
    };

    node_ptr root;

    explicit Treap(node_ptr root) : root(std::move(root)) {}

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
        }
    }

    static node_ptr join(node_ptr l, node_ptr r) {
        if (!l) return r;
        if (!r) return l;
        push(l);
        push(r);
        if (l->pri > r->pri) {
            l->right = join(std::move(l->right), std::move(r));
            recalc(l);
            return l;
        } else {
            r->left = join(std::move(l), std::move(r->left));
            recalc(r);
            return r;
        }
    }

    static std::pair<node_ptr, node_ptr> split(node_ptr t, int k) {
        assert(0 <= k && k <= size(t));
        if (k == 0) return {nullptr, std::move(t)};
        if (k == size(t)) return {std::move(t), nullptr};
        push(t);
        if (k <= size(t->left)) {
            auto s = split(std::move(t->left), k);
            t->left = std::move(s.second);
            recalc(t);
            return {std::move(s.first), std::move(t)};
        } else {
            auto s = split(std::move(t->right), k - size(t->left) - 1);
            t->right = std::move(s.first);
            recalc(t);
            return {std::move(t), std::move(s.second)};
        }
    }

    static void update(const node_ptr& t, int k, const T& x) {
        push(t);
        int lsize = size(t->left);
        if (k < lsize) {
            update(t->left, k, x);
        } else if (lsize < k) {
            update(t->right, k - lsize - 1, x);
        } else {
            t->val = x;
        }
        recalc(t);
    }
};