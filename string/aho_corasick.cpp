#pragma once
#include <map>
#include <memory>
#include <queue>
#include <string>
#include <vector>

class AhoCorasick {
public:
    explicit AhoCorasick() : root(std::make_shared<Node>()) {}

    void insert(const std::string& s) {
        auto t = root;
        for (char c : s) {
            if (!t->ch.count(c)) t->ch[c] = std::make_shared<Node>();
            t = t->ch[c];
        }
        ++t->cnt;
    }

    void clear() { root = std::make_shared<Node>(); }

    void build() {
        std::queue<node_ptr> que;
        que.push(root);
        while (!que.empty()) {
            auto t = que.front();
            que.pop();

            for (auto [c, v] : t->ch) {
                auto u = t->link;
                while (u && !u->ch.count(c)) u = u->link;
                v->link = u ? u->ch[c] : root;

                v->cnt += v->link->cnt;
                que.push(v);
            }
        }
    }

    long long count(const std::string& str) const {
        long long ret = 0;
        auto t = root;
        for (auto c : str) {
            while (t && !t->ch.count(c)) t = t->link;
            t = t ? t->ch[c] : root;
            ret += t->cnt;
        }
        return ret;
    }

private:
    struct Node;
    using node_ptr = std::shared_ptr<Node>;

    struct Node {
        std::map<char, node_ptr> ch;
        node_ptr link;
        int cnt = 0;

        Node() = default;
    };

    node_ptr root;
};


class DynamicAhoCorasick {
    std::vector<std::vector<std::string>> dict;
    std::vector<AhoCorasick> ac;

public:
    void insert(const std::string& s) {
        int k = 0;
        while (k < (int) dict.size() && !dict[k].empty()) ++k;
        if (k == (int) dict.size()) {
            dict.emplace_back();
            ac.emplace_back();
        }

        dict[k].push_back(s);
        ac[k].insert(s);

        for (int i = 0; i < k; ++i) {
            for (auto& t : dict[i]) {
                ac[k].insert(t);
            }
            dict[k].insert(dict[k].end(), dict[i].begin(), dict[i].end());
            ac[i].clear();
            dict[i].clear();
        }

        ac[k].build();
    }

    long long count(const std::string& str) const {
        long long ret = 0;
        for (int i = 0; i < (int) ac.size(); ++i) ret += ac[i].count(str);
        return ret;
    }
};