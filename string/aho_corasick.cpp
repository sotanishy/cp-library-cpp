#pragma once
#include <algorithm>
#include <iterator>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include "trie.cpp"

template <int Size, int Offset>
class AhoCorasick : public Trie<Size + 1, Offset> {
    using node_ptr = typename Trie<Size + 1, Offset>::node_ptr;
    using Trie<Size + 1, Offset>::root;

    static const int FAIL = Size;

public:
    void build() {
        std::queue<node_ptr> que;
        for (int i = 0; i <= Size; ++i) {
            if (root->ch[i]) {
                root->ch[i]->ch[FAIL] = root;
                que.push(root->ch[i]);
            } else {
                root->ch[i] = root;
            }
        }
        while (!que.empty()) {
            auto t = que.front();
            que.pop();
            for (int i = 0; i < Size; ++i) {
                if (!t->ch[i]) continue;
                auto fail = t->ch[FAIL];
                while (!fail->ch[i]) fail = fail->ch[FAIL];
                t->ch[i]->ch[FAIL] = fail->ch[i];

                auto& u = t->ch[i]->accept;
                auto& v = fail->ch[i]->accept;
                std::vector<int> accept;
                std::set_union(u.begin(), u.end(), v.begin(), v.end(), std::back_inserter(accept));
                u = accept;

                que.push(t->ch[i]);
            }
        }
    }

    std::map<int, int> match(const std::string& str) const {
        std::map<int, int> ret;
        auto t = root;
        for (auto c : str) {
            while (!t->ch[c - Offset]) t = t->ch[FAIL];
            t = t->ch[c - Offset];
            for (auto& i : t->accept) ++ret[i];
        }
        return ret;
    }
};