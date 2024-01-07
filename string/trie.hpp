#pragma once
#include <map>
#include <memory>
#include <string>
#include <vector>

class Trie {
   public:
    Trie() : root(std::make_shared<Node>()) {}

    void insert(const std::string& s, int id) { insert(root, s, id, 0); }

    void compress() { compress(root); }

   protected:
    struct Node;
    using node_ptr = std::shared_ptr<Node>;

    struct Node {
        std::map<char, node_ptr> ch;
        std::vector<int> accept;
        int sz = 0;
        node_ptr par;
        std::string str;
    };

    const node_ptr root;

    void insert(const node_ptr& t, const std::string& s, int id, int k) {
        ++t->sz;
        if (k == (int)s.size()) {
            t->accept.push_back(id);
            return;
        }
        int c = s[k];
        if (!t->ch.contains(c)) {
            t->ch[c] = std::make_shared<Node>();
            t->ch[c]->par = t;
            t->ch[c]->str = c;
        }
        insert(t->ch[c], s, id, k + 1);
    }

    void compress(node_ptr t) {
        while (t->accept.empty() && t->ch.size() == 1) {
            auto u = t->ch.begin()->second;
            t->ch = u->ch;
            t->accept = u->accept;
            t->str += u->str;
            for (auto [c, w] : t->ch) w->par = t;
            compress(t);
        }
        for (auto [c, u] : t->ch) {
            compress(u);
        }
    }
};