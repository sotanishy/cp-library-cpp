---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/trie.hpp\"\n#include <map>\n#include <memory>\n#include\
    \ <string>\n#include <vector>\n\nclass Trie {\n   public:\n    Trie() : root(std::make_shared<Node>())\
    \ {}\n\n    void insert(const std::string& s, int id) { insert(root, s, id, 0);\
    \ }\n\n    void compress() { compress(root); }\n\n   protected:\n    struct Node;\n\
    \    using node_ptr = std::shared_ptr<Node>;\n\n    struct Node {\n        std::map<char,\
    \ node_ptr> ch;\n        std::vector<int> accept;\n        int sz = 0;\n     \
    \   node_ptr par;\n        std::string str;\n    };\n\n    const node_ptr root;\n\
    \n    void insert(const node_ptr& t, const std::string& s, int id, int k) {\n\
    \        ++t->sz;\n        if (k == (int)s.size()) {\n            t->accept.push_back(id);\n\
    \            return;\n        }\n        int c = s[k];\n        if (!t->ch.contains(c))\
    \ {\n            t->ch[c] = std::make_shared<Node>();\n            t->ch[c]->par\
    \ = t;\n            t->ch[c]->str = c;\n        }\n        insert(t->ch[c], s,\
    \ id, k + 1);\n    }\n\n    void compress(node_ptr t) {\n        while (t->accept.empty()\
    \ && t->ch.size() == 1) {\n            auto u = t->ch.begin()->second;\n     \
    \       t->ch = u->ch;\n            t->accept = u->accept;\n            t->str\
    \ += u->str;\n            for (auto [c, w] : t->ch) w->par = t;\n            compress(t);\n\
    \        }\n        for (auto [c, u] : t->ch) {\n            compress(u);\n  \
    \      }\n    }\n};\n"
  code: "#pragma once\n#include <map>\n#include <memory>\n#include <string>\n#include\
    \ <vector>\n\nclass Trie {\n   public:\n    Trie() : root(std::make_shared<Node>())\
    \ {}\n\n    void insert(const std::string& s, int id) { insert(root, s, id, 0);\
    \ }\n\n    void compress() { compress(root); }\n\n   protected:\n    struct Node;\n\
    \    using node_ptr = std::shared_ptr<Node>;\n\n    struct Node {\n        std::map<char,\
    \ node_ptr> ch;\n        std::vector<int> accept;\n        int sz = 0;\n     \
    \   node_ptr par;\n        std::string str;\n    };\n\n    const node_ptr root;\n\
    \n    void insert(const node_ptr& t, const std::string& s, int id, int k) {\n\
    \        ++t->sz;\n        if (k == (int)s.size()) {\n            t->accept.push_back(id);\n\
    \            return;\n        }\n        int c = s[k];\n        if (!t->ch.contains(c))\
    \ {\n            t->ch[c] = std::make_shared<Node>();\n            t->ch[c]->par\
    \ = t;\n            t->ch[c]->str = c;\n        }\n        insert(t->ch[c], s,\
    \ id, k + 1);\n    }\n\n    void compress(node_ptr t) {\n        while (t->accept.empty()\
    \ && t->ch.size() == 1) {\n            auto u = t->ch.begin()->second;\n     \
    \       t->ch = u->ch;\n            t->accept = u->accept;\n            t->str\
    \ += u->str;\n            for (auto [c, w] : t->ch) w->par = t;\n            compress(t);\n\
    \        }\n        for (auto [c, u] : t->ch) {\n            compress(u);\n  \
    \      }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy: []
  timestamp: '2024-01-07 23:25:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.hpp
layout: document
title: Trie
---

## Description

トライ木は，文字列の集合を管理するデータ構造である．

トライ木は実現したい処理に応じて，関数や持たせるデータを自分で書くことが多いので，これはあくまでテンプレ．

## Operations

- `void insert(string s, int id)`
    - 文字列 $s$ を挿入する
    - 時間計算量: $O(\vert s\vert)$
- `void compress()`
    - トライ木を圧縮して Patricia trie を構築する．これにより，木の木の深さが $O(\sqrt{\sum \vert s \vert})$ になる．
    - 時間計算量: $O(\sum \vert s\vert)$