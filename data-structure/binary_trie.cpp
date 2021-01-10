#pragma once
#include <cassert>
#include <vector>

/*
 * @brief Binary Trie
 * @docs docs/data-structure/binary_trie.md
 */
template <typename T, int B = 32>
class BinaryTrie {
public:
    BinaryTrie() : root(std::make_unique<Node>()) {}

    int size() const {
        return root->count;
    }

    bool empty() const {
        return size() == 0;
    }

    int count(T x) const {
        return count(root, x, B - 1);
    }

    int count_less(T x, T xor_val = 0) const {
        return count_less(root, x, xor_val, B - 1);
    }

    void insert(T x) {
        insert(root, x, B - 1);
    }

    void erase(T x) {
        erase(root, x, B - 1);
    }

    T min_element(T xor_val = 0) const {
        assert(!empty());
        return min_element(root, xor_val, B - 1);
    }

    T max_element(T xor_val = 0) const {
        assert(!empty());
        return max_element(root, xor_val, B - 1);
    }

private:
    struct Node;
    using node_ptr = std::unique_ptr<Node>;

    struct Node {
        node_ptr ch[2];
        int count = 0;
    };

    const node_ptr root;

    int count(const node_ptr& t, T x, int k) const {
        if (k == -1) return t->count;
        bool b = x >> k & 1;
        return t->ch[b] ? count(t->ch[b], x, k - 1) : 0;
    }

    int count_less(const node_ptr& t, T x, T xor_val, int k) const {
        if (k == -1) return 0;
        bool b = x >> k & 1;
        bool f = xor_val >> k & 1;
        int ret = 0;
        if (f ^ b) {
            if (t->ch[f]) ret += t->ch[f]->count;
            if (t->ch[1 - f]) ret += count_less(t->ch[1 - f], x, xor_val, k - 1);
        } else {
            if (t->ch[f]) ret += count_less(t->ch[f], x, xor_val, k - 1);
        }
        return ret;
    }

    void insert(const node_ptr& t, T x, int k) {
        if (k == -1) {
            ++t->count;
            return;
        }
        bool b = x >> k & 1;
        if (!t->ch[b]) t->ch[b] = std::make_unique<Node>();
        ++t->count;
        insert(t->ch[b], x, k - 1);
    }

    void erase(const node_ptr& t, T x, int k) {
        if (k == -1) {
            --t->count;
            return;
        }
        --t->count;
        erase(t->ch[x >> k & 1]);
    }

    T min_element(const node_ptr& t, T xor_val, int k) const {
        if (k == -1) return 0;
        bool b = xor_val >> k & 1;
        T ret = 0;
        if (t->ch[b] && t->ch[b].count > 0) {
            ret += min_element(t->ch[b], xor_val, k - 1);
        } else {
            ret += T(1) << k;
            ret += min_element(t->ch[1 - b], xor_val, k - 1);
        }
        return ret;
    }

    T max_element(const node_ptr& t, T xor_val, int k) const {
        if (k == -1) return 0;
        bool b = xor_val >> k & 1;
        T ret = 0;
        if (t->ch[1 - b] && t->ch[1 - b].count > 0) {
            ret += T(1) << k;
            ret += max_element(t->ch[1 - b], xor_val, k - 1);
        } else {
            ret += max_element(t->ch[b], xor_val, k - 1);
        }
        return ret;
    }
};