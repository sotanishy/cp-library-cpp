#pragma once
#include <cassert>
#include <memory>
#include <random>
#include <utility>

template <typename M, typename O, typename M::T (*act)(typename M::T, typename O::T)>
class LazyTreap {
    using T = typename M::T;
    using E = typename O::T;

public:
    LazyTreap() = default;

    static LazyTreap join(LazyTreap l, LazyTreap r) {
        return LazyTreap(join(std::move(l.root), std::move(r.root)));
    }

    std::pair<LazyTreap, LazyTreap> split(int k) {
        auto p = split(std::move(root), k);
        return {LazyTreap(std::move(p.first)), LazyTreap(std::move(p.second))};
    }

    void update(int l, int r, const E& x) {
        assert(0 <= l && l < r && r <= size());
        node_ptr a, b, c;
        std::tie(a, b) = split(std::move(root), l);
        std::tie(b, c) = split(std::move(b), r - l);
        b->lazy = O::op(b->lazy, x);
        root = join(join(std::move(a), std::move(b)), std::move(c));
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
        root = join(std::move(p.first), std::move(q.second));
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
        E lazy;
        unsigned int pri;
        int sz;
        bool rev;

        Node() : Node(M::id) {}
        Node(const T& x) : left(nullptr), right(nullptr), val(x), sum(val), lazy(O::id), pri(rand()), sz(1), rev(false) {}
    };

    node_ptr root;

    explicit LazyTreap(node_ptr root) : root(std::move(root)) {}

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
        if (t->lazy != O::id) {
            t->val = act(t->val, t->lazy);
            if (t->left) {
                t->left->lazy = O::op(t->left->lazy, t->lazy);
                t->left->sum = act(t->left->sum, t->lazy);
            }
            if (t->right) {
                t->right->lazy = O::op(t->right->lazy, t->lazy);
                t->right->sum = act(t->right->sum, t->lazy);
            }
            t->lazy = O::id;
        }
        recalc(t);
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
        push(t);
        if (k == 0) return {nullptr, std::move(t)};
        if (k == size(t)) return {std::move(t), nullptr};
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
};
