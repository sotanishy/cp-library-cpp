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
    BinaryTrie() : node(1) {}

    int size() const {
        return node[0].count;
    }

    bool empty() const {
        return size() == 0;
    }

    int count(T x) const {
        int t = 0;
        for (int i = B - 1; i >= 0; --i) {
            bool b = x >> i & 1;
            if (node[t].ch[b] == -1) return 0;
            t = node[t].ch[b];
        }
        return node[t].count;
    }

    void insert(T x) {
        int t = 0;
        for (int i = B - 1; i >= 0; --i) {
            bool b = x >> i & 1;
            if (node[t].ch[b] == -1) {
                node[t].ch[b] = node.size();
                node.emplace_back();
            }
            ++node[t].count;
            t = node[t].ch[b];
        }
        ++node[t].count;
    }

    void erase(T x) {
        if (!count(x)) return;
        int t = 0;
        for (int i = B - 1; i >= 0; --i) {
            --node[t].count;
            t = node[t].ch[x >> i & 1];
        }
        --node[t].count;
    }

    T min_element(T x = 0) const {
        assert(size());
        int t = 0;
        T ret = 0;
        for (int i = B - 1; i >= 0; --i) {
            bool b = x >> i & 1;
            int c = node[t].ch[b];
            if (c != -1 && node[c].count > 0) {
                t = c;
            } else {
                t = node[t].ch[1 - b];
                ret |= T(1) << i;
            }
        }
        return ret;
    }

    T max_element(T x = 0) const {
        assert(size());
        int t = 0;
        T ret = 0;
        for (int i = B - 1; i >= 0; --i) {
            bool b = x >> i & 1;
            int c = node[t].ch[1 - b];
            if (c != -1 && node[c].count > 0) {
                t = c;
                ret |= T(1) << i;
            } else {
                t = node[t].ch[b];
            }
        }
        return ret;
    }

private:
    struct Node {
        std::vector<int> ch;
        int count;
        Node() : ch(2, -1), count(0) {}
    };

    std::vector<Node> node;
};
