#pragma once
#include <memory>
#include <string>
#include <vector>

class Trie {
public:
    Trie() : root(std::make_unique<Node>()) {}

    void insert(const std::string& s, int id) { insert(root, s, id, 0); }

private:
    struct Node;
    using node_ptr = std::unique_ptr<Node>;

    struct Node {
        std::vector<node_ptr> ch;
        std::vector<int> accept;
        int sz = 0;

        Node() : ch(26) {}
    };

    const node_ptr root;

    void insert(const node_ptr& t, const std::string& s, int id, int k) {
        ++t->sz;
        if (k == s.size()) {
            t->accept.push_back(id);
            return;
        }
        int c = s[k] - 'a';
        if (!t->ch[c]) t->ch[c] = std::make_unique<Node>();
        insert(t->ch[c], s, id, k + 1);
    }
};