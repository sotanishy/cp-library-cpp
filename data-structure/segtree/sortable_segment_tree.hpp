#pragma once
#include <memory>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

#include "segment_tree.hpp"

template <typename M>
class SortableSegmentTree {
    using T = M::T;

   public:
    SortableSegmentTree() = default;
    explicit SortableSegmentTree(long long max_key,
                                 const std::vector<std::pair<long long, T>>& kv)
        : n(kv.size()), max_key(max_key), st_all(n), st_sorted(n), rev(n) {
        for (int k = 0; k < n; ++k) {
            auto [key, val] = kv[k];
            st_sorted[k] = std::make_unique<Node>();
            st_sorted[k]->update(key, val, 0, max_key);
            st_all.update(k, val);
            left.insert(k);
        }
        left.insert(n);
    }

    void update(int k, long long key, const T& val) {
        split(k), split(k + 1);
        st_sorted[k] = std::make_unique<Node>();
        st_sorted[k]->update(key, val, 0, max_key);
        st_all.update(k, val);
    }

    T fold(int l, int r) {
        split(l), split(r);
        return st_all.fold(l, r);
    }

    void sort(int l, int r, bool descending = false) {
        if (r - l <= 1) return;
        split(l), split(r);
        auto it = ++left.find(l);
        while (it != left.end() && *it < r) {
            st_sorted[l] =
                join(std::move(st_sorted[l]), std::move(st_sorted[*it]));
            st_all.update(*it, M::id());
            rev[*it] = false;
            it = left.erase(it);
        }
        if (st_sorted[l]) {
            st_all.update(l, !descending ? st_sorted[l]->val_forward
                                         : st_sorted[l]->val_backward);
            rev[l] = descending;
        }
    }

   private:
    struct Node;
    using node_ptr = std::unique_ptr<Node>;

    struct Node {
        int sz;
        T val_forward, val_backward;
        node_ptr left, right;
        Node()
            : sz(0),
              val_forward(M::id()),
              val_backward(M::id()),
              left(nullptr),
              right(nullptr) {}

        void recalc() {
            int sl = left ? left->sz : 0;
            int sr = right ? right->sz : 0;
            sz = sl + sr;
            T vl_forward = left ? left->val_forward : M::id();
            T vr_forward = right ? right->val_forward : M::id();
            val_forward = M::op(vl_forward, vr_forward);
            T vl_backward = left ? left->val_backward : M::id();
            T vr_backward = right ? right->val_backward : M::id();
            val_backward = M::op(vr_backward, vl_backward);
        }

        void update(long long key, const T& x, long long l, long long r) {
            if (r - l == 1) {
                sz = 1;
                val_forward = val_backward = x;
                return;
            }
            long long m = std::midpoint(l, r);
            if (key < m) {
                if (!left) left = std::make_unique<Node>();
                left->update(key, x, l, m);
            } else {
                if (!right) right = std::make_unique<Node>();
                right->update(key, x, m, r);
            }
            recalc();
        }
    };

    static std::pair<node_ptr, node_ptr> split(node_ptr t, int k) {
        if (k == 0) return {nullptr, std::move(t)};
        if (k == t->sz) return {std::move(t), nullptr};
        int szl = t->left ? t->left->sz : 0;
        auto t2 = std::make_unique<Node>();
        if (k < szl) {
            std::tie(t2->left, t->left) = split(std::move(t->left), k);
            std::swap(t, t2);
        } else {
            std::tie(t->right, t2->right) = split(std::move(t->right), k - szl);
        }
        t->recalc(), t2->recalc();
        return {std::move(t), std::move(t2)};
    }

    static node_ptr join(node_ptr t1, node_ptr t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        t1->left = join(std::move(t1->left), std::move(t2->left));
        t1->right = join(std::move(t1->right), std::move(t2->right));
        t1->recalc();
        return t1;
    }

    int n;
    long long max_key;
    std::set<int> left;
    SegmentTree<M> st_all;
    std::vector<node_ptr> st_sorted;
    std::vector<bool> rev;

    void split(int k) {
        int l = *--left.upper_bound(k);
        if (l == k) return;
        if (!rev[l]) {
            std::tie(st_sorted[l], st_sorted[k]) =
                split(std::move(st_sorted[l]), k - l);
        } else {
            std::tie(st_sorted[k], st_sorted[l]) =
                split(std::move(st_sorted[l]), l + st_sorted[l]->sz - k);
            rev[k] = true;
        }
        left.insert(k);
        if (st_sorted[l]) {
            st_all.update(l, !rev[l] ? st_sorted[l]->val_forward
                                     : st_sorted[l]->val_backward);
        }
        if (st_sorted[k]) {
            st_all.update(k, !rev[k] ? st_sorted[k]->val_forward
                                     : st_sorted[k]->val_backward);
        }
    }
};