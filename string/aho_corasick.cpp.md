---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: string/trie.cpp
    title: Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/aho_corasick.cpp\"\n#include <algorithm>\n#include\
    \ <iterator>\n#include <map>\n#include <queue>\n#include <string>\n#include <vector>\n\
    #line 2 \"string/trie.cpp\"\n#include <memory>\n#line 5 \"string/trie.cpp\"\n\n\
    template <int Size, int Offset>\nclass Trie {\npublic:\n    Trie() : root(std::make_shared<Node>())\
    \ {}\n\n    void insert(const std::string& s, int id) { insert(root, s, id, 0);\
    \ }\n\nprotected:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        std::vector<node_ptr> ch;\n        std::vector<int>\
    \ accept;\n        int sz = 0;\n\n        Node() : ch(Size) {}\n    };\n\n   \
    \ const node_ptr root;\n\n    void insert(const node_ptr& t, const std::string&\
    \ s, int id, int k) {\n        ++t->sz;\n        if (k == (int) s.size()) {\n\
    \            t->accept.push_back(id);\n            return;\n        }\n      \
    \  int c = s[k] - Offset;\n        if (!t->ch[c]) t->ch[c] = std::make_shared<Node>();\n\
    \        insert(t->ch[c], s, id, k + 1);\n    }\n};\n#line 9 \"string/aho_corasick.cpp\"\
    \n\ntemplate <int Size, int Offset>\nclass AhoCorasick : public Trie<Size + 1,\
    \ Offset> {\n    using node_ptr = typename Trie<Size + 1, Offset>::node_ptr;\n\
    \    using Trie<Size + 1, Offset>::root;\n\n    static const int FAIL = Size;\n\
    \npublic:\n    void build() {\n        std::queue<node_ptr> que;\n        for\
    \ (int i = 0; i <= Size; ++i) {\n            if (root->ch[i]) {\n            \
    \    root->ch[i]->ch[FAIL] = root;\n                que.push(root->ch[i]);\n \
    \           } else {\n                root->ch[i] = root;\n            }\n   \
    \     }\n        while (!que.empty()) {\n            auto t = que.front();\n \
    \           que.pop();\n            for (int i = 0; i < Size; ++i) {\n       \
    \         if (!t->ch[i]) continue;\n                auto fail = t->ch[FAIL];\n\
    \                while (!fail->ch[i]) fail = fail->ch[FAIL];\n               \
    \ t->ch[i]->ch[FAIL] = fail->ch[i];\n\n                auto& u = t->ch[i]->accept;\n\
    \                auto& v = fail->ch[i]->accept;\n                std::vector<int>\
    \ accept;\n                std::set_union(u.begin(), u.end(), v.begin(), v.end(),\
    \ std::back_inserter(accept));\n                u = accept;\n\n              \
    \  que.push(t->ch[i]);\n            }\n        }\n    }\n\n    std::map<int, int>\
    \ match(const std::string& str) const {\n        std::map<int, int> ret;\n   \
    \     auto t = root;\n        for (auto c : str) {\n            while (!t->ch[c\
    \ - Offset]) t = t->ch[FAIL];\n            t = t->ch[c - Offset];\n          \
    \  for (auto& i : t->accept) ++ret[i];\n        }\n        return ret;\n    }\n\
    };\n"
  code: "#pragma once\n#include <algorithm>\n#include <iterator>\n#include <map>\n\
    #include <queue>\n#include <string>\n#include <vector>\n#include \"trie.cpp\"\n\
    \ntemplate <int Size, int Offset>\nclass AhoCorasick : public Trie<Size + 1, Offset>\
    \ {\n    using node_ptr = typename Trie<Size + 1, Offset>::node_ptr;\n    using\
    \ Trie<Size + 1, Offset>::root;\n\n    static const int FAIL = Size;\n\npublic:\n\
    \    void build() {\n        std::queue<node_ptr> que;\n        for (int i = 0;\
    \ i <= Size; ++i) {\n            if (root->ch[i]) {\n                root->ch[i]->ch[FAIL]\
    \ = root;\n                que.push(root->ch[i]);\n            } else {\n    \
    \            root->ch[i] = root;\n            }\n        }\n        while (!que.empty())\
    \ {\n            auto t = que.front();\n            que.pop();\n            for\
    \ (int i = 0; i < Size; ++i) {\n                if (!t->ch[i]) continue;\n   \
    \             auto fail = t->ch[FAIL];\n                while (!fail->ch[i]) fail\
    \ = fail->ch[FAIL];\n                t->ch[i]->ch[FAIL] = fail->ch[i];\n\n   \
    \             auto& u = t->ch[i]->accept;\n                auto& v = fail->ch[i]->accept;\n\
    \                std::vector<int> accept;\n                std::set_union(u.begin(),\
    \ u.end(), v.begin(), v.end(), std::back_inserter(accept));\n                u\
    \ = accept;\n\n                que.push(t->ch[i]);\n            }\n        }\n\
    \    }\n\n    std::map<int, int> match(const std::string& str) const {\n     \
    \   std::map<int, int> ret;\n        auto t = root;\n        for (auto c : str)\
    \ {\n            while (!t->ch[c - Offset]) t = t->ch[FAIL];\n            t =\
    \ t->ch[c - Offset];\n            for (auto& i : t->accept) ++ret[i];\n      \
    \  }\n        return ret;\n    }\n};"
  dependsOn:
  - string/trie.cpp
  isVerificationFile: false
  path: string/aho_corasick.cpp
  requiredBy: []
  timestamp: '2021-10-07 18:08:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/aho_corasick.cpp
layout: document
title: Aho-Corasick Algorithm
---

## Description

Aho-Corasick 法は，入力文字列に対して複数のパターンを高速にマッチするアルゴリズムである．

パターンからトライ木をもとにしてオートマトンを構築する．

## Operations

- `void insert(string p, int id)`
    - パターン $p$ を挿入する
    - 時間計算量: $O(\vert p\vert)$
- `void build()`
    - オートマトンを構築する
    - 時間計算量: $O(\sum \vert p\vert)$
- `map<int, int> match(string s)`
    - 文字列 $s$ に対する各パターンのマッチ回数を返す
    - 時間計算量: $O(\vert s\vert + \sum \vert p\vert)$
