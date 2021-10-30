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
  bundledCode: "#line 2 \"data-structure/persistent_stack.cpp\"\n#include <memory>\n\
    \ntemplate <typename T>\nclass PersistentStack {\npublic:\n    PersistentStack()\
    \ = default;\n\n    T top() const {\n        return last->val;\n    }\n\n    bool\
    \ empty() const {\n        return last == nullptr;\n    }\n\n    PersistentStack\
    \ push(const T& val) const {\n        return PersistentStack(std::make_shared<Node>(val,\
    \ last));\n    }\n\n    PersistentStack pop() const {\n        return PersistentStack(last->prev);\n\
    \    }\n\nprivate:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        T val;\n        node_ptr prev;\n        Node(T val,\
    \ node_ptr prev) : val(val), prev(prev) {}\n    };\n\n    node_ptr last;\n\n \
    \   explicit PersistentStack(node_ptr last) : last(last) {}\n};\n"
  code: "#pragma once\n#include <memory>\n\ntemplate <typename T>\nclass PersistentStack\
    \ {\npublic:\n    PersistentStack() = default;\n\n    T top() const {\n      \
    \  return last->val;\n    }\n\n    bool empty() const {\n        return last ==\
    \ nullptr;\n    }\n\n    PersistentStack push(const T& val) const {\n        return\
    \ PersistentStack(std::make_shared<Node>(val, last));\n    }\n\n    PersistentStack\
    \ pop() const {\n        return PersistentStack(last->prev);\n    }\n\nprivate:\n\
    \    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\n    struct Node\
    \ {\n        T val;\n        node_ptr prev;\n        Node(T val, node_ptr prev)\
    \ : val(val), prev(prev) {}\n    };\n\n    node_ptr last;\n\n    explicit PersistentStack(node_ptr\
    \ last) : last(last) {}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/persistent_stack.cpp
  requiredBy: []
  timestamp: '2021-10-30 12:57:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/persistent_stack.cpp
layout: document
title: Persistent Stack
---

## Description

永続スタックは，過去のバージョンを保持するスタックである．

空間計算量: $O(m)$, $m$ は変更の数

## Operations

- `bool empty()`
    - 時間計算量: $O(1)$
- `T top()`
    - 先頭の要素を返す
    - 時間計算量: $O(1)$
- `PersistentStack push(T val)`
    - `val` を先頭に追加する
    - 時間計算量: $O(1)$
- `PersistentStack pop()`
    - 先頭の要素を削除する
    - 時間計算量: $O(1)$

## Reference

- [ゼロから作る永続データ構造](https://qiita.com/wotsushi/items/72e7f8cdd674741ffd61)