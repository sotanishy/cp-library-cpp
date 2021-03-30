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
  bundledCode: "#line 2 \"string/trie.cpp\"\n#include <memory>\n#include <string>\n\
    #include <vector>\n\nclass Trie {\npublic:\n    Trie() : root(std::make_unique<Node>())\
    \ {}\n\n    void insert(const std::string& s, int id) { insert(root, s, id, 0);\
    \ }\n\nprivate:\n    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\
    \n    struct Node {\n        std::vector<node_ptr> ch;\n        std::vector<int>\
    \ accept;\n        int sz = 0;\n\n        Node() : ch(26) {}\n    };\n\n    const\
    \ node_ptr root;\n\n    void insert(const node_ptr& t, const std::string& s, int\
    \ id, int k) {\n        ++t->sz;\n        if (k == s.size()) {\n            t->accept.push_back(id);\n\
    \            return;\n        }\n        int c = s[k] - 'a';\n        if (!t->ch[c])\
    \ t->ch[c] = std::make_unique<Node>();\n        insert(t->ch[c], s, id, k + 1);\n\
    \    }\n};\n"
  code: "#pragma once\n#include <memory>\n#include <string>\n#include <vector>\n\n\
    class Trie {\npublic:\n    Trie() : root(std::make_unique<Node>()) {}\n\n    void\
    \ insert(const std::string& s, int id) { insert(root, s, id, 0); }\n\nprivate:\n\
    \    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\n    struct Node\
    \ {\n        std::vector<node_ptr> ch;\n        std::vector<int> accept;\n   \
    \     int sz = 0;\n\n        Node() : ch(26) {}\n    };\n\n    const node_ptr\
    \ root;\n\n    void insert(const node_ptr& t, const std::string& s, int id, int\
    \ k) {\n        ++t->sz;\n        if (k == s.size()) {\n            t->accept.push_back(id);\n\
    \            return;\n        }\n        int c = s[k] - 'a';\n        if (!t->ch[c])\
    \ t->ch[c] = std::make_unique<Node>();\n        insert(t->ch[c], s, id, k + 1);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.cpp
  requiredBy: []
  timestamp: '2021-03-30 13:20:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.cpp
layout: document
title: Trie
---

## Description

トライ木は，文字列の集合を管理するデータ構造である．

トライ木は実現したい処理に応じて，関数や持たせるデータを自分で書くことが多いので，これはあくまでテンプレ．

## TODO

- パトリシア木