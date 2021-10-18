---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/aho_corasick.cpp
    title: Aho-Corasick Algorithm
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/trie.cpp\"\n#include <memory>\n#include <string>\n\
    #include <vector>\n\ntemplate <int Size, int Offset>\nclass Trie {\npublic:\n\
    \    Trie() : root(std::make_shared<Node>()) {}\n\n    void insert(const std::string&\
    \ s, int id) { insert(root, s, id, 0); }\n\nprotected:\n    struct Node;\n   \
    \ using node_ptr = std::shared_ptr<Node>;\n\n    struct Node {\n        std::vector<node_ptr>\
    \ ch;\n        std::vector<int> accept;\n        int sz = 0;\n\n        Node()\
    \ : ch(Size) {}\n    };\n\n    const node_ptr root;\n\n    void insert(const node_ptr&\
    \ t, const std::string& s, int id, int k) {\n        ++t->sz;\n        if (k ==\
    \ (int) s.size()) {\n            t->accept.push_back(id);\n            return;\n\
    \        }\n        int c = s[k] - Offset;\n        if (!t->ch[c]) t->ch[c] =\
    \ std::make_shared<Node>();\n        insert(t->ch[c], s, id, k + 1);\n    }\n\
    };\n"
  code: "#pragma once\n#include <memory>\n#include <string>\n#include <vector>\n\n\
    template <int Size, int Offset>\nclass Trie {\npublic:\n    Trie() : root(std::make_shared<Node>())\
    \ {}\n\n    void insert(const std::string& s, int id) { insert(root, s, id, 0);\
    \ }\n\nprotected:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        std::vector<node_ptr> ch;\n        std::vector<int>\
    \ accept;\n        int sz = 0;\n\n        Node() : ch(Size) {}\n    };\n\n   \
    \ const node_ptr root;\n\n    void insert(const node_ptr& t, const std::string&\
    \ s, int id, int k) {\n        ++t->sz;\n        if (k == (int) s.size()) {\n\
    \            t->accept.push_back(id);\n            return;\n        }\n      \
    \  int c = s[k] - Offset;\n        if (!t->ch[c]) t->ch[c] = std::make_shared<Node>();\n\
    \        insert(t->ch[c], s, id, k + 1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.cpp
  requiredBy:
  - string/aho_corasick.cpp
  timestamp: '2021-10-07 18:08:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.cpp
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