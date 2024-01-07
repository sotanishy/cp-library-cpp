---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/pattern_search_2d.hpp
    title: 2D Pattern Search (Baker-Bird Algorithm)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_C.test.cpp
    title: test/aoj/ALDS1_14_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/aho_corasick.hpp\"\n#include <algorithm>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <string>\n#include <vector>\n\
    \nclass AhoCorasick {\n   public:\n    struct Node {\n        std::map<char, int>\
    \ ch;\n        std::vector<int> accept;\n        int link = -1;\n        int cnt\
    \ = 0;\n\n        Node() = default;\n    };\n\n    std::vector<Node> states;\n\
    \    std::map<int, int> accept_state;\n\n    explicit AhoCorasick() : states(1)\
    \ {}\n\n    void insert(const std::string& s, int id = -1) {\n        int i =\
    \ 0;\n        for (char c : s) {\n            if (!states[i].ch.count(c)) {\n\
    \                states[i].ch[c] = states.size();\n                states.emplace_back();\n\
    \            }\n            i = states[i].ch[c];\n        }\n        ++states[i].cnt;\n\
    \        states[i].accept.push_back(id);\n        accept_state[id] = i;\n    }\n\
    \n    void clear() {\n        states.clear();\n        states.emplace_back();\n\
    \    }\n\n    int get_next(int i, char c) const {\n        while (i != -1 && !states[i].ch.count(c))\
    \ i = states[i].link;\n        return i != -1 ? states[i].ch.at(c) : 0;\n    }\n\
    \n    void build() {\n        std::queue<int> que;\n        que.push(0);\n   \
    \     while (!que.empty()) {\n            int i = que.front();\n            que.pop();\n\
    \n            for (auto [c, j] : states[i].ch) {\n                states[j].link\
    \ = get_next(states[i].link, c);\n                states[j].cnt += states[states[j].link].cnt;\n\
    \n                auto& a = states[j].accept;\n                auto& b = states[states[j].link].accept;\n\
    \                std::vector<int> accept;\n                std::ranges::set_union(a,\
    \ b, std::back_inserter(accept));\n                a = accept;\n\n           \
    \     que.push(j);\n            }\n        }\n    }\n\n    long long count(const\
    \ std::string& str) const {\n        long long ret = 0;\n        int i = 0;\n\
    \        for (auto c : str) {\n            i = get_next(i, c);\n            ret\
    \ += states[i].cnt;\n        }\n        return ret;\n    }\n\n    // list of (id,\
    \ index)\n    std::vector<std::pair<int, int>> match(const std::string& str) const\
    \ {\n        std::vector<std::pair<int, int>> ret;\n        int i = 0;\n     \
    \   for (int k = 0; k < (int)str.size(); ++k) {\n            char c = str[k];\n\
    \            i = get_next(i, c);\n            for (auto id : states[i].accept)\
    \ {\n                ret.emplace_back(id, k);\n            }\n        }\n    \
    \    return ret;\n    }\n};\n\nclass DynamicAhoCorasick {\n    std::vector<std::vector<std::string>>\
    \ dict;\n    std::vector<AhoCorasick> ac;\n\n   public:\n    void insert(const\
    \ std::string& s) {\n        int k = 0;\n        while (k < (int)dict.size() &&\
    \ !dict[k].empty()) ++k;\n        if (k == (int)dict.size()) {\n            dict.emplace_back();\n\
    \            ac.emplace_back();\n        }\n\n        dict[k].push_back(s);\n\
    \        ac[k].insert(s);\n\n        for (int i = 0; i < k; ++i) {\n         \
    \   for (auto& t : dict[i]) {\n                ac[k].insert(t);\n            }\n\
    \            dict[k].insert(dict[k].end(), dict[i].begin(), dict[i].end());\n\
    \            ac[i].clear();\n            dict[i].clear();\n        }\n\n     \
    \   ac[k].build();\n    }\n\n    long long count(const std::string& str) const\
    \ {\n        return std::accumulate(\n            ac.begin(), ac.end(), 0LL,\n\
    \            [&](auto res, auto& a) { return res + a.count(str); });\n    }\n\
    };\n"
  code: "#pragma once\n#include <algorithm>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <string>\n#include <vector>\n\nclass AhoCorasick {\n\
    \   public:\n    struct Node {\n        std::map<char, int> ch;\n        std::vector<int>\
    \ accept;\n        int link = -1;\n        int cnt = 0;\n\n        Node() = default;\n\
    \    };\n\n    std::vector<Node> states;\n    std::map<int, int> accept_state;\n\
    \n    explicit AhoCorasick() : states(1) {}\n\n    void insert(const std::string&\
    \ s, int id = -1) {\n        int i = 0;\n        for (char c : s) {\n        \
    \    if (!states[i].ch.count(c)) {\n                states[i].ch[c] = states.size();\n\
    \                states.emplace_back();\n            }\n            i = states[i].ch[c];\n\
    \        }\n        ++states[i].cnt;\n        states[i].accept.push_back(id);\n\
    \        accept_state[id] = i;\n    }\n\n    void clear() {\n        states.clear();\n\
    \        states.emplace_back();\n    }\n\n    int get_next(int i, char c) const\
    \ {\n        while (i != -1 && !states[i].ch.count(c)) i = states[i].link;\n \
    \       return i != -1 ? states[i].ch.at(c) : 0;\n    }\n\n    void build() {\n\
    \        std::queue<int> que;\n        que.push(0);\n        while (!que.empty())\
    \ {\n            int i = que.front();\n            que.pop();\n\n            for\
    \ (auto [c, j] : states[i].ch) {\n                states[j].link = get_next(states[i].link,\
    \ c);\n                states[j].cnt += states[states[j].link].cnt;\n\n      \
    \          auto& a = states[j].accept;\n                auto& b = states[states[j].link].accept;\n\
    \                std::vector<int> accept;\n                std::ranges::set_union(a,\
    \ b, std::back_inserter(accept));\n                a = accept;\n\n           \
    \     que.push(j);\n            }\n        }\n    }\n\n    long long count(const\
    \ std::string& str) const {\n        long long ret = 0;\n        int i = 0;\n\
    \        for (auto c : str) {\n            i = get_next(i, c);\n            ret\
    \ += states[i].cnt;\n        }\n        return ret;\n    }\n\n    // list of (id,\
    \ index)\n    std::vector<std::pair<int, int>> match(const std::string& str) const\
    \ {\n        std::vector<std::pair<int, int>> ret;\n        int i = 0;\n     \
    \   for (int k = 0; k < (int)str.size(); ++k) {\n            char c = str[k];\n\
    \            i = get_next(i, c);\n            for (auto id : states[i].accept)\
    \ {\n                ret.emplace_back(id, k);\n            }\n        }\n    \
    \    return ret;\n    }\n};\n\nclass DynamicAhoCorasick {\n    std::vector<std::vector<std::string>>\
    \ dict;\n    std::vector<AhoCorasick> ac;\n\n   public:\n    void insert(const\
    \ std::string& s) {\n        int k = 0;\n        while (k < (int)dict.size() &&\
    \ !dict[k].empty()) ++k;\n        if (k == (int)dict.size()) {\n            dict.emplace_back();\n\
    \            ac.emplace_back();\n        }\n\n        dict[k].push_back(s);\n\
    \        ac[k].insert(s);\n\n        for (int i = 0; i < k; ++i) {\n         \
    \   for (auto& t : dict[i]) {\n                ac[k].insert(t);\n            }\n\
    \            dict[k].insert(dict[k].end(), dict[i].begin(), dict[i].end());\n\
    \            ac[i].clear();\n            dict[i].clear();\n        }\n\n     \
    \   ac[k].build();\n    }\n\n    long long count(const std::string& str) const\
    \ {\n        return std::accumulate(\n            ac.begin(), ac.end(), 0LL,\n\
    \            [&](auto res, auto& a) { return res + a.count(str); });\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: string/aho_corasick.hpp
  requiredBy:
  - string/pattern_search_2d.hpp
  timestamp: '2024-01-07 22:05:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_C.test.cpp
documentation_of: string/aho_corasick.hpp
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
- `int get_next(int i, char c)`
    - 状態 $i$ にいるときに文字 $c$ が出現したときの遷移先の状態を返す
- `long long count(string s)`
    - 文字列 $s$ に対する各パターンのマッチ回数の合計を返す
    - 時間計算量: $O(\vert s\vert + \sum \vert p\vert)$
- `vector<pair<int, int>> match(string s)`
    - 文字列 $s$ に対する各パターンのマッチ位置を返す
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