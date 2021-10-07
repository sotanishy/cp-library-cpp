#pragma once
#include <memory>
#include <string>
#include <vector>

template <int Size, int Offset>
class Trie {
public:
    Trie() : root(std::make_shared<Node>()) {}

    void insert(const std::string& s, int id) { insert(root, s, id, 0); }

protected:
    struct Node;
    using node_ptr = std::shared_ptr<Node>;

    struct Node {
        std::vector<node_ptr> ch;
        std::vector<int> accept;
        int sz = 0;

        Node() : ch(Size) {}
    };

    const node_ptr root;

    void insert(const node_ptr& t, const std::string& s, int id, int k) {
        ++t->sz;
        if (k == (int) s.size()) {
            t->accept.push_back(id);
            return;
        }
        int c = s[k] - Offset;
        if (!t->ch[c]) t->ch[c] = std::make_shared<Node>();
        insert(t->ch[c], s, id, k + 1);
    }
};