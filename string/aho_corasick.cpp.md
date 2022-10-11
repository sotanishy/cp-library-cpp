---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/aho_corasick.cpp\"\n#include <algorithm>\n#include\
    \ <map>\n#include <memory>\n#include <queue>\n#include <string>\n#include <vector>\n\
    \nclass AhoCorasick {\npublic:\n    explicit AhoCorasick() : root(std::make_shared<Node>())\
    \ {}\n\n    void insert(const std::string& s, int id = -1) {\n        auto t =\
    \ root;\n        for (char c : s) {\n            if (!t->ch.count(c)) t->ch[c]\
    \ = std::make_shared<Node>();\n            t = t->ch[c];\n        }\n        ++t->cnt;\n\
    \        t->accept.push_back(id);\n    }\n\n    void clear() { root = std::make_shared<Node>();\
    \ }\n\n    void build() {\n        std::queue<node_ptr> que;\n        que.push(root);\n\
    \        while (!que.empty()) {\n            auto t = que.front();\n         \
    \   que.pop();\n\n            for (auto [c, v] : t->ch) {\n                v->link\
    \ = get_next(t->link, c);\n\n                v->cnt += v->link->cnt;\n\n     \
    \           auto& a = v->accept;\n                auto& b = v->link->accept;\n\
    \                std::vector<int> accept;\n                std::set_union(a.begin(),\
    \ a.end(), b.begin(), b.end(), std::back_inserter(accept));\n                a\
    \ = accept;\n\n                que.push(v);\n            }\n        }\n    }\n\
    \n    long long count(const std::string& str) const {\n        long long ret =\
    \ 0;\n        auto t = root;\n        for (auto c : str) {\n            t = get_next(t,\
    \ c);\n            ret += t->cnt;\n        }\n        return ret;\n    }\n\n \
    \   // list of (id, index)\n    std::vector<std::pair<int, int>> match(const std::string&\
    \ str) const {\n        std::vector<std::pair<int, int>> ret;\n        auto t\
    \ = root;\n        for (int i = 0; i < (int) str.size(); ++i) {\n            char\
    \ c = str[i];\n            t = get_next(t, c);\n            for (auto j : t->accept)\
    \ {\n                ret.emplace_back(j, i);\n            }\n        }\n     \
    \   return ret;\n    }\n\nprivate:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        std::map<char, node_ptr> ch;\n        std::vector<int>\
    \ accept;\n        node_ptr link;\n        int cnt = 0;\n\n        Node() = default;\n\
    \    };\n\n    node_ptr root;\n\n    node_ptr get_next(node_ptr t, char c) const\
    \ {\n        while (t && !t->ch.count(c)) t = t->link;\n        return t ? t->ch[c]\
    \ : root;\n    }\n};\n\nclass DynamicAhoCorasick {\n    std::vector<std::vector<std::string>>\
    \ dict;\n    std::vector<AhoCorasick> ac;\n\npublic:\n    void insert(const std::string&\
    \ s) {\n        int k = 0;\n        while (k < (int) dict.size() && !dict[k].empty())\
    \ ++k;\n        if (k == (int) dict.size()) {\n            dict.emplace_back();\n\
    \            ac.emplace_back();\n        }\n\n        dict[k].push_back(s);\n\
    \        ac[k].insert(s);\n\n        for (int i = 0; i < k; ++i) {\n         \
    \   for (auto& t : dict[i]) {\n                ac[k].insert(t);\n            }\n\
    \            dict[k].insert(dict[k].end(), dict[i].begin(), dict[i].end());\n\
    \            ac[i].clear();\n            dict[i].clear();\n        }\n\n     \
    \   ac[k].build();\n    }\n\n    long long count(const std::string& str) const\
    \ {\n        long long ret = 0;\n        for (int i = 0; i < (int) ac.size();\
    \ ++i) ret += ac[i].count(str);\n        return ret;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <map>\n#include <memory>\n#include\
    \ <queue>\n#include <string>\n#include <vector>\n\nclass AhoCorasick {\npublic:\n\
    \    explicit AhoCorasick() : root(std::make_shared<Node>()) {}\n\n    void insert(const\
    \ std::string& s, int id = -1) {\n        auto t = root;\n        for (char c\
    \ : s) {\n            if (!t->ch.count(c)) t->ch[c] = std::make_shared<Node>();\n\
    \            t = t->ch[c];\n        }\n        ++t->cnt;\n        t->accept.push_back(id);\n\
    \    }\n\n    void clear() { root = std::make_shared<Node>(); }\n\n    void build()\
    \ {\n        std::queue<node_ptr> que;\n        que.push(root);\n        while\
    \ (!que.empty()) {\n            auto t = que.front();\n            que.pop();\n\
    \n            for (auto [c, v] : t->ch) {\n                v->link = get_next(t->link,\
    \ c);\n\n                v->cnt += v->link->cnt;\n\n                auto& a =\
    \ v->accept;\n                auto& b = v->link->accept;\n                std::vector<int>\
    \ accept;\n                std::set_union(a.begin(), a.end(), b.begin(), b.end(),\
    \ std::back_inserter(accept));\n                a = accept;\n\n              \
    \  que.push(v);\n            }\n        }\n    }\n\n    long long count(const\
    \ std::string& str) const {\n        long long ret = 0;\n        auto t = root;\n\
    \        for (auto c : str) {\n            t = get_next(t, c);\n            ret\
    \ += t->cnt;\n        }\n        return ret;\n    }\n\n    // list of (id, index)\n\
    \    std::vector<std::pair<int, int>> match(const std::string& str) const {\n\
    \        std::vector<std::pair<int, int>> ret;\n        auto t = root;\n     \
    \   for (int i = 0; i < (int) str.size(); ++i) {\n            char c = str[i];\n\
    \            t = get_next(t, c);\n            for (auto j : t->accept) {\n   \
    \             ret.emplace_back(j, i);\n            }\n        }\n        return\
    \ ret;\n    }\n\nprivate:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        std::map<char, node_ptr> ch;\n        std::vector<int>\
    \ accept;\n        node_ptr link;\n        int cnt = 0;\n\n        Node() = default;\n\
    \    };\n\n    node_ptr root;\n\n    node_ptr get_next(node_ptr t, char c) const\
    \ {\n        while (t && !t->ch.count(c)) t = t->link;\n        return t ? t->ch[c]\
    \ : root;\n    }\n};\n\nclass DynamicAhoCorasick {\n    std::vector<std::vector<std::string>>\
    \ dict;\n    std::vector<AhoCorasick> ac;\n\npublic:\n    void insert(const std::string&\
    \ s) {\n        int k = 0;\n        while (k < (int) dict.size() && !dict[k].empty())\
    \ ++k;\n        if (k == (int) dict.size()) {\n            dict.emplace_back();\n\
    \            ac.emplace_back();\n        }\n\n        dict[k].push_back(s);\n\
    \        ac[k].insert(s);\n\n        for (int i = 0; i < k; ++i) {\n         \
    \   for (auto& t : dict[i]) {\n                ac[k].insert(t);\n            }\n\
    \            dict[k].insert(dict[k].end(), dict[i].begin(), dict[i].end());\n\
    \            ac[i].clear();\n            dict[i].clear();\n        }\n\n     \
    \   ac[k].build();\n    }\n\n    long long count(const std::string& str) const\
    \ {\n        long long ret = 0;\n        for (int i = 0; i < (int) ac.size();\
    \ ++i) ret += ac[i].count(str);\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/aho_corasick.cpp
  requiredBy: []
  timestamp: '2022-10-01 22:18:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/aho_corasick.cpp
layout: document
title: Aho-Corasick Algorithm
---

## Description

Aho-Corasick 法は，入力文字列に対して複数のパターンを高速にマッチするアルゴリズムである．

パターンからトライ木をもとにしてオートマトンを構築する．

## Operations (AhoCorasick)

- `void insert(string p)`
    - パターン $p$ を挿入する
    - 時間計算量: $O(\vert p\vert)$
- `void build()`
    - オートマトンを構築する
    - 時間計算量: $O(\sum \vert p\vert)$
- `long long count(string s)`
    - 文字列 $s$ に対する各パターンのマッチ回数の合計を返す
    - 時間計算量: $O(\vert s\vert + \sum \vert p\vert)$

## Operations (DynamicAhoCorasick)

- `void insert(string p)`
    - パターン $p$ を挿入する
    - 時間計算量: $\mathrm{amortized}\,O(\vert p\vert\log n)$
- `map<int, int> match(string s)`
    - 文字列 $s$ に対する各パターンのマッチ回数を返す
    - 時間計算量: $O((\vert s\vert + \sum \vert p\vert)\log n)$

## Reference

- [静的データ構造で動的に処理する (1) - えびちゃんの日記](https://rsk0315.hatenablog.com/entry/2019/06/19/124528)