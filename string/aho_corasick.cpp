#pragma once
#include <algorithm>
#include <map>
#include <memory>
#include <queue>
#include <string>
#include <vector>

class AhoCorasick {
public:
    explicit AhoCorasick() : root(std::make_shared<Node>()) {}

    void insert(const std::string& s, int id = -1) {
        auto t = root;
        for (char c : s) {
            if (!t->ch.count(c)) t->ch[c] = std::make_shared<Node>();
            t = t->ch[c];
        }
        ++t->cnt;
        t->accept.push_back(id);
    }

    void clear() { root = std::make_shared<Node>(); }

    void build() {
        std::queue<node_ptr> que;
        que.push(root);
        while (!que.empty()) {
            auto t = que.front();
            que.pop();

            for (auto [c, v] : t->ch) {
                v->link = get_next(t->link, c);

                v->cnt += v->link->cnt;

                auto& a = v->accept;
                auto& b = v->link->accept;
                std::vector<int> accept;
                std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(accept));
                a = accept;

                que.push(v);
            }
        }
    }

    long long count(const std::string& str) const {
        long long ret = 0;
        auto t = root;
        for (auto c : str) {
            t = get_next(t, c);
            ret += t->cnt;
        }
        return ret;
    }

    // list of (id, index)
    std::vector<std::pair<int, int>> match(const std::string& str) const {
        std::vector<std::pair<int, int>> ret;
        auto t = root;
        for (int i = 0; i < (int) str.size(); ++i) {
            char c = str[i];
            t = get_next(t, c);
            for (auto j : t->accept) {
                ret.emplace_back(j, i);
            }
        }
        return ret;
    }

private:
    struct Node;
    using node_ptr = std::shared_ptr<Node>;

    struct Node {
        std::map<char, node_ptr> ch;
        std::vector<int> accept;
        node_ptr link;
        int cnt = 0;

        Node() = default;
    };

    node_ptr root;

    node_ptr get_next(node_ptr t, char c) const {
        while (t && !t->ch.count(c)) t = t->link;
        return t ? t->ch[c] : root;
    }
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